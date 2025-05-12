CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp point_set_list.cpp point_set.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=program

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@