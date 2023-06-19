/*Napisati funkciju parni_neparni koja uzima dva iteratora na početak i kraj kontejnera
std::list<int> kao argumente te nazad vraća novi std::list<int> kontejner takav da su
svi parni članovi na lijevoj strani, a svi neparni na desnoj strani kolekcije. Funkcija ne treba
modifikovati elemente proslijeđene kolekcije na koje iteratori pokazuju.
Kako treba izgledati potpis funkcije? Zašto?
A. std::list<int> parni_neparni(std::list<int>::iterator,
std::list<int>::iterator);
B. std::list<int> parni_neparni(std::list<int>::const_iterator,
std::list<int>::const_iterator);*/

#include <iostream>
#include <list>
#include <vector>
#include <functional>
using namespace std;

list<int> parni_neparni (list<int>::const_iterator b,list<int>::const_iterator e)
{
  list<int> brojevi;
  for(auto i=b;i!=e;i++)
  {
    if(*i%2==0)
      brojevi.push_front(*i);
    else
      brojevi.push_back(*i);
  }
  return brojevi;
}

int main(void)
{
  list<int> lista{1,2,3,4,5,6};
  list<int> l{parni_neparni(lista.begin(),lista.end())};
  for(auto &i:l)
    cout<<i<<endl;
  return 0;
}

