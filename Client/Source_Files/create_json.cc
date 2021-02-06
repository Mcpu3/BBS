#include "../Header_Files/tcp_client.h"

string create_data_json(const Data& data) {
	picojson::object v;
	picojson::object v1;

	v.emplace("method", data.method);

	v1.emplace("id", static_cast<double>(data.message.id));
	v1.emplace("user", data.message.user);
	v1.emplace("password", data.message.password);
	v1.emplace("body", data.message.body);

	v.emplace("message", v1);

	return picojson::value(v).serialize();
}