#include <iostream>
#include "LongNumber.hpp"
class LongNumber {
  public:
  LongNumber(){}
  LongNumber(const LongNumber& l) : number_{l.number_} {}
  LongNumber(LongNumber&& l) : number_{std::move(l.number_)} {}
  explicit LongNumber(const long long& l) : number_{l} {}
  explicit LongNumber(const long long&& l) : number_{l} {}

  LongNumber& operator=(const LongNumber& l) {
    number_ = l.number_;
    return *this;
  }

  LongNumber& operator=(LongNumber&& l) {
    number_ = std::move(l.number_);
    return *this;
  }

  LongNumber operator+(const LongNumber& l) const{
    return (LongNumber)(number_+l.number_);
  }

  LongNumber operator-(const LongNumber& l) const{
    return (LongNumber)(number_-l.number_);
  }

  LongNumber operator*(const LongNumber& l) const{
    return (LongNumber)(number_*l.number_);
  }

   LongNumber operator/(const LongNumber& l) const{
     try{
    if (l.number_)return (LongNumber)(number_/l.number_);
    else throw std::logic_error("Dijeljenje s nulom nije moguce");
     }
     catch (std::logic_error){}
  }

   LongNumber& operator+=(const LongNumber& l){
     number_+=l.number_;
     return *this;
   }

  LongNumber& operator-=(const LongNumber& l){
     number_-=l.number_;
     return *this;
   }

  LongNumber& operator*=(const LongNumber& l){
     number_*=l.number_;
     return *this;
   }

 LongNumber& operator/=(const LongNumber& l){
      try{
    if (l.number_){number_/=l.number_;}
    else throw std::logic_error("Dijeljenje s nulom nije moguce");
     }
     catch (std::logic_error){}

     return *this;
   }

 LongNumber& operator=(const long long& l){
   number_=l;
   return *this;
 }

 LongNumber& operator=(long long&& l){
   number_=std::move(l);
   return *this;
 }

LongNumber operator+(const long long& l) const{
    return (LongNumber)(number_+l);
  }

  LongNumber operator-(const long long& l) const{
    return (LongNumber)(number_-l);
  }

  LongNumber operator*(const long long& l) const{
    return (LongNumber)(number_*l);
  }

   LongNumber operator/(const long long& l) const{
     try{
    if (l)return (LongNumber)(number_/l);
    else throw std::logic_error("Dijeljenje s nulom nije moguce");
     }
     catch (std::logic_error){}
  }

   LongNumber& operator+=(const long long& l){
     number_+=l;
     return *this;
   }

  LongNumber& operator-=(const long long& l){
     number_-=l;
     return *this;
   }

  LongNumber& operator*=(const long long& l){
     number_*=l;
     return *this;
   }

 LongNumber& operator/=(const long long & l){
      try{
    if (l){number_/=l;}
    else throw std::logic_error("Dijeljenje s nulom nije moguce");
     }
     catch (std::logic_error){}

     return *this;
   }

 inline bool operator==(const LongNumber& l) const{
   return number_==l.number_;
 }

 inline bool operator!=(const LongNumber& l) const{
   return number_!=l.number_;
 }

 inline bool operator>(const LongNumber& l) const{
   return number_>l.number_;
 }

 inline bool operator<(const LongNumber& l) const{
   return number_<l.number_;
 }

 inline bool operator>=(const LongNumber& l) const{
   return number_>=l.number_;
 }

 inline bool operator<=(const LongNumber& l) const{
   return number_<=l.number_;
 }

 inline bool operator==(const long long& l) const{
   return number_==l;
 }

 inline bool operator!=(const long long& l) const{
   return number_!=l;
 }

 inline bool operator>(const long long& l) const{
   return number_>l;
 }

 inline bool operator<(const long long& l) const{
   return number_<l;
 }

 inline bool operator>=(const long long& l) const{
   return number_>=l;
 }

 inline bool operator<=(const long long& l) const{
   return number_<=l;
 }

 LongNumber operator^(short k) const
 {
   LongNumber l{1};
   for(int i=0;i<k;++i)
   {
     l.number_*=number_;
   }
   return l;
 }

 operator bool() const{
   return number_;
 }

 LongNumber& operator++(){
   ++number_;
   return *this;
 }
LongNumber operator++(int){
LongNumber l=*this;
++l.number_;
return l;
}

 LongNumber& operator--(){
   --number_;
   return *this;
 }

LongNumber operator--(int){
LongNumber l=*this;
--l.number_;
return l;
}

LongNumber abs() const{
  LongNumber l{*this};
  if(l.number_<0) 
    l.number_*=-1; 
    return l;
}

bool isOdd() const{
  bool b=true;
  if(b%2==0) b=false;
  return b;
}

bool isEven() const{
  bool b=true;
  if(b%2==1) b=false;
  return b;
}

bool isPositive() const{
  bool b=true;
  if(number_<0) b=false;
  return b;
}

bool isNegative() const{
  bool b=true;
  if(number_<0) b=false;
  return b;
}

const long long& value() const { return number_; }

long long& num(){ return number_; }

private:
long long number_{0};
};
std::ostream& operator<<(std::ostream& output, const LongNumber& l)
{
  output<<l.value();
  return output;
}
std::istream& operator>>(std::istream& input, LongNumber& l){
  input>>l.num();
  return input;
}
