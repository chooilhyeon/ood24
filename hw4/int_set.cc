#include "int_set.h"

IntSet::IntSet(int capacity) {
capacity_ = capacity;
elements_ = new int[capacity_];
size_ = 0;
}

IntSet::IntSet(const IntSet& int_set) {
capacity_ = int_set.capacity_;
elements_ = new int[int_set.capacity_];
size_ = int_set.size_;
}

int IntSet::capacity() const {
return capacity_;
}

int IntSet::size() const {
return size_;
}

int* IntSet::elements() const {
return elements_;
}

void IntSet::Add(int value) {
assert(size_ < capacity_ && "Exceeded capacity");
bool include = false;
for (int i = 0 ; i < size_ ; i++) {
int j = elements_[i];
if (j == value) {
include = true;
break;
}
}
if (include == false) {
elements_[size_] = value;
size_++;
}
}

void IntSet::Add(const IntSet& int_set) {
for (int i = 0 ; i < int_set.size_ ; i++) {
int j = int_set.elements_[i];
Add(j);
}
}

void IntSet::Map(std::function<int(int)> f) {
for (int i = 0 ; i < size_ ; i++) {
elements_[i] = f(elements_[i]);
}
}

bool IntSet::ForAll(std::function<bool(int)> f) {
for (int i = 0 ; i < size_ ; i++) {
bool present = f(elements_[i]);
if (present == false) return present;
}
return true;
}

