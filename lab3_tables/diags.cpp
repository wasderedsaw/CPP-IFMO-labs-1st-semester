#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char const *argv[]) {
  int m, n;
  cin >> m >> n;
  while (m <= 0 || n <= 0) {
    cout << "Оба значения должны быть положительными!" << endl;
    cin >> m >> n;
  }
  int a [m][n],b[n][m];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand() % 100 - 50;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout.width(4);
      cout << a[i][j];
    }
    cout << endl;
  }
  cout << endl;
  int j, h;
  int sum;
  cout << "Сумма элементов в диагоналях, параллельных побочной и расположенных выше неё:" << endl;
  for (int i = 1; i < m - 1; i++) {
    j = 0;
    h = i;
    sum = 0;
    while (h + j == i && h * j >= 0) {
      sum += a[h][j];
      h--;
      j++;
    }
    cout.width(4);
    cout << sum << endl;
  }
  cout << endl;
  cout << "Сумма элементов в диагоналях, параллельных побочной и расположенных ниже неё:" << endl;
  for (int i = 1; i < n - 1; i++) {
    j = n - 1;
    h = i;
    sum = 0;
    while (h + j == n + i - 1 && h * j >= 0 && h < n) {
      sum += a[j][h];
      h++;
      j--;
    }
    cout.width(4);
    cout << sum << endl;
  }
  return 0;
}
