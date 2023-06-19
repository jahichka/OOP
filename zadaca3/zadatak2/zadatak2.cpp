/*Napisati poboljšanu verziju prethodne funkcije takvu da osim iteratora na std::list uzima i
predicate funkciju kao argument (std::function<bool(int)> iz functional
zaglavlja). Funkcija treba da poziva predicate nad svakim članom ulaznog argumenta, te ukoliko
je rezultat predicate poziva tačan, član treba da se nalazi na lijevoj strani, odnosno ukoliko je
netačan na desnoj strani rezultujuće kolekcije.*/

#include <iostream>
#include <list>
#include <vector>
#include <functional>
using namespace std;

list<int> partition (list<int>::const_iterator b,list<int>::const_iterator e, function<bool(int)> predicate)
{
  list<int> brojevi;
  for(auto i=b;i!=e;i++)
  {
    if(predicate(*i))
      brojevi.push_front(*i);
    else
      brojevi.push_back(*i);
  }
  return brojevi;
}

int main() {
list<int> nums{15,20,25,-10,-75,100,-255,430,200};

//auto l=[](int num) { return num > 0; };
//auto l=[](int num) { return !(num % 10); };
auto l=[](int num) { return std::abs(num) > 99; };

auto result = partition(nums.cbegin(), nums.cend(),l);

for (auto num : result) {
cout << num << " ";
}
cout << endl;
return 0;
}

