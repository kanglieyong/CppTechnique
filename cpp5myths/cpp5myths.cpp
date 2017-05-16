#include <iostream>
#include <string>
#include <set>
#include <regex>
#include <exception>

#include <boost/asio.hpp>

using std::cout;
using std::iostream;
using std::string;
using std::istream;
using std::set;
using std::regex;
using std::smatch;
using std::runtime_error;

set<string> get_strings(istream& is, regex pat)
{
	set<string> res;
	smatch m;
	for (string s; getline(is, s); )  // read a line
		if (regex_search(s, m, pat))
			res.insert(m[0]);              // save match in set
	return res;
}

// open a connection to server and open an attach file to skip headers
void connect_to_file(iostream& s, const string& server, const string& file)
{
	if (!s)
		throw runtime_error{ "can't connect\n" };

	// Request to read the file from the server:
	s << "GET " << "http://" + server + "/" + file << " HTTP/1.0\r\n";
	s << "Host: " << server << "\r\n";
	s << "Accept: */*\r\n";
	s << "Connection: close\r\n\r\n";

	// Check that the response is OK:
	string http_version;
	unsigned int status_code;
	s >> http_version >> status_code;

	string status_message;
	getline(s, status_message);

	if (!s || http_version.substr(0, 5) != "HTTP/")
		throw runtime_error{ "Invalid response\n" };

	if (status_code != 200)
		throw runtime_error{ "Response returned with status code" };

	// Discard the response headers, which are terminated by a blank line:
	string header;
	while (getline(s, header) && header != "\r")
		;
}

int main()
{
	try {
		string server = "www.stroustrup.com";
		boost::asio::ip::tcp::iostream s{ server,"http" };  // make a connection
		connect_to_file(s, server, "C++.html");    // check and open file

		regex pat{ R"((http://)?www([./#\+-]\w*)+)" }; // URL
		for (auto x : get_strings(s, pat))    // look for URLs
			cout << x << '\n';
	}
	catch (std::exception& e) {
		cout << "Exception: " << e.what() << "\n";
		return 1;
	}

	return 0;
}
