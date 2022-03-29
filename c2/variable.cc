#include <iostream>
int main() {
  long double ld = 3.1415926536;
  int i = 100, sum = 0;
  for (int i = 0; i != 10; ++i)
    sum += i;

  std::cout << i << " " << sum << std::endl;

  double dval = 3.14;
  const int& ri = dval;
  std::cout << ri << std::endl;

  constexpr int bufsize = 1024;
  constexpr int limit = bufsize + 512;
}
