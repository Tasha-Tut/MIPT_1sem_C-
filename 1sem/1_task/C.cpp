#include <iostream>

int count = 0;

void StayQueen(int **array, int n, int x, int y) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      array[i][y] -= 1;
      array[x][j] -= 1;
      if (0 <= x - i + j && x - i + j < n && 0 <= y - j + i && y - j + i < n) {
        array[x - i + j][y - j + i] -= 1;
      }
      if (0 <= i + j - x && i + j - x < n && 0 <= i + j - y && i + j - y < n) {
        array[i + j - y][i + j - x] -= 1;
      }
    }
  }
  array[x][y] = 10000;
}

void RemoveQueen(int **array, int n, int x, int y) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      array[i][y] += 1;
      array[x][j] += 1;
      if (0 <= x - i + j && x - i + j < n && 0 <= y - j + i && y - j + i < n) {
        array[x - i + j][y - j + i] += 1;
      }
      if (0 <= i + j - x && i + j - x < n && 0 <= i + j - y && i + j - y < n) {
        array[i + j - y][i + j - x] += 1;
      }
    }
  }
  array[x][y] = 0;
}

bool MayQueenStay(int **array, int x, int y) {
  return array[x][y] == 0;
  return false;
}

void PeacefulQueens(int **array, int n, int k) {
  for (int j = 0; j < n; ++j) {
    if (MayQueenStay(array, k, j)) {
      if (k == n - 1) {
        count += 1;
        break;
      }
      StayQueen(array, n, k, j);
      PeacefulQueens(array, n, k + 1);
      RemoveQueen(array, n, k, j);
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  auto **array = new int *[n];
  for (int i = 0; i < n; ++i) {
    array[i] = new int[n]{};
  }
  PeacefulQueens(array, n, 0);
  std::cout << count;
  for (int i = 0; i < n; ++i) {
    delete[] array[i];
  }
  delete[] array;
  return 0;
}
