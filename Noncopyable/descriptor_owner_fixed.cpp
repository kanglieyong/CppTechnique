#include <boost/noncopyable.hpp>
#include <string>

class descriptor_owner_fixed : private boost::noncopyable
{
public:
  explicit descriptor_owner_fixed(const std::string& inStr = "Hello")
    : mStr(inStr)
  {}
  
private:
  std::string mStr;
};

int main(void)
{
  descriptor_owner_fixed d1("O_O");
  descriptor_owner_fixed d2("^_^");

  // can't compile
  // d2 = d1;
  // can't compile
  // descriptor_owner_fixed d3(d1);

  return 0;
}
