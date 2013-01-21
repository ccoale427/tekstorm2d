IO_SOURCES = IO/FileStream.cpp IO/MemoryStream.cpp
IO_OBJECTS = bin/FileStream.o bin/MemoryStream.o
IO_DEPS = FileStream MemoryStream

# make IO
IO: $(IO_DEPS)

FileStream: IO/FileStream.cpp
	$(CC) $(CFLAGS) IO/FileStream.cpp -o bin/FileStream.o

MemoryStream: IO/MemoryStream.cpp
	$(CC) $(CFLAGS) IO/MemoryStream.cpp -o bin/MemoryStream.o


