CXX = g++
CPPFLAGS = -Wall
TARGET = main
all: $(TARGET)

$(TARGET):
		$(CXX) $(CPPFLAGS) -Iinclude main.cpp src/*.cpp -o bin/main