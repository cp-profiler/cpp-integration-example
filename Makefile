OBJS_EXAMPLE = message.pb.o connector.o example.o
OBJS_RESTARTS = message.pb.o connector.o restarts.o

CC = clang++
DEBUG = -g

CFLAGS = -std=c++0x -W -Wall -c $(DEBUG) -I/usr/local/include
LFLAGS = -lzmq `pkg-config --cflags --libs protobuf`

all: example restarts

example: $(OBJS_EXAMPLE)
	$(CC) $(LFLAGS) $(OBJS_EXAMPLE) -o example
example.o: example.cpp
	$(CC) $(CFLAGS) example.cpp -o example.o

restarts: $(OBJS_RESTARTS)
	$(CC) $(LFLAGS) $(OBJS_RESTARTS) -o restarts
restarts.o: restarts.cpp
	$(CC) $(CFLAGS) restarts.cpp -o restarts.o

message.pb.o: cpp-integration/message.pb.cpp cpp-integration/message.pb.hh 
	$(CC) $(CFLAGS) cpp-integration/message.pb.cpp -o message.pb.o
connector.o: cpp-integration/connector.cpp cpp-integration/connector.hh
	$(CC) $(CFLAGS) cpp-integration/connector.cpp -o connector.o

clean:
	rm -f *.o example restarts