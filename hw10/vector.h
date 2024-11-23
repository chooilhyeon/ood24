#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cassert>
#include <cstddef>

template <typename T>
class Vector {
 public:
  explicit Vector(std::size_t capacity) {
    capacity_ = capacity;
    elements_ = new T[capacity_];
    size_ = 0;
  }

  Vector(const Vector& vector) {
    capacity_ = vector.capacity();
    elements_ = new T[vector.capacity()];
    size_ = vector.size();

    for (int i = 0 ; i < vector.size() ; i++) {
      elements_[i] = vector.elements_[i];
    }
  }

  virtual ~Vector() {
    delete[] elements_;
    elements_ = nullptr;
    capacity_ = 0;
    size_ = 0;
  }

  void operator=(const Vector& vector) {
    delete[] elements_;
    capacity_ = vector.capacity();
    elements_ = new T[vector.capacity()];
    size_ = vector.size();

    for (int i = 0 ; i < vector.size() ; i++) {
      elements_[i] = vector.elements_[i];
    }
  }

  T& operator[](const int index) {
    assert(index >= 0 && index < size_ && "Out-of-bound");
    return elements_[index];
  }

  int size() const {
    return size_;
  }

  int capacity() const {
    return capacity_;
  }

  void PushBack(T elem) {
    if (size_ == capacity_) {
      T* arr_ = new T[size_+4];
      for (int i = 0; i < size_; i++) {
        arr_[i] = elements_[i];
      }
      delete[] elements_;
      elements_ = arr_;
      capacity_ += 4;
    }
    elements_[size_] = elem;
    size_++;
  }

  void PopBack() {
    assert(!IsEmpty() && "Out-of-bound");
    size_--;
  }

  bool IsEmpty() const {
    return size_ == 0;
  }

 private:
  T* elements_;
  int capacity_;
  int size_;
};


#endif  //  _VECTOR_H_
