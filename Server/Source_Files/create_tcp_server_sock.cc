#include "../Header_Files/tcp_server.h"

int create_tcp_server_sock(const unsigned short& server_port) {
	int sock;
	sockaddr_in server_address;

	if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		throw runtime_error("socket() failed");

	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(server_port);
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sock, (sockaddr*)&server_address, sizeof(server_address)) != 0)
		throw runtime_error("bind() failed");

	if (listen(sock, numeric_limits<int>::max()) != 0)
		throw runtime_error("listen() failed");

	return sock;
}