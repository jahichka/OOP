/*Napisati generičku funkciju jednako koja poredi sekvence [od1, do1) i [od2, do2), pri čemu se
pretpostavlja da sekvence imaju isti broj elemenata. Funkcija vraća vrijednost true ukoliko su svi
elementi obje sekvence isti, u suprotnom vraća netačnu vrijednost. Funkcija uzima tri parametra - prva
dva označavaju početak i kraj prve sekvence, a treći parametar označava početak druge sekvence.
Napomena: iteratori koji operiraju na sekvencama mogu biti različitog tipa.
Koristeći funkciju jednako, napisati program koji učitava riječi koje korisnik unosi sa tastature i
ispisuje svaku riječ koju identificira kao palindrom. Palindrom je riječ koja ima isto značenje bez
obzira da li se čita sa lijeva na desno ili obrnuto. Primjer pozivanja programa se nalazi na linku.*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template<typename T, typename U>
bool jednako (T b, T e, U r)
{
  for(auto i=b;i!=e;++i, ++r)
  {
    if(*i!=*r) return false;
  }
  return true;
}

int main(void)
{
  string rijec="macejedejecam";
  string obrnuto;
  reverse_copy(rijec.begin(),rijec.end(),obrnuto.begin());
  if(jednako(rijec.begin(),rijec.end(),obrnuto.end()))
    cout<<"palindrom"<<endl;
  else cout<<"nije palindrom"<<endl;
  return 0;
}
