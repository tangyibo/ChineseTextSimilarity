#set your project name
PRJ_NAME =textsimhash
#set your project type : choose one below
PRJ_TYPE = g++ 
#PRJ_TYPE = g++ -shared
#PRJ_TYPE = ar -r 

#set Debug or release
#Compile_Flag = release
Compile_Flag = debug

#set your output path
Output:= bin

#set your source folder
SRC:= src

#add the lib you used here

#LIBS := -lLib1 -lLib2 -lLib3
LIBS :=

#LIBPATH := -Lpath1 -Lpath2 -Lpath3
LIBPATH :=-L/usr/local/lib

# INCLUDEPATH := -I/usr/lib/XXX/include
INCLUDEPATH := -I./include

###################################
#DON"T MODIFY THE BELOWS

#combine output folder
FinalOutput := $(Output)/$(Compile_Flag)/

#list all dirs
SUBDIRS := $(shell find $(SRC) -type d)

#flags in makefile
DEBUG_FLAG = -O0 -g -Wall -c -fmessage-length=0 
#DEBUG_FLAG = -O0 -g -Wall -c -fmessage-length=0 -DDO_ORACLE_DB
RELEASE_FLAG = -O3 -Wall -c -fmessage-length=0

RM := rm -rf

#set compile flag
ifeq ($(Compile_Flag),debug)
CFLAGS := $(DEBUG_FLAG)
else
CFLAGS := $(RELEASE_FLAG)
endif

#prepare files
CPP_SRCS:=$(shell find $(SRC) -name *.cpp)

OBJS:=$(CPP_SRCS:%.cpp=$(FinalOutput)%.o)

#all target
all: dir $(FinalOutput)$(PRJ_NAME)

dir:
	mkdir -p $(FinalOutput);
	for val in $(SUBDIRS);do \
	  mkdir -p $(FinalOutput)$${val}; \
	done;

#tool invocations
$(FinalOutput)$(PRJ_NAME):$(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking:GCC C++ Linker'
	$(PRJ_TYPE) $(LIBPATH) -o"$@" $^ $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

$(FinalOutput)%o:./%cpp
	@echo 'Building file: $<'
	@echo 'Invoking:GCC C++ Compiler'
	g++ $(CFLAGS) $(INCLUDEPATH) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

#other targets
clean:
	-$(RM) $(Output)/*
	-@echo ' '
	
.PHONY:all clean
.SECONDARY:

