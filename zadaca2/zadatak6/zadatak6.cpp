#include <cmath>
#include <iostream>
#include <string>

using namespace std;

double kalkulator(int &x, int &y, char &c) {
  if (c == '+')
    return x + y;
  else if (c == '-')
    return x - y;
  else if (c == '*')
    return x * y;
  else if (c == '%')
    return x % y;
  else if (c == '^')
    return pow(x, y);
  else if (c == '/') {
    if (y == 0) {
      cout << "Dijeljenje sa nulom nije moguce" << endl;
      exit(1);
    }

    else
      return (double)x / y;
  }

  else {
    cout << c << " nije operacija kalkultora" << endl;
    exit(1);
  }
}

bool provjera_broj(const string &s) {
  auto i = s.begin();
  int brojac = 0;
  bool minus;
  if (s.at(0) == '-') minus = true;
  while (i != s.end() && isdigit(s.at(brojac)) && minus) {
    ++i;
    ++brojac;
  }
  return !s.empty() && i == s.end();
}

void unos(const string &a, int &x, const string &b, int &y) {
  x = 0, y = 0;
  if (!provjera_broj(a) && provjera_broj(b)) {
    cout << "' " << a << " ' nije broj" << endl;
    exit(1);
  } else if (provjera_broj(a) && !provjera_broj(b)) {
    cout << "' " << b << " ' nije broj" << endl;
    exit(1);
  } else if (!provjera_broj(a) && !provjera_broj(b)) {
    cout << "' " << a << " ' i ' " << b << " ' nisu brojevi" << endl;
    exit(1);
  } else {
    for (int i = 0; i < a.size(); i++) {
      x += (a.at(i) - 48) * pow(10, a.size() - 1 - i);
      y += (b.at(i) - 48) * pow(10, b.size() - 1 - i);
    }
  }
}

int main() {
  int x, y;
  string a, b;
  char operacija;
  cin >> a >> operacija >> b;
  unos(a, x, b, y);
  cout << kalkulator(x, y, operacija) << endl;
}
