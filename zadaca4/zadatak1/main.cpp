#include <iostream>
#include "LongNumber.hpp"
#include "LongNumber.cpp"
int main(void)
{
  LongNumber a{5};
  LongNumber b{6};
  LongNumber c{2};
  a+=b;
  std::cout<<a<<std::endl;
  std::cout<<(a==b)<<std::endl;
  a=20;
  std::cout<<a<<std::endl;
  std::cout<<a*(LongNumber)15<<std::endl;
  a*=300;
  std::cout<<a<<std::endl;
  std::cout<<(a>=b)<<std::endl;
  if(c) std::cout<<++b<<std::endl;
  std::cout<<b.isOdd()<<std::endl;
  LongNumber d;
  std::cin>>d;
  std::cout<<d<<std::endl;
  return 0;
}
