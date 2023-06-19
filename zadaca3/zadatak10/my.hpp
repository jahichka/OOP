#include <functional>
#include <iostream>

template <typename T>
void sort(T b, T e, std::function<bool(decltype(*b),decltype(*b))> f ) {
  while (b != e) {
    --e;
    for (auto i = b; i != e;) {
      auto j = i;
      if (!f(j, ++i)) {
        std::iter_swap(j, i);
      }
    }
  }
}

template <typename T>
void sort(T b, T e) {
  while (b != e) {
    --e;
    for (auto i = b; i != e;) {
      auto j = i;
      if (*j<(*++i)) {
        std::iter_swap(j, i);
      }
    }
  }
}

