#pragma once
#include <iostream>

template <typename T>
class MojNizInt {
  private:
  size_t n_{0};
  size_t c_{0};
  T* p_{nullptr};

  public:
  MojNizInt() : c_{1}, p_{new T[c_]} {}
  size_t size() const { return n_; }

  int& at(const size_t i) const {
    if (i < n_)
      return p_[i];
    else
      throw std::invalid_argument("Van opsega");
  }

  int& at(const size_t i) {
    if (i < n_)
      return p_[i];
    else
      throw std::invalid_argument("Van opsega");
  }

  MojNizInt (std::initializer_list<T> a)
      : n_{a.size()}, c_{a.size()}, p_{new T[c_]} {
    std::copy(std::begin(a), std::end(a), p_);
  }
  MojNizInt(const MojNizInt<T>& a) : n_{a.n_}, c_{2 * n_}, p_{new T[c_]} {
    std::copy(a.p_, a.p_ + n_, p_);
  }
  
  template<typename M>
  MojNizInt<T>(const MojNizInt<M>& a) : n_{a.n_}, c_{2 * n_}, p_{new T[c_]} {
    std::copy(a.p_, a.p_ + n_, p_);
  }

  MojNizInt(MojNizInt&& a) : n_{a.n_}, c_{n_}, p_{a.p_} {
    a.p_ = nullptr;
    a.n_ = 0;
  }

  MojNizInt& operator=(const MojNizInt& a) {
    n_ = a.n_;
    c_ = 2 * n_;
    p_ = new T[c_];
    std::copy(a.p_, a.p_ + n_, p_);
    return *this;
  }

  MojNizInt& operator=(MojNizInt&& a) {
    n_ = a.n_;
    c_ = n_;
    p_ = a.p_;
    a.p_ = nullptr;
    a.n_ = 0;
    return *this;
  }

  ~MojNizInt() { delete[] p_; }

  int& operator[](const size_t i) const { return p_[i]; }
  int& operator[](const size_t i) { return p_[i]; }

  int* begin() { return p_; }
  int* end() { return p_ + n_; }

  MojNizInt operator*(int k) const {
    MojNizInt a{*this};
    std::copy(p_, p_ + n_, a.p_);
    for (auto i = 0; i < a.size(); ++i) {
      a[i] *= k;
    }
    return a;
  }

  MojNizInt operator+(const MojNizInt& a) const {
    if (a.size() != size())
      throw std::invalid_argument("Dimenzije se ne poklapaju");
    else {
      MojNizInt n{*this};
      for (auto i = 0; i < size(); ++i) {
        n[i] += a[i];
      }
      return n;
    }
  }

  MojNizInt operator++(int) {
    MojNizInt n{*this};
    for (auto i = 0; i < n_; ++i) {
      ++p_[i];
    }
    return n;
  }

  MojNizInt& operator++() {
    for (auto i = 0; i < n_; ++i) {
      ++p_[i];
    }
    return *this;
  }

  /*void push_back(const int i){
    int *ptr=new int[n_+1];
    std::copy(p_,p_+n_,ptr);
    ptr[n_]=i;
    delete []p_;
    p_=ptr;
    ++n_;
  }*/

  void push_back(const int& i) {
    if (n_ < c_) {
      p_[n_] = i;
      ++n_;
    } else {
      c_ = 2 * n_;
      int* ptr = new T[2 * n_];
      std::copy(p_, p_ + n_, ptr);
      ptr[n_] = i;
      delete[] p_;
      p_ = ptr;
      ++n_;
    }
  }

  void pop_back() {
    --n_;
  }

  int& front() { return p_[0]; }
  int& back() { return p_[n_-1]; }



};
