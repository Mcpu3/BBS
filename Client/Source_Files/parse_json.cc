#include "../Header_Files/tcp_client.h"

string parse_status_message_json(const string& status_message_json) {
	picojson::value v;

	if (!picojson::parse(v, status_message_json).empty())
		throw runtime_error("picojson::parse() failed");

	return v.get<picojson::object>()["status_message"].get<string>();
}

vector<Message> parse_messages_json(const string& messages_json) {
	vector<Message> messages;
	picojson::value v;

	if (!picojson::parse(v, messages_json).empty())
		throw runtime_error("picojson::parse() failed");

	for (picojson::array::iterator i = v.get<picojson::object>()["messages"].get<picojson::array>().begin(); i != v.get<picojson::object>()["messages"].get<picojson::array>().end(); i++) {
		messages.emplace_back(
			static_cast<unsigned long long>(i->get<picojson::object>()["id"].get<double>()),
			i->get<picojson::object>()["user"].get<string>(),
			i->get<picojson::object>()["password"].get<string>(),
			i->get<picojson::object>()["body"].get<string>()
		);
	}

	return messages;
}