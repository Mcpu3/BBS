#include "../Header_Files/tcp_server.h"

string receive_from(const int& client_sock, const char& delimiter) {
	string receive_string;
	char buffer;

	while (true) {
		if (recv(client_sock, &buffer, 1ul, 0) <= static_cast<ssize_t>(0))
			throw runtime_error("recv() failed");

		if (buffer == delimiter)
			break;

		receive_string += buffer;
	}

	return receive_string;
}