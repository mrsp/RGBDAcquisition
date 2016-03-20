#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../OGLRendererSandbox.h"


int main(int argc, char **argv)
{
   if (argc<3)
   {
     fprintf(stderr,"usage : ModelDump path/To/FileA.obj path/To/FileB.c \n");
     return 0;
   }
    return dumpModelFile(argv[1],argv[2]);
}