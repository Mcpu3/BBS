#include "../Header_Files/tcp_client.h"

void get_messages(const int& sock) {
	const Data data{
		"get",
		{
			0ull,
			"",
			"",
			""
		}
	};

	const string data_json = create_data_json(data) + '\0';

	if (send(sock, data_json.c_str(), data_json.length(), 0) != static_cast<ssize_t>(data_json.length()))
		throw runtime_error("send() failed");

	const vector<Message> messages = parse_messages_json(receive_from(sock, '\0'));

	for (const Message& message : messages) {
		cout << '[' << message.id << ']' << ' ';
		cout << message.body << ' ';
		cout << "--" << message.user << endl;
		cout << '_' << endl;
	}
}