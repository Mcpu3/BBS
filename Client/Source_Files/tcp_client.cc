#include "../Header_Files/tcp_client.h"

int main() {
	const unsigned short server_port = static_cast<unsigned short>(49152);
	const string server_ip = "127.0.0.1";

	int sock;

	try {
		sock = create_tcp_client_socket(server_port, server_ip);
	}
	catch (const exception& e) {
		die_with_error(e.what());
	}

	while (true) {
		string command;

			do {
				cout << "\x1b[32m" << "1: 読み込み, 2: 書き込み, 3: 削除, 4: 終了" << "\x1b[0m" << '>';
				getline(cin, command);
			} while (!regex_match(command, regex(R"([1-4])")));

		try {
			if (command == "1")
				get_messages(sock);
			else if (command == "2")
				post_message(sock);
			else if (command == "3")
				delete_message(sock);
			else if (command == "4") {
				quit(sock);
				break;
			}
		}
		catch (const exception& e) {
			die_with_error(e.what());
		}

		cout << endl;
	}

	close(sock);
}