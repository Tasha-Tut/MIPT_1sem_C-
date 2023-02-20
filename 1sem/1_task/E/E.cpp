#include <iostream>
#include <cmath>

void Swap(int &a, int &b) {
  int q = a;
  a = b;
  b = q;
}

void Sort(int *array, int lenth) {
  int mini;
  for (int i = 0; i < lenth - 1; ++i) {
    mini = i;
    for (int j = i + 1; j < lenth; ++j) {
      if (array[j] < array[mini]) {
        mini = j;
      }
    }
    Swap(array[i], array[mini]);
  }
}

int main() {
  int cost;
  int lenth;
  int new_lenth = 0;
  int maximum_sum = 0;
  int dollar;
  std::cin >> cost;
  std::cin >> lenth;
  auto *array = new int[lenth]{};
  for (int i = 0; i < lenth; ++i) {
    std::cin >> dollar;
    maximum_sum += 2 * dollar;
    if (dollar <= cost) {
      array[i] = dollar;
      ++new_lenth;
    }
  }
  Sort(array, new_lenth);
  auto *dynamic_array = new int[new_lenth]{};
  auto *tmp_array = new int[new_lenth]{};
  int number = pow(3, new_lenth);
  int jimmi = 100000;
  for (int i = 0; i < number; ++i) {
    int x = i;
    int sum = 0;
    int count = 0;
    for (int j = 0; j < new_lenth; ++j) {
      dynamic_array[j] = x % 3;
      sum += dynamic_array[j] * array[j];
      count += dynamic_array[j];
      x /= 3;
    }
    if (sum == cost) {
      if (count < jimmi) {
        for (int j = 0; j < new_lenth; ++j) {
          tmp_array[j] = dynamic_array[j];
        }
        jimmi = count;
      }
    }
  }
  if (jimmi == 100000) {
    if (maximum_sum < cost) {
      std::cout << -1;
    } else {
      if (maximum_sum > cost) {
        std::cout << 0;
      }
    }
  } else {
    std::cout << jimmi << '\n';
    for (int i = new_lenth - 1; i >= 0; --i) {
      if (tmp_array[i] == 2) {
        std::cout << array[i] << ' ' << array[i] << ' ';
      } else {
        if (tmp_array[i] == 1) {
          std::cout << array[i] << ' ';
        }
      }
    }
  }
  delete[] dynamic_array;
  delete[] tmp_array;
  delete[] array;
  return 0;
}
