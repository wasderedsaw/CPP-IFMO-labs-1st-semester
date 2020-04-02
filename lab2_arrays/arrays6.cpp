#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int n;
  cin >> n;
  int array [n];
  // for (int i = 0; i < n; i++) {
  //   cin >> array[i];
  // }
  for (int i = 0; i < n; i++) {
  //  cin >> a[i];
      array[i] = rand() % 10 - 5;
      // a[i] = i;
  }
  for (int i = 0; i < n; i++) {
    cout << array[i] << endl;
  }
  cout << endl;
  int min = array[0];
  for (int i = 1; i < n; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  cout << min << endl;
  int first = -1, last = -1;
  for (int i = 0;i < n; i++) {
    if (array[i] > 0 && first == -1) {
      first = i;
    }
    if (array[i] > 0) {
      last = i;
    }
  }
  if (last - first < 1) {
    cout << "Неверные вводные данные" << endl;
  } else {
    int answer = 0;
    for (int i = first + 1; i < last; i++) {
      answer += array[i];
    }
    cout << answer << endl;
  }
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (array[i] == 0) {
      for (int j = i; j > index; j--) {
        swap(array[j], array[j - 1]);
      }
      index++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
  return 0;
}
