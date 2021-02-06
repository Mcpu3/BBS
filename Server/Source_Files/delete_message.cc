#include "../Header_Files/tcp_server.h"

void delete_message(const int& client_sock, const Data& data) {
	vector<Message> messages = parse_messages_json();

	const vector<Message>::iterator result = find_if(messages.begin(), messages.end(), [&data](const Message& msg) { return msg.id == data.message.id; });

	if (result == messages.end()) {
		const string status_message_json = create_status_message_json("\x1b[33m不正なIDです\x1b[0m") + '\0';

		if (send(client_sock, status_message_json.c_str(), status_message_json.length(), 0) != static_cast<ssize_t>(status_message_json.length()))
			throw runtime_error("send() failed");

		return;
	}

	if (data.message.password != result->password) {
		const string status_message_json = create_status_message_json("\x1b[33m不正なパスワードです\x1b[0m") + '\0';

		if (send(client_sock, status_message_json.c_str(), status_message_json.length(), 0) != static_cast<ssize_t>(status_message_json.length()))
			throw runtime_error("send() failed");

		return;
	}

	messages.erase(result);

	create_messages_json(messages);

	const string status_message_json = create_status_message_json("OK") + '\0';

	if (send(client_sock, status_message_json.c_str(), status_message_json.length(), 0) != static_cast<ssize_t>(status_message_json.length()))
		throw runtime_error("send() failed");
}