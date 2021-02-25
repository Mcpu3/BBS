PROGRAM := server
OBJS := accept_tcp_connection.o create_json.o create_tcp_server_sock.o delete_message.o die_with_error.o get_messages.o parse_json.o post_message.o receive_from.o tcp_server_thread.o
CC := g++
CFLAGS := -O3 -Wall
RM := rm

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -o $@ $^

accept_tcp_connection.o: Source_Files/accept_tcp_connection.cc Header_Files/tcp_server.h Header_Files/picojson.h
	$(CC) $(CFLAGS) -c -o $@ $<

create_json.o: Source_Files/create_json.cc Header_Files/tcp_server.h Header_Files/picojson.h
	$(CC) $(CFLAGS) -c -o $@ $<

create_tcp_server_sock.o: Source_Files/create_tcp_server_sock.cc Header_Files/tcp_server.h Header_Files/picojson.h
	$(CC) $(CFLAGS) -c -o $@ $<

delete_message.o: Source_Files/delete_message.cc Header_Files/tcp_server.h Header_Files/picojson.h
	$(CC) $(CFLAGS) -c -o $@ $<

die_with_error.o: Source_Files/die_with_error.cc Header_Files/tcp_server.h Header_Files/picojson.h
	$(CC) $(CFLAGS) -c -o $@ $<

get_messages.o: Source_Files/get_messages.cc Header_Files/tcp_server.h Header_Files/picojson.h
	$(CC) $(CFLAGS) -c -o $@ $<

parse_json.o: Source_Files/parse_json.cc Header_Files/tcp_server.h Header_Files/picojson.h
	$(CC) $(CFLAGS) -c -o $@ $<

post_message.o: Source_Files/post_message.cc Header_Files/tcp_server.h Header_Files/picojson.h
	$(CC) $(CFLAGS) -c -o $@ $<

receive_from.o: Source_Files/receive_from.cc Header_Files/tcp_server.h Header_Files/picojson.h
	$(CC) $(CFLAGS) -c -o $@ $<

tcp_server_thread.o: Source_Files/tcp_server_thread.cc Header_Files/tcp_server.h Header_Files/picojson.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) -f $(PROGRAM) $(OBJS) messages.json