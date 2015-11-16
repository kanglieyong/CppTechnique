#include <gmock/gmock.h>
#include "Soundex.h"

using namespace testing;

class SoundexEncoding : public Test {
public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  ASSERT_THAT(soundex.encode("A"), Eq("A0000"));
}

TEST_F(SoundexEncoding, PadsWithZeroToEnsureThreeDigits) {
  ASSERT_THAT(soundex.encode("I"), Eq("I0000"));
}
