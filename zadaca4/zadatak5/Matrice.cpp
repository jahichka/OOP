#include <iostream>

template <typename T>
class Matrica {
  private:
  size_t m_{0};
  size_t n_{0};
  T* p_{nullptr};

  public:
  Matrica(std::initializer_list<T> l) : m_{l[0]}, n_{l[1]}, p_{new T[m_ * n_]} {
    if (m_ * n_ == l.size() - 2) {
      std::copy(&l[2], end(l), p_);
    } else if (m_ * n_ < l.size() - 2) {
      std::copy(&l[2], end(l), p_);
      for (auto i = l.size() - 1; i != m_ * n_; ++i) {
        p_[i] = new T;
      }
    } else
      throw std::domain_error("dimenzije ne odgovaraju broju clanova");
  }

  Matrica(size_t m, size_t n) : m_{m}, n_{n}, p_{new T[m_ * n_]} {}

  Matrica(const Matrica& M) : m_{M.m_}, n_{M.n_}, p_{new T[m_ * n_]} {
    std::copy(M.p_ + 1, M.p_ + 1 + m_ * n_, p_);
  }

  Matrica(Matrica&& M) : m_{M.m_}, n_{M.n_}, p_{M.p_} {
    M.m_ = 0;
    M.n_ = 0;
    M.p_ = nullptr;
  }

  ~Matrica(){ delete []p_; }

  Matrica& operator=(const Matrica& M) {
    m_ = M.m_;
    n_ = M.n_;
    p_ = new T[m_ * n_];
    std::copy(M.p_ + 1, M.p_ + 1 + m_ * n_, p_);
  }

  Matrica& operator=(Matrica&& M) {
    m_ = M.m_;
    n_ = M.n_;
    p_ = M.p_;
    M.m_ = 0;
    M.n_ = 0;
    M.p_ = nullptr;
  }

  T& operator()(size_t m, size_t n)const{
    return p_[(m-1)*n_+n];
  }

 T& operator()(size_t m, size_t n){
    return p_[(m-1)*n_+n];
  }


};
