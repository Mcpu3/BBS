#include "../Header_Files/tcp_server.h"

void post_message(const int& client_sock, const Data& data) {
	vector<Message> messages = parse_messages_json();

	messages.emplace_back(
		messages.back().id + 1ull,
		data.message.user,
		data.message.password,
		data.message.body
	);

	create_messages_json(messages);

	const string status_message_json = create_status_message_json("OK") + '\0';

	if (send(client_sock, status_message_json.c_str(), status_message_json.length(), 0) != static_cast<ssize_t>(status_message_json.length()))
		throw runtime_error("send() failed");
}