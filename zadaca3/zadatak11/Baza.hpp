#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Radnik.hpp"

struct BazaRadnika
{
  std::map<std::string, Radnik> Baza;

  BazaRadnika() {Baza.clear();};

  std::istream& ucitaj(std::istream &unos)
  {
    while(unos){
    std::string kljuc;
    unos>>kljuc;
    auto it=Baza.find(kljuc);
    try{
      if(it!=Baza.end())
        throw std::domain_error("");
      else {
        Radnik r(unos);
        Baza.insert({kljuc,r});
      }
    }
    catch (const std::exception& a) {std::cout<<"radnik postoji"<<std::endl;
    unos.ignore(1000,'\n');
    }
    }
    return unos;
  }

  bool izbrisi_radnika(std::string kljuc)
  {
    return Baza.erase(kljuc);
  }

  std::ostream& ispis(std::ostream& izlaz)
  {
    for(auto const &i:Baza)
    {
      izlaz<<i.first<<" "<<i.second.plata<<" "<<i.second.godine<<"\n";
    }
    return izlaz;
  }

  double prosjek_plata()
  {
    double suma=0;
    for(auto const& i:Baza)
      suma+=i.second.plata;
    return suma/Baza.size();
  }

  double prosjek_godina()
  {
    double godine=0;
   for(auto const& i:Baza)
      godine+=i.second.godine;
    return godine/Baza.size();

  }
};
