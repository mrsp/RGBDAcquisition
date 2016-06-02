#ifndef NAO_GEOMETRY_H_INCLUDED
#define NAO_GEOMETRY_H_INCLUDED


#include "skeleton.h"


#define NORMAL   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */


enum NAO_JOINT_NAMES
{
    NullJoint = 0,
    HeadYaw 	,//Head joint twist (Z) 	-119.5 to 119.5 	-2.0857 to 2.0857
    HeadPitch 	,//Head joint front and back (Y) 	-38.5 to 29.5 	-0.6720 to 0.5149

    LShoulderPitch 	,//Left shoulder joint front and back (Y) 	-119.5 to 119.5 	-2.0857 to 2.0857
    LShoulderRoll 	,//Left shoulder joint right and left (Z) 	-18 to 76 	-0.3142 to 1.3265
    LElbowYaw 	,//Left shoulder joint twist (X) 	-119.5 to 119.5 	-2.0857 to 2.0857
    LElbowRoll 	,//Left elbow joint (Z) 	-88.5 to -2 	-1.5446 to -0.0349
    LWristYaw 	,//Left wrist joint (X) 	-104.5 to 104.5 	-1.8238 to 1.8238
    LHand 	,//Right hand 	Open and Close 	Open and Close


    RShoulderPitch 	,//Right shoulder joint front and back (Y) 	-119.5 to 119.5 	-2.0857 to 2.0857
    RShoulderRoll 	,//Right shoulder joint right and left (Z) 	-76 to 18 	-1.3265 to 0.3142
    RElbowYaw 	,//Right shoulder joint twist (X) 	-119.5 to 119.5 	-2.0857 to 2.0857
    RElbowRoll 	,//Right elbow joint (Z) 	2 to 88.5 	0.0349 to 1.5446
    RWristYaw 	,//Right wrist joint (X) 	-104.5 to 104.5 	-1.8238 to 1.8238
    RHand 	,//Right hand 	Open and Close 	Open and Close


    LHipYawPitch 	,//Left hip joint twist (Y-Z 45°) 	-65.62 to 42.44 	-1.145303 to 0.740810
    RHipYawPitch  	,//Right hip joint twist (Y-Z 45°) 	-65.62 to 42.44 	-1.145303 to 0.740810


    LHipRoll 	,//Left hip joint right and left (X) 	-21.74 to 45.29 	-0.379472 to 0.790477
    LHipPitch 	,//Left hip joint front and back (Y) 	-88.00 to 27.73 	-1.535889 to 0.484090
    LKneePitch 	,//Left knee joint (Y) 	-5.29 to 121.04 	-0.092346 to 2.112528
    LAnklePitch ,//	Left ankle joint front and back (Y) 	-68.15 to 52.86 	-1.189516 to 0.922747
    LAnkleRoll 	,//Left ankle joint right and left (X) 	-22.79 to 44.06 	-0.397880 to 0.769001

    RHipRoll 	 ,//Right hip joint right and left (X) 	-45.29 to 21.74 	-0.790477 to 0.379472
    RHipPitch 	 ,//Right hip joint front and back (Y) 	-88.00 to 27.73 	-1.535889 to 0.484090
    RKneePitch 	 ,//Right knee joint (Y) 	-5.90 to 121.47 	-0.103083 to 2.120198
    RAnklePitch  ,//	Right ankle joint front and back (Y) 	-67.97 to 53.40 	-1.186448 to 0.932056
    RAnkleRoll 	 ,//Right ankle joint right and left (X) 	-44.06 to 22.80 	-0.768992 to 0.397935
   //--------------------------------------------
    NUMBER_OF_NAO_JOINTS
};


static const char * NAOjointNames[] =
{
    "NullJoint" ,
    "HeadYaw" 	,
    "HeadPitch" ,

    "LShoulderPitch",
    "LShoulderRoll" ,
    "LElbowYaw" 	,
    "LElbowRoll" 	,
    "LWristYaw" 	,
    "LHand" 	    ,

    "RShoulderPitch",
    "RShoulderRoll" ,
    "RElbowYaw" 	,
    "RElbowRoll" 	,
    "RWristYaw" 	,
    "RHand" 	    ,


    "LHipYawPitch" 	,
    "RHipYawPitch"  ,


    "LHipRoll" 	 ,
    "LHipPitch"  ,
    "LKneePitch" ,
    "LAnklePitch",
    "LAnkleRoll" ,

    "RHipRoll"	 ,
    "RHipPitch"  ,
    "RKneePitch" ,
    "RAnklePitch",
    "RAnkleRoll" ,
 //=================
 "End of Joint Names"
};





static float NAO_min[] =
{    0,
     -119.5  ,
     -38.5   ,
     -119.5  ,
     -18     ,
     -119.5  ,
     -88.5   ,
     -104.5  ,
     -1      , // Left Hand
     -119.5  ,
     -76     ,
     -119.5  ,
     2       ,
     -104.5  ,
     -1 	 , // Right hand

     -65.62 ,
     -65.62 ,

     -21.74 ,
     -88.00 ,
     -5.29 ,
     -68.15  ,
     -22.79  ,

     -45.29  ,
     -88.00  ,
     -5.90  ,
     -67.97  ,
     -44.06
};






static float NAO_max[] =
{   0,
    119.5 ,
    29.5  ,

    119.5 ,
    76    ,
    119.5 ,
    -2    ,
    104.5 ,
    1.0	,//Right hand 	Open and Close 	Open and Close


    119.5 	,
    18 	    ,
    119.5 	,
    88.5 	,
    104.5 	,
    1.0 	,//Right hand 	Open and Close 	Open and Close


    42.44 	,
    42.44 	,


    45.29 	,
    27.73 	,
    121.04 	,
    52.86 	,
    44.06 	,

    21.74 	,
    27.73 	,
    121.47 	,
    53.40 	,
    22.80
    };




struct naoJoint
{
  float value;
};



struct naoCommand
{
   unsigned long timestampInit;

   //CMD_TWIST
   float velocityX;
   float velocityY;
   float orientationTheta;

   //JOINTS
   float jointMotor[NUMBER_OF_NAO_JOINTS];
   //float joints2DPos[NUMBER_OF_NAO_JOINTS*2];
   //float joints3DPos[NUMBER_OF_NAO_JOINTS*3];

   //CONFIGURATION PARAMETER
   float Kp_Pitch, Ki_Pitch, Kd_Pitch;
   float Kp_Roll, Ki_Roll, Kd_Roll;

   //Last the timestamp
   unsigned long timestampEnd;
};






int setNAOMotorsFromHumanSkeleton(struct naoCommand *  nao , struct skeletonHuman *sk )
{
  updateSkeletonAnglesNAO(sk);

  nao->jointMotor[HeadYaw] =   sk->relativeJointAngle[HUMAN_SKELETON_HEAD].y;
  nao->jointMotor[HeadPitch] = sk->relativeJointAngle[HUMAN_SKELETON_HEAD].x;

  nao->jointMotor[LShoulderPitch]  =   sk->relativeJointAngle[HUMAN_SKELETON_LEFT_SHOULDER].x;
  nao->jointMotor[LShoulderRoll]   =   sk->relativeJointAngle[HUMAN_SKELETON_LEFT_SHOULDER].z;
  nao->jointMotor[LElbowYaw] 	= 0.0; // Left shoulder joint twist (X) 	-119.5 to 119.5 	-2.0857 to 2.0857
  nao->jointMotor[LElbowRoll] 	=  sk->relativeJointAngle[HUMAN_SKELETON_LEFT_ELBOW].z;//Left elbow joint (Z) 	-88.5 to -2 	-1.5446 to -0.0349
  nao->jointMotor[LWristYaw] 	= 0.0; //Left wrist joint (X) 	-104.5 to 104.5 	-1.8238 to 1.8238
  nao->jointMotor[LHand] 	= 1.0; //Right hand 	Open and Close 	Open and Close


  nao->jointMotor[RShoulderPitch] 	 =   sk->relativeJointAngle[HUMAN_SKELETON_RIGHT_SHOULDER].x;
  nao->jointMotor[RShoulderRoll]     =   sk->relativeJointAngle[HUMAN_SKELETON_RIGHT_SHOULDER].z;
  nao->jointMotor[RElbowYaw] 	= 0.0; //Right shoulder joint twist (X) 	-119.5 to 119.5 	-2.0857 to 2.0857
  nao->jointMotor[RElbowRoll] 	= sk->relativeJointAngle[HUMAN_SKELETON_RIGHT_ELBOW].z;//Right elbow joint (Z) 	2 to 88.5 	0.0349 to 1.5446
  nao->jointMotor[RWristYaw] 	= 0.0; //Right wrist joint (X) 	-104.5 to 104.5 	-1.8238 to 1.8238
  nao->jointMotor[RHand] 	= 1.0; //Right hand 	Open and Close 	Open and Close


  nao->jointMotor[LHipYawPitch] = sk->relativeJointAngle[HUMAN_SKELETON_LEFT_HIP].z;
  nao->jointMotor[RHipYawPitch] = sk->relativeJointAngle[HUMAN_SKELETON_RIGHT_HIP].z;


  nao->jointMotor[LHipRoll] 	= 0.0; //Left hip joint right and left (X) 	-21.74 to 45.29 	-0.379472 to 0.790477
  nao->jointMotor[LHipPitch] 	= sk->relativeJointAngle[HUMAN_SKELETON_LEFT_HIP].x;
  nao->jointMotor[LKneePitch] 	= sk->relativeJointAngle[HUMAN_SKELETON_LEFT_KNEE].x;
  nao->jointMotor[LAnklePitch]  = 0.0; // Left ankle joint front and back (Y) 	-68.15 to 52.86 	-1.189516 to 0.922747
  nao->jointMotor[LAnkleRoll] 	= 0.0; //Left ankle joint right and left (X) 	-22.79 to 44.06 	-0.397880 to 0.769001

  nao->jointMotor[RHipRoll] 	 = 0.0; //Right hip joint right and left (X) 	-45.29 to 21.74 	-0.790477 to 0.379472
  nao->jointMotor[RHipPitch] 	 = sk->relativeJointAngle[HUMAN_SKELETON_RIGHT_HIP].x;
  nao->jointMotor[RKneePitch] 	 = sk->relativeJointAngle[HUMAN_SKELETON_RIGHT_KNEE].x;//Right knee joint (Y) 	-5.90 to 121.47 	-0.103083 to 2.120198
  nao->jointMotor[RAnklePitch]   = 0.0;//	Right ankle joint front and back (Y) 	-67.97 to 53.40 	-1.186448 to 0.932056
  nao->jointMotor[RAnkleRoll] 	 = 0.0;//Right ankle joint right and left (X) 	-44.06 to 22.80 	-0.768992 to 0.397935


  unsigned int i=0,addline=0;
  for (i=0; i<NUMBER_OF_NAO_JOINTS; i++)
  {
    addline=0;
    if (NAO_max[i]<nao->jointMotor[i]) { nao->jointMotor[i]=NAO_max[i]; fprintf(stderr,RED " joint %u @ max " NORMAL , i );          addline=1;}
    if (NAO_min[i]>nao->jointMotor[i]) { nao->jointMotor[i]=NAO_min[i]; fprintf(stderr,RED " joint %u @ min " NORMAL , i );          addline=1;}
    if (nao->jointMotor[i]!=nao->jointMotor[i]) { nao->jointMotor[i]=NAO_min[i]; fprintf(stderr,RED " joint %u @ NaN " NORMAL , i ); addline=1;}
  }

  if (addline)
  {
    fprintf(stderr,"\n");
  }

  return 1;
}











static int printoutNAOCommand(const char * filename ,struct naoCommand *  nao)
{
  unsigned int i=0;

  FILE * fp = fopen(filename,"w");
  if (fp!=0)
  {

  fprintf(fp,"NAO COMMAND \n");
  fprintf(fp,"----------------------- \n");

  for (i=0; i<NUMBER_OF_NAO_JOINTS; i++)
  {
    fprintf(fp,"Motor #%u - %s = %0.2f \n",i , NAOjointNames[i] , nao->jointMotor[i]);
  }
  fprintf(fp,"----------------------- \n");
  fclose(fp);
  }
 return 0;
}


















#endif // NAO_GEOMETRY_H_INCLUDED