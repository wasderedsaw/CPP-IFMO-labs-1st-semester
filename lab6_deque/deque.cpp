#include <iostream>

using namespace std;

struct node {
  int element;
  struct node* next;
  struct node* prev;
};

struct deque {
  int size;
  struct node* top;
  struct node* bot;

  bool empty() {
    return size == 0;
  }

  void push_top(int a) {
    struct node* next = new node();
    next->next = NULL;
    next->prev = NULL;
    next->element = a;
    if (size == 0) {
      bot = next;
    } else {
      next->prev = top;
      top->next = next;
    }
    top = next;
    size++;
  }

  void push_bot(int a) {
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

  int pick_top() {
    if (size == 0) {
      cout << "Попытка вытащить элемент из пустого дека, работа программы прекращена" << endl;
      exit(0);
      return 0;
    }
    return top->element;
  }

  int pick_bot() {
    if (size == 0) {
      cout << "Попытка вытащить элемент из пустого дека, работа программы прекращена" << endl;
      exit(0);
      return 0;
    }
    return bot->element;
  }

  int pop_top() {
    if (size == 0) {
      cout << "Попытка вытащить элемент из пустого дека, работа программы прекращена" << endl;
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

  int pop_bot() {
    if (size == 0) {
      cout << "Попытка вытащить элемент из пустого дека, работа программы прекращена" << endl;
      exit(0);
      return 0;
    }
    int answer = bot->element;
    struct node* next = bot->next;
    if (next == NULL) {
      top = NULL;
    } else {
    delete bot;
    next->prev = NULL;
    }
    bot = next;
    size--;
    return answer;
  }

  string toString() {
    if (size == 0) {
      return "[NULL]";
    }
    string result = "[NULL <--> ";
    struct node * curNode = bot;
    while (curNode != NULL) {
      result += to_string(curNode->element);
      result += " <--> ";
      curNode = curNode->next;
    }
    result += "NULL]";
    return result;
  }
};

int main() {
  deque deque;
  deque.size = 0;
  deque.top = NULL;
  deque.bot = NULL;
  string cmd;
  int a;
  cout << "Введите push_top a, чтобы добавить число a в верхнюю часть дека;" << endl
  << "Введите push_bot a, чтобы добавить число a в нижнюю часть дека;" << endl
  << "Введите pop_top, чтобы вытащить число из верхней части дека;" << endl
  << "Введите pop_bot, чтобы вытащить число из нижней части дека;" << endl
  << "Введите size, чтобы узнать размер дека;" << endl
  << "Введите empty, чтобы узнать, пуст ли дек;" << endl
  << "Введите pick_top, чтобы узнать значение верхнего элемента, не вытаскивая его из дека;" << endl
  << "Введите pick_bot, чтобы узнать значение нижнего элемента, не вытаскивая его из дека;" << endl
  << "Введите print, чтобы вывести весь дек(снизу вверх);" << endl
  << "Введите exit, чтобы закончить работу с деком;" << endl;
  cin >> cmd;
  while (cmd != "exit") {

    if (cmd == "push_top") {
      cin >> a;
      deque.push_top(a);
    }

    else if (cmd == "push_bot") {
        cin >> a;
        deque.push_bot(a);
    }

    else if (cmd == "pop_top") {
        cout << deque.pop_top() << endl;
    }

    else if (cmd == "pop_bot") {
        cout << deque.pop_bot() << endl;
    }

    else if (cmd == "size") {
        cout << deque.size << endl;
    }

    else if (cmd == "empty") {
        if (deque.empty()) {
          cout << "Пуст" << endl;
        } else {
          cout << "Не пуст" << endl;
        }
    }

    else if (cmd == "pick_top") {
        cout << deque.pick_top() << endl;
    }

    else if (cmd == "pick_bot") {
        cout << deque.pick_bot() << endl;
    }

    else if (cmd == "print") {
        cout << deque.toString() << endl;
    }

    else {
      cout << "Введите одну из предложенных команд" << endl;
    }
    cin >> cmd;
  }
  cout << "Работа программы завершена" << endl;
  return 0;
}
