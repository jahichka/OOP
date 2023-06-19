#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

bool provjera_ponavljanja(const int &broj, const vector<int> &v) {
  bool b = true;
  if (v.empty())
    return true;
  else {
    for (auto &i : v) {
      if (i == broj) {
        b = false;
      }
    }
    return b;
  }
}

void ukupno(const int &ukupan_broj_kuglica, vector<int> &v) {
  int x;
  for (int i = 0; i < ukupan_broj_kuglica; i++) {
    do {
      x = rand() % 99;
    } while (!provjera_ponavljanja(x, v));
    v.push_back(x);
  }
}

void izvlacenje(const int &broj_kuglica_za_izvlacenje, const vector<int> &v1,
                vector<int> &v2) {
  int broj, x;
  for (int i = 0; i < broj_kuglica_za_izvlacenje; i++) {
    do {
      x = rand() % v1.size();
      broj = v1.at(x);
    } while (!provjera_ponavljanja(broj, v2));
    v2.push_back(broj);
  }
}
void ispis(const vector<int> &v1, const vector<int> &v2) {
  cout << "Izvuceno\tSortirano" << endl;
  string crtice(32, '-');
  cout << crtice << endl;
  for (int i = 0; i < v1.size(); i++) {
    cout << v1.at(i) << "\t\t" << v2.at(i) << endl;
  }
}

int main() {
  srand(time(NULL));
  vector<int> kuglice, izvuceno, sortirano;
  int ukupan_broj_kuglica, broj_kuglica_za_izvlacenje;
  cout << "Unesite ukupan broj kuglica: ";
  cin >> ukupan_broj_kuglica;
  cout << "Unesite broj kuglica za izvlacenje: ";
  cin >> broj_kuglica_za_izvlacenje;
  ukupno(ukupan_broj_kuglica, kuglice);
  izvlacenje(broj_kuglica_za_izvlacenje, kuglice, izvuceno);
  sortirano.assign(izvuceno.begin(), izvuceno.end());

  auto kriterij1 = [](const int &a, const int &b) {
    if ((a % 2) && (!(b % 2)))
      return false;
    else
      return true;
  };
  sort(sortirano.begin(), sortirano.end(), kriterij1);

  int n;
  for (int i = 0; i < sortirano.size(); i++) {
    if (sortirano.at(i) % 2 == 1) {
      n = i;
      break;
    }
  }
  auto kriterij2 = [](const int &a, const int &b) { return a > b; };

   sort(sortirano.begin(), sortirano.begin() + n, kriterij2);
  sort(sortirano.begin() + n, sortirano.end(), kriterij2);
  ispis(izvuceno, sortirano);
}
