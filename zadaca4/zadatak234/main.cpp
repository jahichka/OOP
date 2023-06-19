#include <iostream>
#include <string>
#include "MojNizInt.cpp"

int main(void)
{
  MojNizInt<int> a{2.5,4.5,6.5};
  MojNizInt<std::string> b{a};
  MojNizInt<std::string> c{std::move(a)};
}
