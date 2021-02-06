#ifndef TCPSERVER
#define TCPSERVER

#include <algorithm>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <vector>
#include "picojson.h"
using namespace std;

struct Message {
	unsigned long long id;
	string user;
	string password;
	string body;

	Message() = default;

	Message(const unsigned long long& new_id, const string& new_user, const string& new_password, const string& new_body) :
		id(new_id),
		user(new_user),
		password(new_password),
		body(new_body)
	{}
};

struct Data {
	string method;
	Message message;

	Data() = default;

	Data(const string& new_method, const Message& new_message) :
		method(new_method),
		message(new_message)
	{}
};

Data parse_data_json(const string& data_json);
int accept_tcp_connection(const int& server_sock);
int create_tcp_server_sock(const unsigned short& server_port);
string create_messages_without_password_json(const vector<Message>& messages);
string create_status_message_json(const string& status_message);
string receive_from(const int& client_sock, const char& delimiter);
vector<Message> parse_messages_json();
void create_messages_json(const vector<Message>& messages);
void delete_message(const int& client_sock, const Data& data);
void die_with_error(const string& error_message);
void get_messages(const int& client_sock);
void post_message(const int& client_sock, const Data& data);
void thread_main(const int& client_sock);

#endif