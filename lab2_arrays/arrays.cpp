#include <iostream>
#include <cstdlib>

using namespace std;

void

int main(int argc, char const *argv[]) {
  int n;
  cout << "1 - ввод с клавиатуры, 2 - генерация случайных значений" << endl;
  int x;
  cin >> x;
  while (x != 1 && x != 2) {
    cout << "Введите 1 или 2!" << endl;
    cin >> x;
  }
  if (x == 1) {
    cout << "Введите n" << endl;
    cin >> n;
    int array [n];
    cout << "Введите n элементов массива" << endl;
    for (int i = 0; i < n; i++) {
      cin >> array[i];
    }
  } else {
    n = 10000;
    int array [n];
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }
    cout << "Сгенерировано " << n << " случайных чисел от 0 до 99" << endl;
  }
  int control = -1;
  while (control != 0) {
    cout << "Введите 0 для выхода" << endl;
    cout << "Введите 1 для выполнения условия лабы" << endl;
    cout << "Введите 2 для сортировки пузырьком ..." << endl;
    cout << "Введите 3 для сортировки пузырьком ..." << endl;
    cout << "Введите 4 для сортировки пузырьком с флажком" << endl;
    cout << "Введите 5 для линейного поиска" << endl;
    cout << "Введите 5 для бинарного поиска" << endl;
    cin >> control;
    switch (control) {
      case 1:

        break;
      case 2:

        break;
      case 3:

        break;
      case 4:

        break;
      case 5:

        break;
      case 0:
        continue;
        break;
    }
  }
  cout << "Работа программы завершена" << endl;
  return 0;
}
