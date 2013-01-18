CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall -lpthread -lglut

build_all: all

#include Audio/makefile
#include Content/makefile
include Core/makefile
#include Graphics/makefile
#include IO/makefile
#include Math/makefile
#include Networking/makefile
#include Physics/makefile
#include Scene/makefile
#include Scripting/makefile
#include Threading/makefile

ALL_OBJECTS = $(AUDIO_OBJECTS) $(CONTENT_OBJECTS) $(CORE_OBJECTS) $(GRAPHICS_OBJECTS) $(IO_OBJECTS) $(MATH_OBJECTS) $(NETWORKING_OBJECTS) $(PHYSICS_OBJECTS) $(SCENE_OBJECTS) $(SCRIPTING_OBJECTS) $(THREADING_OBJECTS)

all: audio content core graphics io math networking physics scene scripting
	$(CC) main.cpp $(LFLAGS) $(ALL_OBJECTS) -o ../bin/tekstorm

clean:
	rm -f ../bin/*.o
