#include "../Header_Files/tcp_client.h"

void post_message(const int& sock) {
	string user;
	string password;
	string body;
	string ok;

	do {
		cout << "ユーザー>";
		getline(cin, user);
	} while (!regex_match(user, regex(R"(.+)")));

	do {
		cout << "パスワード>";
		getline(cin, password);
	} while (!regex_match(password, regex(R"(.+)")));

	do {
		cout << "本文>";
		getline(cin, body);
	} while (!regex_match(body, regex(R"(.+)")));

	do {
		cout << "書き込みますか (Y/N)?>";
		getline(cin, ok);
	} while (!regex_match(ok, regex(R"([YyNn])")));

	if (!regex_match(ok, regex(R"([Yy])")))
		return;

	const Data data{
		"post",
		{
			0ull,
			user,
			password,
			body
		}
	};

	const string data_json = create_data_json(data) + '\0';

	if (send(sock, data_json.c_str(), data_json.length(), 0) != static_cast<ssize_t>(data_json.length()))
		throw runtime_error("send() failed");

	cout << parse_status_message_json(receive_from(sock, '\0')) << endl;
}