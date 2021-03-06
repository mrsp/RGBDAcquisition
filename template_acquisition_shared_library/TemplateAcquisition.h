/** @file TemplateAcqusition.h
 *  @brief The plugin module that provides acquisition from Templates ( i.e. Prerecorded datasets )
 *
 *  @author Ammar Qammaz (AmmarkoV)
 *  @bug There is a weird bug with color frames when fscanf eats one more character than what it should , this is resolved using consequent fseek calls but it could be handled better
 */

#ifndef TEMPLATEACQUISITION_H_INCLUDED
#define TEMPLATEACQUISITION_H_INCLUDED

#ifdef __cplusplus
extern "C"
{
#endif

   #include "../acquisition/acquisition_setup.h"

   #if USE_CALIBRATION
    #include "../tools/Calibration/calibration.h"
   #endif

   //Initialization of Template
   int startTemplateModule(unsigned int max_devs,const char * settings);
   //TemplateAcquisition does not conflict with anything so we default to building it
   #define BUILD_TEMPLATE 1

   #if BUILD_TEMPLATE
   int getTemplateCapabilities(int devID,int capToAskFor);

   int enableTemplateStream(int devID,unsigned int streamID);
   int disableTemplateStream(int devID,unsigned int streamID);

   int getTemplateNumberOfDevices(); // This has to be called AFTER startTemplate
   int stopTemplateModule();

   int switchTemplateToColorStream(int devID);
   int mapTemplateDepthToRGB(int devID);
   int mapTemplateRGBToDepth(int devID);
   int getTemplateNumberOfColorStreams(int devID);

   //Basic Per Device Operations
   int listTemplateDevices(int devID,char * output, unsigned int maxOutput);
   int createTemplateDevice(int devID,const char * devName,unsigned int width,unsigned int height,unsigned int framerate);
   int destroyTemplateDevice(int devID);

   int getTotalTemplateFrameNumber(int devID);
   int getCurrentTemplateFrameNumber(int devID);

   int controlTemplateFlow(int devID,float newFlowState);

   int seekRelativeTemplateFrame(int devID,signed int seekFrame);
   int seekTemplateFrame(int devID,unsigned int seekFrame);
   int snapTemplateFrames(int devID);


   #if USE_CALIBRATION
    int getTemplateColorCalibration(int devID,struct calibration * calib);
    int getTemplateDepthCalibration(int devID,struct calibration * calib);

    int setTemplateColorCalibration(int devID,struct calibration * calib);
    int setTemplateDepthCalibration(int devID,struct calibration * calib);
   #endif

   //Color Frame getters
   unsigned long getLastTemplateColorTimestamp(int devID);

   int getTemplateColorWidth(int devID);
   int getTemplateColorHeight(int devID);
   int getTemplateColorDataSize(int devID);
   int getTemplateColorChannels(int devID);
   int getTemplateColorBitsPerPixel(int devID);
   unsigned char * getTemplateColorPixels(int devID);
   double getTemplateColorFocalLength(int devID);
   double getTemplateColorPixelSize(int devID);

   //Depth Frame getters
   unsigned long getLastTemplateDepthTimestamp(int devID);

   int getTemplateDepthWidth(int devID);
   int getTemplateDepthHeight(int devID);
   int getTemplateDepthDataSize(int devID);
   int getTemplateDepthChannels(int devID);
   int getTemplateDepthBitsPerPixel(int devID);

   char * getTemplateDepthPixels(int devID);
   char * getTemplateDepthPixelsFlipped(int devID);

   double getTemplateDepthFocalLength(int devID);
   double getTemplateDepthPixelSize(int devID);
   #endif


#ifdef __cplusplus
}
#endif

#endif // TEMPLATEACQUISITION_H_INCLUDED
