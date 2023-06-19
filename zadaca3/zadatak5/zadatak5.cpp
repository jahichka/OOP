/*Napisati funkciju filter koja uzima listu integer-a kao prvi argument i predicate funkciju kao drugi
argument. Filter treba nazad da vrati novu instancu liste integer-a koja sadrži sve elemente
proslijeđene liste (prvi argument) koji zadovoljavaju datu predicate funkciju. Kako treba da izgleda tip
drugog argumenta funkcije filter?

Input list: [1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10];
Predicate: [](int n) { return n % 2 == 0; }
Output: [8, 4, 0, 2, 6, 10]
Nakon implementacije funkcije filter za listu integer-a, odraditi implementaciju i za listu
proizvoljnog tipa podataka te implementaciju za proizvoljan tip kontejnera.*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

template<typename T, typename F>
T filter(T l, F f)
{
  T L;
  for(auto i:l)
  {
    if(f(i)) L.push_back(i);
  }
  return L;
}

int main()
{
 vector<int> l{1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10};
 auto p =[](int n) { return n % 2 == 0; };
 vector<int> L(filter(l,p));
 for(auto i:L)
   cout<<i<<" ";
 cout<<endl;
  return 0;
}
