#!/bin/bash
#valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes --num-callers=20 --track-fds=yes ./ModelDumpD Ammar.obj Ammar $@ 2>error.txt

valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes --num-callers=20 --track-fds=yes ./Renderer  -from Scenes/test.conf $@ 2>error.txt

exit $?
