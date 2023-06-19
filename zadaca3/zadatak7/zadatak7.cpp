/*Napisati funkciju reduce koja uzima listu integer-a kao prvi argument,
funkciju koju će koristiti da elemente kontejnera svede na jedan element te
početnu vrijednost date akumulacije. Reduce treba da elemente proslijeđenog
kontejnera svede na 1 element koristeći funkciju koja je proslijeđena kao
argument. Kako treba da izgleda tip drugog argumenta funkcije reduce?
Primjer:
Input list: [11, 4, 5, 12, 6, 8, 9]
Funkcija: [](int a, int b) { return a + b + 1; }
Start: -12
Output: 50
Nakon implementacije funkcije reduce za listu integer-a, odraditi implementaciju
i za listu proizvoljnog tipa podataka te implementaciju za proizvoljan tip
kontejnera.*/

#include <functional>
#include <iostream>
#include <list>

template <typename U, typename T>
U reduce(T b, T e, U r, std::function<U(U, U)> f) {
  for (auto i = b; i != e; ++i) {
    r = f(r, *i);
  }
  return r;
}

int main(void) {
  std::list<int> l{11, 4, 5, 12, 6, 8, 9};
  std::function<int(int, int)> f = [](int a, int b) { return a + b + 1; };
  std::cout<<reduce(l.begin(),l.end(),-12,f)<<std::endl;
  return 0;
}
