CXX=g++
CXXFLAGS=-Wall
LDFLAGS=-lcrypt 
SOURCES=pass.cpp hashtable.cpp
TARGET=a.out

OBJECTS=$(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean

hashtable.o: hashtable.h
pass.o: hashtable.h
