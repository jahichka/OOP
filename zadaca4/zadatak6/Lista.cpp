#include <iostream>

template <typename T>
struct Node {
  T data{0};
  T* next{nullptr};
  Node(const T element) : data{element}, next{nullptr} {}
};

template <typename T>
struct List {
  private:
  Node<T>* head_{nullptr};
  Node<T>* tail_{nullptr};
  size_t size_{0};
  void copyList(const List& l) {
    Node<T>* N = head_;
    Node<T>* temp = l.head_;
    N->data = temp->data;
    temp = temp->next;
    for (; temp != nullptr; temp = temp->next) {
      N->next = new Node<T>{temp->data};
      N = N->next;
    }
    N->next = nullptr;
    tail_ = N;
  }
  void dealoc() {
    for (auto temp = head_; temp != nullptr;) {
      auto N = temp->next;
      delete temp;
      temp = N;
    }
  };

  public:
  List() {}
  List(const List& l) : size_{l.size_} { copyList(l); }

  List(List&& l) : head_{l.head_}, tail_{l.tail_}, size_{l.size_} {
    l.head_ = nullptr;
    l.tail_ = nullptr;
    l.size_ = 0;
  }

  List& operator=(const List& l) {
    size_ = l.size_;
    copyList(l);
    return *this;
  }

  List& operator=(List&& l) {
    head_ = l.head_;
    tail_ = l.tail_;
    size_ = l.size_;
    l.head_ = nullptr;
    l.tail_ = nullptr;
    l.size_ = 0;
    return *this;
  }

  ~List() { dealoc(); }

  void push_back(T element) {
    tail_->next = new Node<T>{element};
    ++size_;
  }

  void push_front(T element) {
    Node<T>* temp = head_;
    head_ = new Node<T>{element, temp};
    ++size_;
  }

  void pop_back() {
    if (size_) {
      Node<T>* temp = head_;
      for (; temp->next != tail_; temp = temp->next)
        ;
      delete tail_;
      tail_ = temp;
      tail_->next = nullptr;
      --size_;
    } else
      throw std::logic_error("prazna lista");
  }

  void pop_front() {
    if (size_) {
      Node<T>* temp = head_->next;
      delete head_;
      head_ = temp;
    } else
      throw std::logic_error("prazna lista");
  }

  bool empty() const { return !size_; }

  size_t size() const { return size_; }

  List& extend(const List& l) {
    tail_->next = l.head_;
    tail_ = l.tail_;
  }

  bool operator==(const List& l) const {
    Node<T>* temp1 = head_;
    Node<T>* temp2 = l.head_;
    while (temp1 != nullptr) {
      if (temp1->data != temp2->data) return false;
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    return true;
  }

  bool operator!=(const List& l) const {
    Node<T>* temp1 = head_;
    Node<T>* temp2 = l.head_;
    while (temp1 != nullptr) {
      if (temp1->data == temp2->data) return false;
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    return true;
  }

  T& front() const {
    if (!empty()) {
      return head_->data;
    } else
      throw std::logic_error("prazna lista");
  }

  T& back() const {
    if (!empty()) {
      return tail_->data;
    } else
      throw std::logic_error("prazna lista");
  }
};
