#ifndef DERICHERECURSIVEGAUSSIAN_H_INCLUDED
#define DERICHERECURSIVEGAUSSIAN_H_INCLUDED


int dericheRecursiveGaussianGrayF(
                                     float * source,  unsigned int sourceWidth , unsigned int sourceHeight , unsigned int channels,
                                     float * target,  unsigned int targetWidth , unsigned int targetHeight ,
                                     float sigma , unsigned int order
                                   );


int dericheRecursiveGaussianGray(
                                  unsigned char * source,  unsigned int sourceWidth , unsigned int sourceHeight , unsigned int channels,
                                  unsigned char * target,  unsigned int targetWidth , unsigned int targetHeight ,
                                  float sigma , unsigned int order
                                );


#endif // DERICHERECURSIVEGAUSSIAN_H_INCLUDED
