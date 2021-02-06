#include "../Header_Files/tcp_server.h"

int main() {
	const unsigned short server_port = static_cast<unsigned short>(49152);

	int server_sock;

	try {
		server_sock = create_tcp_server_sock(server_port);
	}
	catch (const exception& e) {
		die_with_error(e.what());
	}

	vector<Message> messages{
		{
			0ull,
			"4402_岩本圭介",
			"Af$d^VA3c^9HWyx*",
			"BBSにようこそ\n括弧内の数値はID, この文字列は本文, \"--\" に続く文字列はユーザーです"
		}
	};

	try {
		create_messages_json(messages);
	}
	catch (const exception& e) {
		die_with_error(e.what());
	}

	while (true) {
		int client_sock;

		try {
			client_sock = accept_tcp_connection(server_sock);
		}
		catch (const exception& e) {
			die_with_error(e.what());
		}

		thread t(thread_main, client_sock);

		t.detach();
	}
}

void thread_main(const int& client_sock) {
	while (true) {
		Data data;

		try {
			data = parse_data_json(receive_from(client_sock, '\0'));
		}
		catch (const exception& e) {
			cerr << "\x1b[33m" << e.what() << "\x1b[0m" << endl;
			return;
		}

		try {
			if (data.method == "delete")
				delete_message(client_sock, data);
			else if (data.method == "get")
				get_messages(client_sock);
			else if (data.method == "post")
				post_message(client_sock, data);
			else if (data.method == "quit")
				break;
		}
		catch (const exception& e) {
			cerr << "\x1b[33m" << e.what() << "\x1b[0m" << endl;
			return;
		}
	}

	close(client_sock);
}