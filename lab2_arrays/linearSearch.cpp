#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n <= 0) {
    cout << "Введите положительное значение n" << endl;
    cin >> n;
  }
  int array [n];
  for (int i = 0; i < n; i++) {
    //cin >> array[i];
    array[i] = i;
  }
  int key;
  cin >> key;
  int startingTime = clock();
  int answer = -1;
  for (int i = 0; i < n; i++) {
    if (array[i] == key) {
      answer = i;
      break;
    }
  }
  if (answer == -1) {
    cout << "Не нашёл =(" << endl;
  } else {
    answer++;
    cout << "Нашёл, число находится на " << answer << " позиции" << endl;
  }
  int counter = (clock() - startingTime) / 1000;
  cout << "Время работы алгоритма в милисекундах - " << counter << endl;
  return 0;
}
