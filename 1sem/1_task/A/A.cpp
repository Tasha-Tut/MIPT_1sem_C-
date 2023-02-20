#include <iostream>

int NumberNeighbors(int **array, int n, int x, int y) {
  ++x;
  ++y;
  auto **with_frame = new int *[n + 2];
  for (int i = 0; i < (n + 2); ++i) {
    with_frame[i] = new int[n + 2]{};
  }
  for (int i = 1; i < (n + 1); ++i) {
    for (int j = 1; j < (n + 1); ++j) {
      with_frame[i][j] = array[i - 1][j - 1];
    }
  }
  int s = with_frame[x - 1][y - 1] + with_frame[x - 1][y] + with_frame[x - 1][y + 1] + with_frame[x][y - 1] +
          with_frame[x][y + 1] + with_frame[x + 1][y - 1] + with_frame[x + 1][y] + with_frame[x + 1][y + 1];
  for (int i = 0; i < (n + 2); ++i) {
    delete[] with_frame[i];
  }
  delete[] with_frame;
  return s;
}

void OneSecond(int **array, int n) {
  auto **new_array = new int *[n];
  for (int i = 0; i < n; ++i) {
    new_array[i] = new int[n];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int k = NumberNeighbors(array, n, i, j);
      if (array[i][j] == 1) {
        if (k == 2 || k == 3) {
          new_array[i][j] = 1;
        } else {
          new_array[i][j] = 0;
        }
      } else {
        if (k == 3) {
          new_array[i][j] = 1;
        } else {
          new_array[i][j] = 0;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      array[i][j] = new_array[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    delete[] new_array[i];
  }
  delete[] new_array;
}

int main() {
  int n;
  int t;
  std::cin >> n;
  std::cin >> t;
  auto **array = new int *[n];
  for (int i = 0; i < n; ++i) {
    array[i] = new int[n];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> array[i][j];
    }
  }

  for (int p = 0; p < t; ++p) {
    OneSecond(array, n);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << array[i][j] << ' ';
    }
    std::cout << '\n';
  }

  for (int i = 0; i < n; ++i) {
    delete[] array[i];
  }
  delete[] array;
  return 0;
}
