#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -Wall -fexceptions -fPIC
RESINC = 
LIBDIR = 
LIB = ../tools/Calibration/libCalibrationLibrary.a
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = ./libTemplateAcquisition.so

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = ./libTemplateAcquisition.so

OBJ_DEBUG = $(OBJDIR_DEBUG)/TemplateAcquisition.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/TemplateAcquisition.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d . || mkdir -p .
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) -shared $(LIBDIR_DEBUG) $(OBJ_DEBUG)  -o $(OUT_DEBUG) $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/TemplateAcquisition.o: TemplateAcquisition.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c TemplateAcquisition.cpp -o $(OBJDIR_DEBUG)/TemplateAcquisition.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf .
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d . || mkdir -p .
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) -shared $(LIBDIR_RELEASE) $(OBJ_RELEASE)  -o $(OUT_RELEASE) $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/TemplateAcquisition.o: TemplateAcquisition.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c TemplateAcquisition.cpp -o $(OBJDIR_RELEASE)/TemplateAcquisition.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf .
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

