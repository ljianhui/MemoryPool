APPNAME := memorypooltest

all: $(APPNAME)

CC := g++
CFLAG := -O3

OBJS := main.o memorypoolfixed.o

$(APPNAME): $(OBJS)
	$(CC) -o $(APPNAME) $(OBJS) $(CFLAG)

main.o: main.cpp memorypoolfixed.h
	$(CC) -c main.cpp $(CFLAG)
memorypoolfixed.o: memorypoolfixed.h memorypoolfixed.cpp
	$(CC) -c memorypoolfixed.cpp $(CFLAG)
clean:
	rm -f *.o $(APPNAME)

