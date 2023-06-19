#include<iostream>

template <typename T>
struct matrica{

  private: 
    size_t m_{0};
    size_t n_{0};
    T* ptr_{nullptr};

  public:
  matrica(){}

  matrica(size_t m, size_t n): m_{m}, n_{n}, ptr_{new T[m_*n_]}{}

  matrica(std::initializer_list<T> l): m_{l[0]}, n_{l[1]}, ptr_{new T[m_*n_]} {
    if(l.size()-2>m_*n_) {
      throw std::domain_error("");
    }
    else if(l.size()-2<=m_*n_)
    {
      std::copy(begin(l)+2,end(l),ptr_);
    }
  }

  matrica(const matrica& m): m_{m.m_}, n_{m.n_}, ptr_{new T[m_*n_]}{
    std::copy(m.ptr_, m.ptr_+m_*n_,ptr_);
  };

  matrica(matrica&& m): m_{m.m_}, n_{m.n_}, ptr_{m.ptr_}{
    m.ptr_=nullptr;
  }

  T& operator[](size_t m, size_t n){
    return ptr_[i:];
  }

  matrica& operator+(const matrica& m){
    matrica n{*this};
    for(auto i=0;i<m_*n_;++i){
      n[i]+=m[i];
    }
    return n;
  }



};
