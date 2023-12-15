#pragma once

#include <iostream>
#include <sstream>
#include <string>

namespace HTML_encode {

class Encode {

public:
  Encode(const std::string &content) {
    std::stringstream ss;
    std::string buff;
    bool first = true;
    ss << content;
    while (std::getline(ss, buff)) {
      if (!first) {
        encoded_text_ += "%0A";
      } else {
        first = false;
      }
      Parse(buff);
    }
  }

  std::string GetResult() { return encoded_text_; }

private:
  std::string encoded_text_;

private:
  void Parse(const std::string &line) {
    for (const char ch : line) {
      switch (ch) {
      case ' ':
        encoded_text_ += "%20";
        break;
      case '#':
        encoded_text_ += "%23";
        break;
      case '$':
        encoded_text_ += "%24";
        break;
      case '%':
        encoded_text_ += "%25";
        break;
      case '&':
        encoded_text_ += "%26";
        break;
      case '+':
        encoded_text_ += "%2B";
        break;
      case ',':
        encoded_text_ += "%2C";
        break;
      case '/':
        encoded_text_ += "%2F";
        break;
      case ':':
        encoded_text_ += "%3A";
        break;
      case ';':
        encoded_text_ += "%3B";
        break;
      case '<':
        encoded_text_ += "%3C";
        break;
      case '=':
        encoded_text_ += "%3D";
        break;
      case '>':
        encoded_text_ += "%3E";
        break;
      case '?':
        encoded_text_ += "%3F";
        break;
      case '@':
        encoded_text_ += "%40";
        break;
      case '[':
        encoded_text_ += "%5B";
        break;
      case '\\':
        encoded_text_ += "%5C";
        break;
      case ']':
        encoded_text_ += "%5D";
        break;
      case '^':
        encoded_text_ += "%5E";
        break;
      case '{':
        encoded_text_ += "%7B";
        break;
      case '}':
        encoded_text_ += "%7D";
        break;
      case '|':
        encoded_text_ += "%7C";
        break;
      default:
        encoded_text_.push_back(ch);
        break;
      }
    }
  }
};

} // namespace HTML_encode
