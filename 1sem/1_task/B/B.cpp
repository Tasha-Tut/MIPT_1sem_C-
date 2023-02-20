#include <iostream>

int *CountLine(char **array, int n, int m) {
  int count = 0;
  int k1 = -1;
  int k2 = -1;
  int s;
  auto *chiselki = new int[2];
  for (int i = 0; i < n; ++i) {
    int f = 1;
    for (int j = 0; j < m; ++j) {
      if (array[i][j] == '0') {
        f *= 0;
      }
    }
    if (f == 1) {
      if (k2 == -1) {
        if (k1 == -1) {
          k1 = i;
        } else {
          k2 = i;
        }
      }
      count += 1;
    }
  }
  if (k1 != -1 && k2 != -1) {
    s = k2 - 1 - k1;
  } else {
    s = -1;
  }
  chiselki[0] = count;
  chiselki[1] = s;
  return chiselki;
}

int *CountVerticalLine(char **array, int n, int m) {
  int count = 0;
  int k1 = -1;
  int k2 = -1;
  int s = -1;
  auto *chiselki = new int[10];
  for (int j = 0; j < m; ++j) {
    int f = 1;
    for (int i = 0; i < n; ++i) {
      if (array[i][j] == '0') {
        f *= 0;
      }
    }
    if (f == 1) {
      if (k2 == -1) {
        if (k1 == -1) {
          k1 = j;
        } else {
          k2 = j;
        }
      }
      count += 1;
    }
  }
  if (k1 != -1 && k2 != -1) {
    s = k2 - 1 - k1;
  }
  chiselki[0] = count;
  chiselki[1] = s;
  return chiselki;
}

void WhatIsThis(char **array, int n, int m) {
  int *vline = CountVerticalLine(array, n, m);
  int *line = CountLine(array, n, m);
  if (n == 1 || m == 1) {
    std::cout << '?';
    delete[] line;
    delete[] vline;
    return;
  }
  if (vline[0] >= 1 && line[0] >= 1) {
    std::cout << "Square";
    delete[] line;
    delete[] vline;
    return;
  }
  if (line[0] == 1 && vline[0] == 0) {
    std::cout << '?';
    delete[] line;
    delete[] vline;
    return;
  }
  if (vline[0] == 1 && line[0] == 0) {
    std::cout << '?';
    delete[] line;
    delete[] vline;
    return;
  }
  if (line[0] > 1 && vline[0] == 0) {
    if (m > line[1]) {
      std::cout << "Line";
      delete[] line;
      delete[] vline;
      return;
    }
    std::cout << '?';
    delete[] line;
    delete[] vline;
    return;
  }
  if (vline[0] > 1 && line[0] == 0) {
    if (n > vline[1]) {
      std::cout << "Vertical line";
      delete[] line;
      delete[] vline;
      return;
    }
    std::cout << '?';
    delete[] line;
    delete[] vline;
    return;
  }
}

int main() {
  int n;
  int m;
  std::cin >> n;
  std::cin >> m;
  auto **array = new char *[n];
  for (int i = 0; i < n; ++i) {
    array[i] = new char[m];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> array[i][j];
    }
  }
  WhatIsThis(array, n, m);
  for (int i = 0; i < n; ++i) {
    delete[] array[i];
  }
  delete[] array;
  return 0;
}
