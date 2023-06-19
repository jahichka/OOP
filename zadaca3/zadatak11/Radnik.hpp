#pragma once

#include <iostream>
struct Radnik{
  double plata=0;
  int godine=0;


 std::istream& ucitaj(std::istream &ulaz)
  {
    ulaz>>plata>>godine;
    return ulaz;
  }  
 
 Radnik(std::istream& ulaz)
  {
    ucitaj(ulaz);
  }

 std::ostream& ispisRadnika(std::ostream& izlaz)
 {
   izlaz<<plata<<" "<<godine<<"\n";
   return izlaz;
 }
};
