#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ispis(const vector <string> &rijeci, const int &najveci) {
  string plusici(najveci + 4, '+');
  string pocetak = "+ ";
  string kraj = " +";
  string prazna_mjesta(najveci, ' ');
  string prazno = pocetak + prazna_mjesta + kraj;
  cout<<endl;
  cout << plusici << endl;
  cout << prazno << endl;
  for (auto &i : rijeci) {
    string mjesta(najveci - i.size(), ' ');
    string linija = pocetak + i + mjesta + kraj;
    cout << linija << endl;
  }
  cout << prazno << endl;
  cout << plusici << endl;
}

void upis(vector<string> &rijeci, int &najveci) {
  string rijec;
  int i=0;
  cout << "Unesi rijec: ";
  while (cin >> rijec) {
    rijeci.push_back(rijec);
    if(rijeci.at(i).size()>najveci) najveci=rijeci.at(i).size();
    i++;
    cout << "Unesi rijec: ";
  
}
}

void sortiranje_vektora(vector <string> &rijeci)
{
  for(auto &i:rijeci)
    sort(i.begin(),i.end());
}

int main()
{
  vector <string> rijeci;
  int najveci=0;

  upis(rijeci, najveci);
  sort(rijeci.begin(),rijeci.end());
  sortiranje_vektora(rijeci);
  ispis(rijeci, najveci);
}
