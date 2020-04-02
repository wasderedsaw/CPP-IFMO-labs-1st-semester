#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a = 0.0, b = 0.0, c = 0.0, x1 = 0.0, x2 = 0.0, dX = 0.0, f = 0.0;
    bool flag = true;
    cin >> a >> b >> c >> x1 >> x2 >> dX;
    if (dX == 0)
    {
      if (c < 0 && b != 0) {
        f = a * x1 * x1 + b * b * x1;
      } else if (c > 0 && b == 0) {
        f = (x1 + a) / (x1 + c);
      } else {
        f = x1 / c;
      }
      cout << x1 << ";" << f << endl;
      cout << "thats it" << endl;
      return 0;
    }
    while (c == 0) {
      cout << "с должно быть отлично от нуля" << endl;
      cin >> c;
    }
    flag = abs(x2 - x1) > abs(x2 - x1 - dX);
    if (flag) {
    for (int x = x1; x != x2; x = x + dX) {
      if (c < 0 && b != 0) {
        f = a * x * x + b * b * x;
      } else if (c > 0 && b == 0) {
        f = (x + a) / (x + c);
      } else {
        f = x / c;
      }
      cout << x << ";" << f << endl;
    }
  }
 else {
      cout << "wrong input!" << endl;
    }
    return 0;
}
