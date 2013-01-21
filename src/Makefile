CC = g++
CFLAGS = -c
LFLAGS = -lpthread -lglut

build_all: all

# Uncomment each as they become available
#include Audio/makefile
#include Content/makefile
#include Core/makefile
#include Graphics/makefile
include IO/makefile
include Math/makefile
#include Networking/makefile
#include Physics/makefile
#include Scene/makefile
#include Scripting/makefile
#include Threading/makefile


ALL_OBJECTS = $(IO_OBJECTS) $(MATH_OBJECTS)
# $(AUDIO_OBJECTS) $(CONTENT_OBJECTS) $(CORE_OBJECTS) $(GRAPHICS_OBJECTS) $(IO_OBJECTS) $(MATH_OBJECTS) $(NETWORKING_OBJECTS) $(PHYSICS_OBJECTS) $(SCENE_OBJECTS) $(SCRIPTING_OBJECTS) $(THREADING_OBJECTS)

# audio content core graphics io math networking physics scene scripting
all: IO Math
	$(CC) main.cpp $(LFLAGS) $(ALL_OBJECTS) -o ../bin/tekstorm

clean:
	rm -f ../bin/*.o
