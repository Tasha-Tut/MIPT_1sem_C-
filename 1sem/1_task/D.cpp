#include <iostream>

void Clean(int);
void Get(int);

void Clean(int n) {
  if (n == 1) {
    std::cout << -1 << ' ';
  }
  if (n == 2) {
    std::cout << -2 << ' ' << -1 << ' ';
  }
  if (n > 2) {
    Clean(n - 2);
    std::cout << -n << ' ';
    Get(n - 2);
    Clean(n - 1);
  }
}

void Get(int n) {
  if (n == 1) {
    std::cout << 1 << ' ';
  }
  if (n == 2) {
    std::cout << 1 << ' ' << 2 << ' ';
  }
  if (n > 2) {
    Get(n - 1);
    Clean(n - 2);
    std::cout << n << ' ';
    Get(n - 2);
  }
}

int main() {
  int n;
  std::cin >> n;
  Get(n);
  return 0;
}
