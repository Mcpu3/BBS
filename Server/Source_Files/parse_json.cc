#include "../Header_Files/tcp_server.h"

Data parse_data_json(const string& data_json) {
	picojson::value v;

	if (!picojson::parse(v, data_json).empty())
		throw runtime_error("picojson::parse() failed");

	const Data data{
		v.get<picojson::object>()["method"].get<string>(),
		{
			static_cast<unsigned long long>(v.get<picojson::object>()["message"].get<picojson::object>()["id"].get<double>()),
			v.get<picojson::object>()["message"].get<picojson::object>()["user"].get<string>(),
			v.get<picojson::object>()["message"].get<picojson::object>()["password"].get<string>(),
			v.get<picojson::object>()["message"].get<picojson::object>()["body"].get<string>()
		}
	};

	return data;
}

vector<Message> parse_messages_json() {
	vector<Message> messages;
	picojson::value v;

	ifstream i("messages.json");

	if (!i)
		throw runtime_error("i.open() failed");

	if (!picojson::parse(v, i).empty())
		throw runtime_error("picojson::parse() failed");

	i.close();

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