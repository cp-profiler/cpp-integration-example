OBJS= message.pb.o connector.o example.o

CC = clang++
DEBUG = -g

CFLAGS = -std=c++0x -W -Wall -c $(DEBUG) -I/usr/local/include
LFLAGS = -lzmq `pkg-config --cflags --libs protobuf`

example: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o example
example.o: example.cpp
	$(CC) $(CFLAGS) example.cpp -o example.o
message.pb.o: cpp-integration/message.pb.cpp cpp-integration/message.pb.hh 
	$(CC) $(CFLAGS) cpp-integration/message.pb.cpp -o message.pb.o
connector.o: cpp-integration/connector.cpp cpp-integration/connector.hh
	$(CC) $(CFLAGS) cpp-integration/connector.cpp -o connector.o