#include "parser.h"

namespace HTML_encode
{

	std::string Encode(const std::string& content) {
		std::string encoded_text;
		std::string::const_iterator it = content.begin();
		std::string::const_iterator end = content.end();
		while (true) {
			if (it == end) {
				break;
			}
			const char ch = *it;
			if (ch == '\\' && std::next(it) < end && *std::next(it) == 'n') {
				char ins[] = "%0A";
				encoded_text.push_back(*ins);
				++it;
			}
			else {
				switch (ch)
				{
				case ' ':
					encoded_text += "%20";
					break;
				case '#':
					encoded_text += "%23";
					break;
				case '$':
					encoded_text += "%24";
					break;
				case '%':
					encoded_text += "%25";
					break;
				case '&':
					encoded_text += "%26";
					break;
				case '+':
					encoded_text += "%2B";
					break;
				case ',':
					encoded_text += "%2C";
					break;
				case '/':
					encoded_text += "%2F";
					break;
				case ':':
					encoded_text += "%3A";
					break;
				case ';':
					encoded_text += "%3B";
					break;
				case '<':
					encoded_text += "%3C";
					break;
				case '=':
					encoded_text += "%3D";
					break;
				case '>':
					encoded_text += "%3E";
					break;
				case '?':
					encoded_text += "%3F";
					break;
				case '@':
					encoded_text += "%40";
					break;
				case '[':
					encoded_text += "%5B";
					break;
				case '\\':
					encoded_text += "%5C";
					break;
				case ']':
					encoded_text += "%5D";
					break;
				case '^':
					encoded_text += "%5E";
					break;
				case '{':
					encoded_text += "%7B";
					break;
				case '}':
					encoded_text += "%7D";
					break;
				case '|':
					encoded_text += "%7C";
					break;
				default:
					encoded_text.push_back(ch);
					break;
				}
			}
			++it;
		}
		return encoded_text;
	}

}