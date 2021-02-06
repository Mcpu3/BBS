#include "../Header_Files/tcp_server.h"

string create_messages_without_password_json(const vector<Message>& messages) {
	picojson::object v;
	picojson::array v1;

	for (const Message& message : messages) {
		picojson::object v2;

		v2.emplace("id", static_cast<double>(message.id));
		v2.emplace("user", message.user);
		v2.emplace("password", "");
		v2.emplace("body", message.body);

		v1.emplace_back(v2);
	}

	v.emplace("messages", v1);

	return picojson::value(v).serialize();
}

string create_status_message_json(const string& status_message) {
	picojson::object v;

	v.emplace("status_message", status_message);

	return picojson::value(v).serialize();
}

void create_messages_json(const vector<Message>& messages) {
	picojson::object v;
	picojson::array v1;

	for (const Message& message : messages) {
		picojson::object v2;

		v2.emplace("id", static_cast<double>(message.id));
		v2.emplace("user", message.user);
		v2.emplace("password", message.password);
		v2.emplace("body", message.body);

		v1.emplace_back(v2);
	}

	v.emplace("messages", v1);

	ofstream o("messages.json");

	if (!o)
		throw runtime_error("o.open() failed");

	o << picojson::value(v);
	o.close();
}