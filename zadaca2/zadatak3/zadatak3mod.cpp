#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool provjera(const vector<int> &v, const int &n) {
  bool b = true;
  if (!v.empty()) {
    for (auto &i : v) {
      if (i == n) b = false;
    }
  }
  return b;
}

void provjera_trougao(const int &broj) {
  string razmak = ", ";
  vector<int> v;
  for (int i = 1; i <= broj; i++) {
    for (int j = 1; j <= broj; j++) {
      int kvadrat = pow(i, 2) + pow(j, 2);
      int n = sqrt(kvadrat);
      if (kvadrat == pow(n, 2) && provjera(v, n)) {
        v.push_back(n);
        cout << "(" << i << razmak << j << razmak << n << ")" << endl;
      }
    }
  }
}

int main() {
  int broj;
  cout << "Unesite cijeli broj: ";
  cin >> broj;
  provjera_trougao(broj);
}
