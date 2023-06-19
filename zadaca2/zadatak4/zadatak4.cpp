#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  int hamming_distance = 0;
  do {
    cout << "Unesite prvu rijec: ";
    cin >> a;
    cout << "Unesite drugu rijec: ";
    cin >> b;
    if (a.size() != b.size())
      cout << "Rijeci moraju biti iste duzine. Unesite ponovno." << endl;

  } while (a.size() != b.size());

  for (int i = 0; i < a.size(); i++) {
    if (a.at(i) != b.at(i)) hamming_distance++;
  }
  cout << "Hammingova udaljenost iznosi: " << hamming_distance << endl;

  return 0;
}
