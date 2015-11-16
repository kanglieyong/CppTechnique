#ifndef SOUNDEX_H_
#define SOUNDEX_H_

#include <string>

class Soundex
{
public:
  std::string encode(const std::string& word) const {
    return zeroPad(word);
  }

private:
  std::string zeroPad(const std::string& word) const {
    return word + "0000";
  }
};

#endif
