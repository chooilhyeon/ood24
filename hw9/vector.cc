#include "vector.h"


Vector::Vector(std::size_t capacity) {
capacity_ = capacity;
elements_ = new int[capacity_];
size_ = 0;
}

Vector::Vector(const Vector& vector) {
    capacity_ = vector.capacity();
  elements_ = new int[vector.capacity()];
size_ = vector.size();

for (int i = 0 ; i < vector.size() ; i++) {
elements_[i] = vector.elements_[i];
}
}

Vector::~Vector() {
    delete[] elements_;
    elements_ = nullptr;
    capacity_ = 0;
    size_ = 0;
}

void Vector::operator=(const Vector& vector) {
delete[] elements_;
capacity_ = vector.capacity();
elements_ = new int[vector.capacity()];
size_ = vector.size();

for (int i = 0 ; i < vector.size() ; i++) {
elements_[i] = vector.elements_[i];
}
}

int& Vector::operator[](const int index) {
    assert(index >= 0 && index < size_ && "Out-of-bound");
    return elements_[index];
}

int Vector::size() const {
return size_;
}

int Vector::capacity() const {
return capacity_;
}

void Vector::PushBack(int elem) {
if (size_ == capacity_) {
    int* arr_ = new int[size_+4];

    for (int i = 0 ; i < size_ ; i++) {
    arr_[i] = elements_[i];
}

capacity_ = capacity_ + 4;
delete[] elements_;
elements_ = arr_;
}

elements_[size_] = elem;
size_++;
}

void Vector::PopBack() {
    assert(size_ > 0 && "Out-of-bound");
    size_--;
}

bool Vector::IsEmpty() const {
if (size_ == 0) return true;
}
