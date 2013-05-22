#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../acquisition/Acquisition.h"
#include "AmmarServer/src/AmmServerNULLlib/AmmServerlib.h"

#define DEFAULT_BINDING_IP "0.0.0.0"
#define DEFAULT_BINDING_PORT 8080 // <--- Change this to 80 if you want to bind to the default http port..!

#define MAX_RGB_FRAME_WIDTH 640
#define MAX_RGB_FRAME_HEIGHT 480

#define MAX_DEPTH_FRAME_WIDTH 640
#define MAX_DEPTH_FRAME_HEIGHT 480

ModuleIdentifier moduleID = TEMPLATE_ACQUISITION_MODULE; //OPENGL_ACQUISITION_MODULE;//OPENNI1_ACQUISITION_MODULE;//

char webserver_root[MAX_FILE_PATH]="public_html/"; // <- change this to the directory that contains your content if you dont want to use the default public_html dir..
char templates_root[MAX_FILE_PATH]="public_html/templates/";

char outputfoldername[512]={0};

struct AmmServer_Instance * default_server=0;
struct AmmServer_RH_Context rgbRAWFrame={0};
struct AmmServer_RH_Context rgbPPMFrame={0};
struct AmmServer_RH_Context depthRAWFrame={0};
struct AmmServer_RH_Context depthPPMFrame={0};

struct AmmServer_RH_Context control={0};

int autoSnapFeed=1;

void * prepare_RGB_RAW_frame_content_callback(char * content)
{
  rgbRAWFrame.content_size = acquisitionCopyColorFrame(moduleID,0,content,rgbRAWFrame.MAX_content_size);
  return 0;
}

void * prepare_RGB_PPM_frame_content_callback(char * content)
{
  rgbPPMFrame.content_size =  acquisitionCopyColorFramePPM(moduleID,0,content,rgbPPMFrame.MAX_content_size);
  return 0;
}

void * prepare_Depth_RAW_frame_content_callback(char * content)
{
  depthRAWFrame.content_size = acquisitionCopyDepthFrame(moduleID,0,content,depthRAWFrame.MAX_content_size);
  return 0;
}

void * prepare_Depth_PPM_frame_content_callback(char * content)
{
  depthPPMFrame.content_size =  acquisitionCopyDepthFramePPM(moduleID,0,content,depthPPMFrame.MAX_content_size);
  return 0;
}

void * prepare_control_content_callback(char * content)
{
   sprintf(content,"<html><body>OK</body></html>");
   control.content_size =  strlen(content);

   char * bufferCommand = (char *) malloc ( 256 * sizeof(char) );
   if (bufferCommand!=0)
          {
            if ( _GET(default_server,&control,"seek",bufferCommand,256) )
                {
                  unsigned int seekFrame = atoi(bufferCommand);
                  acquisitionSeekFrame(moduleID,0,seekFrame);
                  acquisitionSnapFrames(moduleID,0);
                }
            if ( _GET(default_server,&control,"pause",bufferCommand,256) ) { autoSnapFeed = 0; }
            if ( _GET(default_server,&control,"play",bufferCommand,256) )  { autoSnapFeed = 1; }
            if ( _GET(default_server,&control,"snap",bufferCommand,256) )  { acquisitionSnapFrames(moduleID,0); }
          }
  return 0;
}


void init_dynamic_content()
{
  unsigned int RGB_FRAME_SIZE =  MAX_RGB_FRAME_WIDTH * MAX_RGB_FRAME_HEIGHT * 3 ;
  if (! AmmServer_AddResourceHandler(default_server,&rgbRAWFrame,"/rgb.raw",webserver_root,RGB_FRAME_SIZE,0,&prepare_RGB_RAW_frame_content_callback,SAME_PAGE_FOR_ALL_CLIENTS) ) { AmmServer_Warning("Failed adding rgbRAWFrame page\n"); }
  if (! AmmServer_AddResourceHandler(default_server,&rgbPPMFrame,"/rgb.ppm",webserver_root,RGB_FRAME_SIZE+100,0,&prepare_RGB_PPM_frame_content_callback,SAME_PAGE_FOR_ALL_CLIENTS) ) { AmmServer_Warning("Failed adding rgbPPMFrame page\n"); }

  unsigned int DEPTH_FRAME_SIZE =  MAX_DEPTH_FRAME_WIDTH * MAX_DEPTH_FRAME_HEIGHT * 2 ;
  if (! AmmServer_AddResourceHandler(default_server,&depthRAWFrame,"/depth.raw",webserver_root,RGB_FRAME_SIZE,0,&prepare_Depth_RAW_frame_content_callback,SAME_PAGE_FOR_ALL_CLIENTS) ) { AmmServer_Warning("Failed adding depthFrame page\n"); }
  if (! AmmServer_AddResourceHandler(default_server,&depthPPMFrame,"/depth.ppm",webserver_root,RGB_FRAME_SIZE+100,0,&prepare_Depth_PPM_frame_content_callback,SAME_PAGE_FOR_ALL_CLIENTS) ) { AmmServer_Warning("Failed adding depthFrame page\n"); }

  if (! AmmServer_AddResourceHandler(default_server,&control,"/control.html",webserver_root,100,0,&prepare_control_content_callback,SAME_PAGE_FOR_ALL_CLIENTS) ) { AmmServer_Warning("Failed adding control page\n"); }

}

//This function destroys all Resource Handlers and free's all allocated memory..!
void close_dynamic_content()
{
    AmmServer_RemoveResourceHandler(default_server,&rgbRAWFrame,1);
    AmmServer_RemoveResourceHandler(default_server,&rgbPPMFrame,1);
    AmmServer_RemoveResourceHandler(default_server,&depthRAWFrame,1);
    AmmServer_RemoveResourceHandler(default_server,&depthPPMFrame,1);
}

int main(int argc, char *argv[])
{
 AmmServer_RegisterTerminationSignal(&close_dynamic_content);

 unsigned int possibleModules = acquisitionGetModulesCount();
 fprintf(stderr,"Linked to %u modules.. \n",possibleModules);

 if (possibleModules==0) { AmmServer_Error("Acquisition Library is linked to zero modules , can't possibly do anything..\n"); return 1; }
 if (!acquisitionIsModuleLinked(moduleID)) {AmmServer_Error("The module you are trying to use is not linked in this build of the Acquisition library..\n"); return 1; }
 if (!acquisitionStartModule(moduleID,16 /*maxDevices*/ , 0 )) { AmmServer_Error("Could not start module %s ..\n",getModuleStringName(moduleID)); return 1; }

  //We want to initialize all possible devices in this example..
  unsigned int devID=0,maxDevID=acquisitionGetModuleDevices(moduleID);
  if (maxDevID==0) { fprintf(stderr,"No devices found for Module used \n"); return 1; }

  for (devID=0; devID<maxDevID; devID++)
     {
        acquisitionOpenDevice(moduleID,devID,MAX_RGB_FRAME_WIDTH,MAX_RGB_FRAME_HEIGHT,25);
        acquisitionMapDepthToRGB(moduleID,devID);
     }

   default_server = AmmServer_Start ( DEFAULT_BINDING_IP, DEFAULT_BINDING_PORT, 0 /*don't want a configuration file*/ , webserver_root, templates_root );
   if (!default_server) { AmmServer_Error("Could not start server , shutting down everything.."); exit(1); }
   init_dynamic_content();
   while ( (AmmServer_Running(default_server)) )
   { //Do sampling here
     if (!autoSnapFeed)
     {
       for (devID=0; devID<maxDevID; devID++) { acquisitionSnapFrames(moduleID,devID); }
     }
     usleep(35000);
   }

   for (devID=0; devID<maxDevID; devID++) {  acquisitionCloseDevice(moduleID,devID); }

   close_dynamic_content();
   acquisitionStopModule(moduleID);
   AmmServer_Stop(default_server);
  return 0;
}