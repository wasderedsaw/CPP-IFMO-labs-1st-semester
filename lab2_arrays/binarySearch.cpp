#include <iostream>
#include <cmath>
using namespace std;

int main () {
  int n;
  cin >> n;
  while (n <= 0) {
    cout << "Введите положительное значение n" << endl;
    cin >> n;
  }
  int a [n];
  for (int i = 0; i < n; i++) {
    // cin >> a[i];
    a[i] = rand() % 100;
    // a[i] = i;
  }
  int i = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        flag = true;
      }
    }
    i++;
  }
  cout << "Отсортированный массив: " << endl;
  for (int i = 0; i < n; i++) {
    cout <<  a[i] << " ";
  }
  cout << endl;
  int key;
  int l = 0, r = n - 1;
  cin >> key;
  int startingTime = clock();
  while (l < r - 1) {
    if (key > a[(int)round(l + r) / 2]) {
      l = (int)round(l + r) / 2;
    } else {
      r = (int)round(l + r) / 2;
    }
  }
  if (a[r] == key) {
    cout << "Нашёл" << endl;
  } else {
    cout << "Не нашёл" << endl;
  }
  int timeMachine = (clock() - startingTime) / 1000;
  cout << "Время работы алгоритма в мс - " << timeMachine << endl;
  return 0;
}
