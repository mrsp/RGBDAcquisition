/** @file quaternions.h
 *  @brief This is a small math library that deals with quaternions , doubles are used for maximum precision
 *
 *  @author Ammar Qammaz (AmmarkoV)
 */


#ifndef QUATERNIONS_H_INCLUDED
#define QUATERNIONS_H_INCLUDED


#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief This enumerator defines the order of quaternions qWqXqYqZ means W X Y Z , and qXqYqZqW means X Y Z W
 */
enum quatOrder
{
  qWqXqYqZ=0,
  qXqYqZqW
};


enum quatOrderXYZW
{
  pQX=0,
  pQY,
  pQZ,
  pQW
};



/**
 * @brief This function converts euler angles to quaternions
 * @ingroup quaternions
 * @param Quaternions , The output quaternions in the order declared by enum quatOrder
 * @param Euler angles , The input euler angles X,Y,Z
 * @param The convention used for quaternions ( see enum quatOrder )
 * @retval Nothing , no return value
 */
void euler2Quaternions(double * quaternions,double * euler,int quaternionConvention);


/**
 * @brief This function converts quaternions to euler angles
 * @ingroup quaternions
 * @param Euler angles , The output euler angles X,Y,Z
 * @param Quaternions , The input quaternions in the order declared by enum quatOrder
 * @param The convention used for quaternions ( see enum quatOrder )
 */
void quaternions2Euler(double * euler,double * quaternions,int quaternionConvention);


/**
 * @brief Perform Slerp function ( mix , smooth ) 2 quaternions
 * @ingroup quaternions
 * @param Output Quaternion
 * @param Input Quaternion A
 * @param Input Quaternion B
 * @param Factor , typically should be 0.5 for half and half
 */
void quaternionSlerp(double * qOut, double * q0,double * q1,double t);

/**
 * @brief Normalize Quaternion
 * @ingroup quaternions
 * @param
 * @param Input/Output , qX
 * @param Input/Output , qY
 * @param Input/Output , qZ
 * @param Input/Output , qW
 * @retval 1=Success/0=Failure
 */
int normalizeQuaternions(double *qX,double *qY,double *qZ,double *qW);

/**
 * @brief Convert Quaternion to a 3x3 Matrix
 * @ingroup quaternions
 * @param
 * @param Output 3x3 double matrix
 * @param Input quaternion
 * @param Input quaternion convention used
 */
void quaternion2Matrix3x3(double * matrix3x3,double * quaternions,int quaternionConvention);

/**
 * @brief Convert Quaternion to a 4x4 Matrix
 * @ingroup quaternions
 * @param
 * @param Output 4x4 double matrix
 * @param Input quaternion
 * @param Input quaternion convention used
 */
void quaternion2Matrix4x4(double * matrix4x4,double * quaternions,int quaternionConvention);



void matrix4x42Quaternion(double * quaternions,int quaternionConvention,double * matrix4x4);
void matrix3x32Quaternion(double * quaternions,int quaternionConvention,double * m3);

/**
 * @brief Calculate the Inner Product of Two Quaternions
 * @ingroup quaternions
 --------------------------
 * @param Quaternion A qX
 * @param Quaternion A qY
 * @param Quaternion A qZ
 * @param Quaternion A qW
 --------------------------
 * @param Quaternion B qX
 * @param Quaternion B qY
 * @param Quaternion B qZ
 * @param Quaternion B qW
 * @retval Inner Product
 */
double innerProductQuaternions(double qAX,double qAY,double qAZ,double qAW ,
                               double qBX,double qBY,double qBZ,double qBW);



/**
 * @brief Calculate the Angle Between Two Quaternions
 * @ingroup quaternions
 --------------------------
 * @param Quaternion A qX
 * @param Quaternion A qY
 * @param Quaternion A qZ
 * @param Quaternion A qW
 --------------------------
 * @param Quaternion B qX
 * @param Quaternion B qY
 * @param Quaternion B qZ
 * @param Quaternion B qW
 * @retval Angle Between the Two
 */
double anglesBetweenQuaternions(double qAX,double qAY,double qAZ,double qAW ,
                                double qBX,double qBY,double qBZ,double qBW);



void quaternionRotate(double * quaternion , double rotX , double rotY, double rotZ , double angleDegrees , int quaternionConvention);


void quaternionFromTwoVectors(double * quaternionOutput , double * vA , double * vB);

#ifdef __cplusplus
}
#endif


#endif // QUATERNIONS_H_INCLUDED
