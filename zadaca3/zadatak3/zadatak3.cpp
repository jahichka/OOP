#include <iostream>
#include <list>
#include <vector>
#include <functional>
using namespace std;

template<typename T>
list<int> partition (list<int>::const_iterator b,list<int>::const_iterator e, T predicate)
{
  list<int> brojevi;
  for(auto i=b;i!=e;i++)
  {
    try{
    if(predicate(*i))
      brojevi.push_front(*i);
    else
      brojevi.push_back(*i);
        }
    catch(int x) {
      brojevi.clear();
      for(auto i=b;i!=e;i++)
        brojevi.push_back(*i);
      break;
    }
  }
  return brojevi;
}

int main() {
list<int> nums{15,20,25,-10,-75,100,-255,430,200};

auto l=[](int num) { if(num>400) throw 5; return num > 0; };
//auto l=[](int num) { return !(num % 10); };
//auto l=[](int num) { return std::abs(num) > 99; };

auto result = partition(nums.cbegin(), nums.cend(),l);

for (auto num : result) {
cout << num << " ";
}
cout << endl;
return 0;
}
