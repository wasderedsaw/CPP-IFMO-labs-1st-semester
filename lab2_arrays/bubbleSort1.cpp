#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int n;
  n = 10000;
  //cin >> n;
  // while (n <= 0) {
  //   cout << "Введите положительное значение n" << endl;
  //   cin >> n;
  // }
  int a [n];
  for (int i = 0; i < n; i++) {
  //  cin >> a[i];
      a[i] = rand() % 100;
      // a[i] = i;
  }
  int startingTime = clock();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
        if (a[j] > a[j + 1]) {
          swap(a[j],a[j + 1]);
        }
    }
  }
  int counter = (clock() - startingTime) / 1000;
  for (int i = 0; i < n; i++) {
    cout <<  a[i] << " ";
  }
  cout << endl;
  cout << "Время работы алгоритма в мс - " << counter << endl;
  return 0;
}
