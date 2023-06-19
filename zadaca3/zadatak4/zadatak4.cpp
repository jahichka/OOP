/*napisati funkciju koja prima std::vector<int> kao prvi argument, te vektor funkcija koje će biti
primijenjene nad svakim elementom u vektoru. Ukoliko element ne zadovolji kriterije svih predicate
funkcija, u tom slučaju taj element zamijeniti sa defaultnim trećim argumentom kojeg funkcija prima
koji ima vrijednost -1. Ukoliko bilo koja predicate funkcija vrati false, taj element zamijeniti sa
defaultnim argumentom.
Funkcija ima sljedeci potpis:
typedef std::vector<std::function<bool(int)>> Funkcije;
void default_if_not_all(std::vector<int>&, Funkcije, int def=-1);*/

#include <iostream>
#include <vector>
#include<functional>
using namespace std;

typedef std::vector<std::function<bool(int)>> Funkcije;
void default_if_not_all(std::vector<int>&v, Funkcije f, int def=-1){
  for(auto i=v.begin();i!=v.end();i++) 
  {
    for(auto& j:f)
    {
      if(!j(*i)) { 
        *i=def;
        break;
      }
    }
  }
}

int main(void)
{ 
  return 0;
}
