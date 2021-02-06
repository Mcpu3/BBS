#ifndef TCPCLIENT
#define TCPCLIENT

#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
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

int create_tcp_client_socket(const unsigned short& server_port, const string& server_ip);
string create_data_json(const Data& data);
string parse_status_message_json(const string& status_message_json);
string receive_from(const int& sock, const char& delimiter);
vector<Message> parse_messages_json(const string& messages_json);
void die_with_error(const string& error_message);
void delete_message(const int& sock);
void get_messages(const int& sock);
void post_message(const int& sock);
void quit(const int& sock);

#endif