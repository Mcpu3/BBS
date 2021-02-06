#include "../Header_Files/tcp_client.h"

int create_tcp_client_socket(const unsigned short& server_port, const string& server_ip) {
	int sock;
	sockaddr_in server_address;

	if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		throw runtime_error("socket() failed");

	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(server_port);
	server_address.sin_addr.s_addr = inet_addr(server_ip.c_str());

	if (connect(sock, (sockaddr*)&server_address, sizeof(server_address)) != 0)
		throw runtime_error("connect() failed");

	return sock;
}