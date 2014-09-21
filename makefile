APPNAME := memorypooltest

all: $(APPNAME)

CC := g++

OBJS := main.o memorypoolfixed.o

$(APPNAME): $(OBJS)
	$(CC) -o $(APPNAME) $(OBJS)

main.o: main.cpp memorypoolfixed.h
	$(CC) -c main.cpp
memorypoolfixed.o: memorypoolfixed.h memorypoolfixed.cpp
	$(CC) -c memorypoolfixed.cpp
clean:
	rm -f *.o $(APPNAME)

