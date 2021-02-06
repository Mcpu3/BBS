#include "../Header_Files/tcp_client.h"

void delete_message(const int& sock) {
	unsigned long long id;
	string password;
	string ok;

	while (true) {
		string id_string;

		do {
			cout << "ID>";
			getline(cin, id_string);
		} while (!regex_match(id_string, regex(R"(\d+)")));

		try {
			id = stoull(id_string);
		}
		catch (const exception& e) {
			cerr << "\x1b[33m" << e.what() << "\x1b[0m" << endl;
			continue;
		}

		break;
	}

	do {
		cout << "パスワード>";
		getline(cin, password);
	} while (!regex_match(password, regex(R"(.+)")));

	do {
		cout << "削除しますか (Y/N)?>";
		getline(cin, ok);
	} while (!regex_match(ok, regex(R"([YyNn])")));

	if (!regex_match(ok, regex(R"([Yy])")))
		return;
	
	const Data data{
		"delete",
		{
			id,
			"",
			password,
			""
		}
	};

	const string data_json = create_data_json(data) + '\0';

	if (send(sock, data_json.c_str(), data_json.length(), 0) != static_cast<ssize_t>(data_json.length()))
		throw runtime_error("send() failed");

	cout << parse_status_message_json(receive_from(sock, '\0')) << endl;
}