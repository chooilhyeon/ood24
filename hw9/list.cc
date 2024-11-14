#include "list.h"

List::List() {
    size_ = 0;
    head = nullptr;
}

List::List(List& list) {
    size_ = 0;
    head = nullptr;
    for (int i = 0; i < list.size_; i++) {
        PushBack(list.At(i));
    }
}

List::~List() {
    while (!IsEmpty()) {
        PopFront();
    }
}

void List::operator=(List& list) {
    while (!IsEmpty()) {
        PopFront();
    }
    
    for (int i = 0; i < list.size_; i++) {
        PushBack(list.At(i));
    }
}

int List::size() const {
    return size_;
}

int& List::At(int index) {
    assert(index >= 0 && index < size_ && "Out-of-bound");
    
    if (index == 0) {
        return head->value;
    }
    return At(index).value;
}

bool List::IsEmpty() const {
    return size_ == 0;
}

void List::PushBack(int elem) {
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

void List::PushFront(int elem) {
    Elem* newElem = new Elem{elem, head};
    head = newElem;
    size_++;
}

void List::PopBack() {
    assert(!IsEmpty() && "Out-of_bound");
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

void List::PopFront() {
    assert(!IsEmpty() && "Out-of_bound");
    Elem* temp = head;
    head = head->next;
    delete temp;
    size_--;
}
