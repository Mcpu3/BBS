#include "../Header_Files/tcp_server.h"

void get_messages(const int& client_sock) {
	const string data_without_password_json = create_messages_without_password_json(parse_messages_json()) + '\0';

	if (send(client_sock, data_without_password_json.c_str(), data_without_password_json.length(), 0) != static_cast<ssize_t>(data_without_password_json.length()))
		throw runtime_error("send() failed");
}