#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main() {
  vector <string> rijeci;
  string rijec,najduza;
  int broj_karaktera=0;

  cout<<"Unesi rijec: ";
  while(cin>>rijec)
  {
    rijeci.push_back(rijec);
    cout<<"Unesi rijec: ";
  }
  cout<<endl;
  string linija(32,'=');
  cout<<linija<<"\nLista rijeci"<<endl;
  for(auto& i:rijeci)
  {
    cout<<i<<" ";
    broj_karaktera+=i.size();
    if(i.size()>najduza.size())
    {
      najduza=i;
    }
  }
  cout<<endl;
  cout<<"Ukupan broj karaktera: "<<broj_karaktera<<endl;
  cout<<linija<<"\nNajduza rijec"<<endl;

string plusici(najduza.size()+4,'+');
string pocetak="+ ";
string kraj=" +";
string prazna_mjesta(najduza.size(),' ');
string prazna=pocetak+prazna_mjesta+kraj;

cout<<plusici<<endl;
cout<<prazna<<endl;
cout<<pocetak<<najduza<<kraj<<endl;
cout<<prazna<<endl;
cout<<plusici<<endl;




}

