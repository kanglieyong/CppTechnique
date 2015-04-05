#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size = 390000L;

int main()
{
  using std::cout;
  using std::endl;
  using std::vector;

  vector<int> numbers(Size);

  std::srand(std::time(0));
  std::generate(numbers.begin(), numbers.end(), std::rand);
  cout << "Sample size = " << Size << "\n";

  // using lambdas
  int count3 = std::count_if(numbers.begin(), numbers.end(), [](int x){ return x % 3 == 0; });
  cout << "Count of numbers divisible by 3 : " << count3 << endl;
}
