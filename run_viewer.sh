#!/bin/bash
  
ln -s viewer/frames grabbed_frames 

cd viewer 
LD_LIBRARY_PATH=.:../3dparty/libfreenect/build/lib ./Viewer $@
cd ..

exit 0
