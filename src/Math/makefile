MATH_SOURCES = Math/Vector2.cpp Math/Vector3.cpp Math/Vector4.cpp Math/Color3.cpp Math/Color4.cpp
MATH_OBJECTS = bin/Vector2.o bin/Vector3.o bin/Vector4.o bin/Color3.o bin/Color4.o
MATH_DEPS = Vector2 Vector3 Vector4 Color3 Color4

# make math
math: $(MATH_DEPS)

Vector2: Math/Vector2.cpp Math/Vector2.h
	$(CC) $(CFLAGS) Math/Vector2.cpp  -o bin/Vector2.o

Vector3: Math/Vector3.cpp Math/Vector3.h
	$(CC) $(CFLAGS) Math/Vector3.cpp -o bin/Vector3.o

Vector4: Math/Vector4.cpp Math/Vector4.h
	$(CC) $(CFLAGS) Math/Vector4.cpp  -o bin/Vector4.o

Color3: Math/Color3.cpp Math/Color3.h
	$(CC) $(CFLAGS) Math/Color3.cpp  -o bin/Color3.o

Color4: Math/Color4.cpp Math/Color4.h
	$(CC) $(CFLAGS) Math/Color4.cpp -o bin/Color4.o
