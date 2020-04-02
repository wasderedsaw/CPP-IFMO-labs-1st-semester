#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct worker {
  string fullName;
  string position;
  int year;
};

int main() {
  int currentYear = 2019;
  ifstream fin("input.txt");
  int n = 11;
  worker workers [n];
  string s1, s2, s3, s4;
  for (int i = 0; i < n; i++) {
    fin >> s1 >> s2 >> s3 >> s4;
    workers[i].fullName = s1 + " " + s2;
    workers[i].position = s3 + " " + s4;
    fin >> workers[i].year;
  }
  int i = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int j = 0; j < n - 1 - i; j++) {
      if (workers[j].fullName > workers[j + 1].fullName) {
        swap(workers[j], workers[j + 1]);
        flag = true;
      }
    }
    i++;
  }
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " работник:" << endl;
    cout << workers[i].fullName << " " << workers[i].position << " " << workers[i].year << endl;
  }
  int minimalExperience = 0;
  cout << "Введите минимальный стаж:" << endl;
  cin >> minimalExperience;
  bool nobodyIsWorth = true;
  int experience = 0;
  for (int i = 0; i < n; i++) {
    experience = currentYear - workers[i].year;
    if (experience > minimalExperience) {
      nobodyIsWorth = false;
      if (minimalExperience >= 5 && minimalExperience <= 20 || minimalExperience % 10 == 0) {
        cout << "Стаж работника " << workers[i].fullName << " превышает " << minimalExperience << " лет (" << currentYear - workers[i].year << ")" << endl;
      } else {
        if (minimalExperience % 10 == 1 && minimalExperience != 11) {
            cout << "Стаж работника " << workers[i].fullName << " превышает " << minimalExperience << " год (" << currentYear - workers[i].year << ")" << endl;
        } else {
          cout << "Стаж работника " << workers[i].fullName << " превышает " << minimalExperience << " года (" << currentYear - workers[i].year << ")" << endl;
        }
      }
    }
  }
  if (nobodyIsWorth) {
    cout << "Нет ни одного работника с требуемым стажем";
  }
  return 0;
}
