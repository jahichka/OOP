#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void unos_vektora(vector<int> &v, long &broj) {
  while (broj) {
    int x = broj % 10;
    v.push_back(x);
    broj /= 10;
  }
}

void sortiranje_vektora(vector<int> &v) {
  auto kriterij = [](const int &a, const int &b) { return a > b; };

  sort(v.begin(), v.end(), kriterij);
}

void ispis_vektora(const vector<int> &v) {
  for (auto &i : v) cout << i;
  cout << endl;
}

void ispis_max_min(const vector<int> &v) {
  cout << "Najveca cifra je: " << v.front() << ", a najmanja: " << v.back()
       << endl;
}

void suma_zbir(const vector<int> &v) {
  long suma = 0, proizvod = 1;
  for (auto &i : v) {
    suma += i;
    proizvod *= i;
  }
  cout << suma << endl;
  cout << proizvod << endl;
}

int main() {
  vector<int> cifre;
  long broj;
  cout << "Unesite cijeli broj: ";
  cin >> broj;
  unos_vektora(cifre, broj);
  sortiranje_vektora(cifre);
  ispis_vektora(cifre);
  ispis_max_min(cifre);
  suma_zbir(cifre);
}
