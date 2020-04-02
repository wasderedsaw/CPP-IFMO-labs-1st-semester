#include <iostream>
#include <cstdlib>

using namespace std;

int m, n;

int minimum(int array []) {
  int min = array[0];
  for (int i = 1; i < n; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

int maximum(int array []) {
  int max = array[0];
  for (int i = 1; i < m; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

int main() {
  cin >> m >> n;
  while (m <= 0 || n <= 0) {
    cout << "Оба значения должны быть положительными!" << endl;
    cin >> m >> n;
  }
  int a [m][n],b[n][m];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand() % 100 - 50;
      // cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[i][j]=a[j][i];
    }
    cout << endl;
  }
  cout << endl;
  int sum;
  bool flag = false, flag2 = false;;
  for (int i = 0; i < m; i++) {
    flag = false;
    sum = 0;
    for (int j = 0; j < n; j++) {
      sum += a[i][j];
      if (!flag && a[i][j] < 0) {
        flag = true;
        flag2 = true;
      }
    }
    if (flag) {
      cout << i + 1 << "-ая строка содержит отрицательный(ые) элемент(ы), сумма элеметнов в этой строке равна " << sum << endl;
    }
  }
  if (!flag2) {
    cout << "В этом массиве нет строк с отрицательными элементами" << endl;;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == minimum(a[i]) && a[i][j] == maximum(b[j])) {
        cout << "Точка, находящаяся на пересечении " << i + 1 << " строки и " << j + 1 << " столбца - седловая точка матрицы" << endl;
      }
    }
  }
  return 0;
}
