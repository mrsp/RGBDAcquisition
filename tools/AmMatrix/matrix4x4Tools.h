/** @file matrix4x4Tools.h
 *  @brief  A small 4x4 matrix library for simple 4x4 transformations
 *  @author Ammar Qammaz (AmmarkoV)
 */

#ifndef MATRIX4X4TOOLS_H_INCLUDED
#define MATRIX4X4TOOLS_H_INCLUDED


#ifdef __cplusplus
extern "C"
{
#endif

/**
* @brief Allocate a new 4x4 Matrix
* @ingroup AmMatrix
* @retval 0=Failure or a pointer to an allocated 3x3 Matrix
*/
double * alloc4x4Matrix();

/**
* @brief Deallocate an existing 3x3 Matrix
* @ingroup AmMatrix
* @param  Pointer to a Pointer of an allocated matrix
*/
void free4x4Matrix(double ** mat);



/**
* @brief Printout an 4x4 Matrix that consists of floats
* @ingroup AmMatrix
* @param  Label for the printout ( cString )
* @param  Pointer to a Pointer of an allocated float matrix
*/
void print4x4FMatrix(char * str , float * matrix4x4);

/**
* @brief Printout an 4x4 Matrix that consists of doubles
* @ingroup AmMatrix
* @param  Label for the printout ( cString )
* @param  Pointer to a Pointer of an allocated doubles matrix
*/
void print4x4DMatrix(char * str , double * matrix4x4);



/**
* @brief Copy a 4x4 Matrix to another
* @ingroup AmMatrix
* @param  Output Matrix
* @param  Input Matrix
* @param  Pointer to a Pointer of an allocated doubles matrix
*/
void copy4x4Matrix(double * out,double * in);


/**
* @brief Convert a 4x4 Matrix from Float To Double
* @ingroup AmMatrix
* @param  Pointer to a double 4x4 output
* @param  Pointer to a float 4x4 input
*/
void copy4x4FMatrixToD(double * out,float * in);


/**
* @brief Convert a 4x4 Matrix from Double To Float
* @ingroup AmMatrix
* @param  Pointer to a float 4x4 output
* @param  Pointer to a double 4x4 input
*/
void copy4x4DMatrixToF(float * d, double * m );

/**
* @brief Set an allocated 4x4 matrix to Identity ( diagonal 1 , all else 0 )
* @ingroup AmMatrix
* @param  Input/Output Matrix
*/
void create4x4IdentityMatrix(double * m) ;


void create4x4IdentityFMatrix(float * m);

int is4x4DZeroMatrix(double  * m);

int is4x4DIdentityMatrix(double * m);


int is4x4FIdentityMatrix(float  * m);
int is4x4FIdentityMatrixPercisionCompensating(float  * m);


void convert4x4MatrixToRPY(double *m ,double *roll,double *pitch,double *yaw);



/**
* @brief Convert an allocated 4x4 matrix to a homogeneous Translation rotation
* @ingroup AmMatrix
* @param  Output already allocated 4x4 Matrix
* @param  Input angle
* @param  X Axis Parameter
* @param  Y Axis Parameter
* @param  Z Axis Parameter
*/
void create4x4RotationMatrix(double * m,double angle, double x, double y, double z) ;




void create4x4FTranslationMatrix(float * matrix , float x, float y, float z);


/**
* @brief Convert an allocated 4x4 matrix to a homogeneous 3D Translation
* @ingroup AmMatrix
* @param  Output already allocated 4x4 Matrix
* @param  X Translation
* @param  Y Translation
* @param  Z Translation
*/
void create4x4TranslationMatrix(double * matrix,double x, double y, double z);


/**
* @brief Convert an allocated 4x4 matrix to a homogeneous 3D Scaling
* @ingroup AmMatrix
* @param  Output already allocated 4x4 Matrix
* @param  Scaling on the X
* @param  Scaling on the Y
* @param  Scaling on the Z
* @retval 0=Failure,1=Success
*/
void create4x4ScalingMatrix(double * matrix,double scaleX, double scaleY, double scaleZ);



/**
* @brief Convert a quaternion to 4x4 matrix
* @ingroup AmMatrix
* @param  Output already allocated 4x4 Matrix
* @param  Quaternion on the X
* @param  Quaternion on the Y
* @param  Quaternion on the Z
* @param  Quaternion on the W
* @param  Degrees of rotation
*/
void create4x4QuaternionMatrix(double * m , double qX,double qY,double qZ,double qW);



/**
* @brief Convert a quaternion to 4x4 matrix XYZ convention ( weird )
* @ingroup AmMatrix
* @param  Output already allocated 4x4 Matrix
* @param  Rotation X in euler angles (0-360)
* @param  Rotation Y in euler angles (0-360)
* @param  Rotation Z in euler angles (0-360)
* @bug This should probably not be used and maybe altogether removed, but kept for historical reasons :P
*/
void create4x4MatrixFromEulerAnglesXYZ(double * m ,double eulX, double eulY, double eulZ);



/**
* @brief Convert a quaternion to 4x4 matrix ZYX convention ( standard )
* @ingroup AmMatrix
* @param  Output already allocated 4x4 Matrix
* @param  Rotation X in euler angles (0-360)
* @param  Rotation Y in euler angles (0-360)
* @param  Rotation Z in euler angles (0-360)
*/
void create4x4MatrixFromEulerAnglesZYX(double * m ,double eulX, double eulY, double eulZ);


/**
* @brief Convert an allocated 4x4 matrix to a homogeneous 3D Rotation on the X axis
* @ingroup AmMatrix
* @param  Output already allocated 4x4 Matrix
* @param  Degrees of rotation
*/
void create4x4RotationX(double * matrix,double degrees) ;

/**
* @brief Convert an allocated 4x4 matrix to a homogeneous 3D Rotation on the Y axis
* @ingroup AmMatrix
* @param  Output already allocated 4x4 Matrix
* @param  Degrees of rotation
*/
void create4x4RotationY(double * matrix,double degrees) ;

/**
* @brief Convert an allocated 4x4 matrix to a homogeneous 3D Rotation on the Z axis
* @ingroup AmMatrix
* @param  Output already allocated 4x4 Matrix
* @param  Degrees of rotation
*/
void create4x4RotationZ(double * matrix,double degrees);


/**
* @brief Compute the determenant of a 4x4 matrix
* @ingroup AmMatrix
* @param  Input 4x4 Matrix
* @retval Det(mat)
*/
double det4x4Matrix(double * mat) ;

/**
* @brief Invert a 4x4 matrix
* @ingroup AmMatrix
* @param  Input 4x4 Matrix
* @param  Output ( should be already allocated ) 3x3 Matrix
* @retval 0=failure,1=success
*/
int invert4x4MatrixD(double * result,double * mat) ;


/**
* @brief Transpose an allocated 4x4 matrix to Identity ( diagonal 1 , all else 0 )
* @ingroup AmMatrix
* @param  Input/Output Matrix
* @retval 0=Failure,1=Success
*/
int transpose4x4MatrixD(double * mat) ;


/**
* @brief Multiply 2x 4x4 matrices ( A * B )
* @ingroup AmMatrix
* @param  Output 4x4 Matrix ( should be already allocated )
* @param  Input 4x4 Matrix A
* @param  Input 4x4 Matrix B
* @retval 0=failure,1=success
*/
int multiplyTwo4x4Matrices(double * result , double * matrixA , double * matrixB);

int multiplyThree4x4Matrices(double * result , double * matrixA , double * matrixB , double * matrixC);

/**
* @brief Multiply 2x 4x4 Float matrices ( A * B )
* @ingroup AmMatrix
* @param  Output 4x4 Float Matrix ( should be already allocated )
* @param  Input 4x4 Float Matrix A
* @param  Input 4x4 Float Matrix B
* @retval 0=failure,1=success
*/
int multiplyTwo4x4FMatrices(float * result , float * matrixA , float * matrixB);


/**
* @brief Multiply a 4x4 matrix with a Vector (3D Point)  A*V
* @ingroup AmMatrix
* @param  Output Vector ( should be already allocated )
* @param  Input 4x4 Matrix A
* @param  Input Vector 4x1 V
* @retval 0=failure,1=success
*/
int transform3DPointVectorUsing4x4Matrix(double * resultPoint3D, double * transformation4x4, double * point3D);



/**
* @brief Multiply a the 3x3 rotational part of a 4x4 matrix with a Normal Vector (3D Point)  A*V
         Basically just performing a (3x3) x (3x1) operation from a (4x4) x (4x1) input
* @ingroup AmMatrix
* @param  Output Vector ( should be already allocated )
* @param  Input 4x4 Matrix A
* @param  Input Vector 4x1 V where W coordinate should be 0
* @retval 0=failure,1=success
*/
int transform3DNormalVectorUsing3x3PartOf4x4Matrix(double * resultPoint3D, double * transformation4x4, double * point3D);

/**
* @brief Normalize a 4x1 matrix with a Vector (3D Point)
* @ingroup AmMatrix
* @param  Input/Output Vector
* @retval 0=failure,1=success
*/
int normalize3DPointVector(double * vec);



#ifdef __cplusplus
}
#endif


#endif // MATRIX4X4TOOLS_H_INCLUDED
