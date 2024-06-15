CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SOURCES = main.cpp LoadBalancer.cpp Server.cpp Request.cpp

OBJECTS = $(SOURCES:.cpp=.o)

TARGET = my_project

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
