#include <iostream>

using namespace std;

const int N = 1000;

struct car* cars[N];

void removeCar(int number);

void initialize() {
  for (int i = 0; i < N; i++) {
    cars[i] = NULL;
  }
}

struct node {
  struct car* element;
  struct node* next;
};

struct car {
  int number;
  int moved;
};

struct stack {
  struct node* top;
  int size;

  struct car* pick () {
    if (size == 0) {
      cout << "Попытка вытащить элемент из пустого стека, работа программы прекращена" << endl;
      exit(0);
      return 0;
    }
    return top->element;
  }

  string toString() {
    if (size == 0) {
      return "[Пусто]";
    }
    string result = "[Въезд -> ";
    struct node * curNode = top;
    while (curNode != NULL) {
      result += to_string(curNode->element->number);
      result += " -> ";
      curNode = curNode->next;
    }
    result += " Тупик]";
    return result;
  }

  void push(struct car* a) {
    struct node* next = new node();
    next->element = a;
    next->next = top;
    top = next;
    size++;
  }

  struct car* pop() {
    if (size == 0) {
      cout << "Попытка вытащить элемент из пустого стека, работа программы прекращена" << endl;
      exit(0);
      return 0;
    }
    struct car* answer = top->element;
    struct node* next = top->next;
    delete top;
    top = next;
    size--;
    return answer;
  }

  bool empty() {
    return size == 0;
  }

  int whereCarIs(int num) {
    int answer = -1;
    if (size == 0) {
      return -1;
    }
    struct node * curNode = top;
    while (curNode->element->number != num) {
      answer++;
      curNode = curNode->next;
    }
    answer++;
    return answer;
  }
};

stack stack;

int away(int num) {
  struct stack temporary;
  temporary.size = 0;
  temporary.top = NULL;
  while (stack.pick()->number != num){
    stack.pick()->moved++;
    temporary.push(stack.pop());
  };
  int answer = stack.pick()->moved;
  removeCar(num);
  stack.pop();
  while (!temporary.empty()) {
    stack.push(temporary.pop());
  }
  return answer;
}

struct car* getCar(int number) {
  if (cars[number] != NULL) {
    return cars[number];
  }
  struct car* newCar = new car();
  newCar-> number = number;
  newCar->moved = 0;
  cars[number] = newCar;
  return newCar;
}

void removeCar(int number) {
  if (cars[number] == NULL) {
    cerr << " Нет машины с номером " << number << endl;
    return;
  }
  delete cars[number];
  cars[number] = NULL;
}


int main() {
  initialize();
  stack.size = 0;
  stack.top = NULL;
  string cmd;
  int a, num;
  cout << "Введите push a, чтобы добавить машину с номером а на парковку;" << endl
  << "Введите pop а, чтобы убрать с парковки машину с номером а(если она там есть);" << endl
  << "Введите size, чтобы узнать количество машин на парковке;" << endl
  << "Введите empty, чтобы узнать, пуста ли парковка;" << endl
  << "Введите pick, чтобы узнать номер ближайшей к выезду машины;" << endl
  << "Введите print, чтобы вывести список всех находящихся на парковке машин;" << endl
  << "Введите away a, чтобы убрать с парковки машину с номером а(если она там есть);" << endl
  << "Введите where a, чтобы узнать, где на парковке находится машина с номером а;" << endl
  << "Введите exit, чтобы закончить работу с парковкой;" << endl;
  cin >> cmd;
  while (cmd != "exit") {

    if (cmd == "push") {
      cin >> a;
      struct car* car = getCar(a);
      stack.push(car);
      cout << "Машина с номером " << a << " поставлена у въезда" << endl;
    }

    else if (cmd == "size") {
      cout << stack.size << endl;
    }

    else  if (cmd == "empty") {
      if (stack.empty()) {
        cout << "Парковка пуста" << endl;
      } else {
        cout << "На парковке есть машины" << endl;
      }
    }

    else if (cmd == "pick") {
        cout << "Car #" << stack.pick()->number << endl;
    }

    else if (cmd == "print"){
        cout << stack.toString() << endl;
    }

    else if (cmd == "where") {
        cin >> num;
        if (stack.whereCarIs(num) == -1) {
          cout << "Машины с таким номером нету" << endl;
        } else {
          cout << "Машина с таким номером находится на " << stack.whereCarIs(num) << " позиции(считая от выезда)" << endl;
        }
    }

    else if (cmd == "away") {
        cin >> num;
        if (stack.whereCarIs(num) == -1) {
          cout << "Машины с таким номером нету" << endl;
        } else {
          cout << "Машина убрана, с момента её приезда её пришлось двигать " << away(num) << " раз(a)" << endl;
        }
    }

    else {
      cout << "Введите одну из предложенных команд" << endl;
    }

    cin >> cmd;
  }
  cout << "Работа программы завершена" << endl;
  return 0;
}
