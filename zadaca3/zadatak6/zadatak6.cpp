/*Napisati funkciju map koja uzima listu integer-a kao prvi argument te funkciju transformacije kao
drugi argument. Map treba nazad da vrati novi instancu liste integer-a koja sadrži elemente
proslijeđene liste transformirane kroz predicate funkciju. Kako treba da izgleda tip drugog argumenta
funkcije map?
Primjer:
Input list: [7, 2, -4, 5, 0, 6, 3]
Funkcija: [](int n) { return n * 2 + 1; }
Output: [15, 5, -7, 11, 1, 13, 7]

Nakon implementacije funkcije map za listu integer-a, odraditi implementaciju i za listu proizvoljnog
tipa podataka te implementaciju za proizvoljan tip kontejnera.*/

#include <iostream>
#include <list>
#include <vector>

template <typename T,typename U>
T Map (T input, U f)
{
  T output;
  for(auto i:input)
    output.push_back(f(i));
  return output;
}

int main(void)
{
  std::vector<int>v{7, 2, -4, 5, 0, 6, 3};
  auto l = [](int n) { return n * 2 + 1; };
  std::vector<int>t (Map(v,l));
  for(auto i:t)
    std::cout<<i<<" ";
  std::cout<<std::endl;
  return 0;
}
