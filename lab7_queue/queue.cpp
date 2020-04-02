#include <iostream>

using namespace std;

struct node {
  int element;
  struct node* next;
  struct node* prev;
};

struct queue {
  int size;
  struct node* top;
  struct node* bot;

  bool empty() {
    return size == 0;
  }

  void push(int a) {
    struct node* next = new node();
    next->next = NULL;
    next->prev = NULL;
    next->element = a;
    if (size == 0) {
      top = next;
    } else {
      next->next = bot;
      bot->prev = next;
    }
    bot = next;
    size++;
  }

  int pick() {
    if (size == 0) {
      cout << "Попытка вытащить элемент из пустой очереди, работа программы прекращена" << endl;
      exit(0);
      return 0;
    }
    return top->element;
  }

  int pop() {
    if (size == 0) {
      cout << "Попытка вытащить элемент из пустой очереди, работа программы прекращена" << endl;
      exit(0);
      return 0;
    }
    int answer = top->element;
    struct node* prev = top->prev;
    if (prev == NULL) {
      bot = NULL;
    } else {
    delete top;
    prev->next = NULL;
    }
    top = prev;
    size--;
    return answer;
  }

  string toString() {
    if (size == 0) {
      return "[NULL]";
    }
    string result = "[";
    struct node * curNode = bot;
    while (curNode != NULL) {
      result += to_string(curNode->element);
      result += " --> ";
      curNode = curNode->next;
    }
    result += "NULL]";
    return result;
  }
};

int main() {
  queue queue;
  queue.size = 0;
  queue.top = NULL;
  queue.bot = NULL;
  string cmd;
  int a;
  cout << "Введите push a, чтобы добавить число а в конец очереди" << endl
  << "Введите pop, чтобы вытащить число из начала очереди" << endl
  << "Введите size, чтобы вывести длину очереди" << endl
  << "Введите empty, чтобы узнать, пуста ли очередь" << endl
  << "Введите pick, чтобы узнать, какой элемент находится в начале очереди" << endl
  << "Введите print, чтобы вывести всю очередь" << endl
  << "Введите exit, чтобы закончить работу прогаммы" << endl;
  cin >> cmd;
  while (cmd != "exit") {

    if (cmd == "push") {
      cin >> a;
      queue.push(a);
    }

    else if (cmd == "pop") {
      cout << queue.pop() << endl;
    }

    else if (cmd == "size") {
      cout << queue.size << endl;
    }

    else if (cmd == "empty") {
      if (queue.empty()) {
        cout << "Пуста" << endl;
      } else {
        cout << "Не пуста" << endl;
      }
    }

    else if (cmd == "pick") {
        cout << queue.pick() << endl;
    }

    else if (cmd == "print") {
        cout << queue.toString() << endl;
    }

    else {
      cout << "Введите одну из предложенных команд" << endl;
    }
    cin >> cmd;
  }
  cout << "Работа прогаммы завершена" << endl;
  return 0;
}
