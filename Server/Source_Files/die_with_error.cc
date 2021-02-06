#include "../Header_Files/tcp_server.h"

void die_with_error(const string& error_message) {
	perror(("\x1b[31m" + error_message + "\x1b[0m").c_str());
	exit(1);
}