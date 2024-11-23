#ifndef _LIST_H_
#define _LIST_H_

#include <cassert>
#include <cstddef>

template <typename T>
class List {
 public:
List() {
    size_ = 0;
    head = nullptr;
}

List(const List& list) {
    size_ = 0;
    head = nullptr;
    for (int i = 0; i < list.size_; i++) {
        PushBack(list.At(i));
    }
}

virtual ~List() {
    while (!IsEmpty()) {
        PopFront();
    }
}

void operator=(const List& list) {
    if (this == &list) {
        return;
    }

    while (!IsEmpty()) {
        PopFront();
    }

    for (int i = 0; i < list.size_; i++) {
        PushBack(list.At(i));
    }
}


int size() const {
    return size_;
}

void PushBack(T elem) {
    Elem* newElem = new Elem{elem, nullptr};
    if (IsEmpty()) {
        head = newElem;
    } else {
        Elem* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newElem;
    }
    size_++;
}

void PushFront(T elem) {
    Elem* newElem = new Elem{elem, head};
    head = newElem;
    size_++;
}

void PopBack() {
    assert(!IsEmpty() && "Out-of-bound");
    if (size_ == 1) {
        delete head;
        head = nullptr;
        size_--;
    } else {
        Elem* last = head;
        while (last->next->next != nullptr) {
            last = last->next;
        }
        delete last->next;
        last->next = nullptr;
        size_--;
    }
}

void PopFront() {
    assert(!IsEmpty() && "Out-of-bound");
    Elem* temp = head;
    head = head->next;
    delete temp;
    size_--;
}


T& At(int index) const {
    assert(index >= 0 && index < size_ && "Out-of-bound");
    Elem* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->value;
}

bool IsEmpty() const {
    return size_ == 0;
}

 private:
struct Elem {
T value;
Elem* next;
};
Elem* head;
int size_;
};

#endif  //  _LIST_H_
