#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>



struct Predmet {
std::string naziv;
std::string odsjek;
};
struct OcjenaIzPredmeta {
int ocjena;
std::list<Predmet>::const_iterator predmet;
};
struct Student {
  private:
std::string _brojIndeksa;
std::string _ime;
std::string _prezime;
std::string _grad;
std::vector<OcjenaIzPredmeta> _ocjene;

  public:
void unesi();
void promijeniIndeks(int);
void promijeniIme(std::string);
void promijeniPrezime(std::string);
void promijeniGrad(std::string);
void promijeniOcjenu(int);

};

