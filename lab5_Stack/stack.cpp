#include <iostream>

using namespace std;

struct node {
  int element;
  struct node* next;
};

struct stack {
  struct node* top;
  int size;

  int pick () {
    if (size == 0) {
      cout << "Попытка вытащить элемент из пустого стека, работа программы прекращена" << endl;
      exit(0);
      return 0;
    }
    return top->element;
  }

  string toString() {
    string result = "[";
    struct node * curNode = top;
    while (curNode != NULL) {
      result += to_string(curNode->element);
      result += " -> ";
      curNode = curNode->next;
    }
    result += "NULL]";
    return result;
  }

  void push(int a) {
    struct node* next = new node();
    next->element = a;
    next->next = top;
    top = next;
    size++;
  }

  int pop() {
    if (size == 0) {
      cout << "Попытка вытащить элемент из пустого стека, работа программы прекращена" << endl;
      exit(0);
      return 0;
    }
    int answer = top->element;
    struct node* next = top->next;
    delete top;
    top = next;
    size--;
    return answer;
  }

  bool empty() {
    return size == 0;
  }
};

int main() {
  stack stack;
  stack.size = 0;
  stack.top = NULL;
  string cmd;
  int a;
  cout << "Введите push a, чтобы добавить число а в стек;" << endl
  << "Введите pop, чтобы вытащить число из вершины стека;" << endl
  << "Введите size, чтобы узнать размер стека;" << endl
  << "Введите empty, чтобы узнать, пуст ли стек;" << endl
  << "Введите pick, чтобы узнать значение последнего элемента, положенного в стек, не вытаскивая его из стека;" << endl
  << "Введите print, чтобы вывести весь стек(начиная от корня);" << endl
  << "Введите exit, чтобы закончить работу со стеком;" << endl;
  cin >> cmd;
  while (cmd != "exit") {

    if (cmd == "push") {
      cin >> a;
      stack.push(a);
    }

    else if (cmd == "pop") {
      cout << stack.pop() << endl;
    }

    else  if (cmd == "size") {
      cout << stack.size << endl;
    }

    else  if (cmd == "empty") {
      if (stack.empty()) {
        cout << "Пуст" << endl;
      } else {
        cout << "Не пуст" << endl;
      }
    }

    else if (cmd == "pick") {
        cout << stack.pick() << endl;
    }

    else if (cmd == "print"){
        cout << stack.toString() << endl;
    }

    else {
      cout << "Введите одну из предложенных команд" << endl;
    }
    cin >> cmd;
  }
  cout << "Работа программы завершена" << endl;
  return 0;
}
