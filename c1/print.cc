#include <iostream>
int main() {
  int v1 = 0, v2 = 0;
  std::cout << "Enter two number and will print number between them"
            << std::endl;
  std::cin >> v1 >> v2;

  while (v1 <= v2) {
    std::cout << v1 << std::endl;
    v1++;
  }
}
