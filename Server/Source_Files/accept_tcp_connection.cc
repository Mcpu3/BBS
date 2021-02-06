#include "../Header_Files/tcp_server.h"

int accept_tcp_connection(const int& server_sock) {
	int client_sock;
	sockaddr_in client_address;

	const size_t client_address_length = sizeof(client_address);

	if ((client_sock = accept(server_sock, (sockaddr*)&client_address, (socklen_t*)&client_address_length)) < 0)
		throw runtime_error("accept() failed");

	return client_sock;
}