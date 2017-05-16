#include <memory>
#include <mutex>

class singleton
{
public:
  virtual ~singleton() {}
  static singleton& instance();
  
private:
  static std::unique_ptr<singleton> instance_;
  static std::once_flag once_flag_;
  
  singleton() {}
  singleton(const singleton &src);
  singleton& operator=(const singleton &rhs);
};

std::unique_ptr<singleton> singleton::instance_;
std::once_flag singleton::once_flag_;

singleton& singleton::instance()
{
  std::call_once(once_flag_,
    []{ instance_.reset(new singleton); });
  return *instance_.get();
}

int main()
{
  singleton &ref = singleton::instance();
  
  return 0;
}
