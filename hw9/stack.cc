#include "stack.h"

Stack::Stack(std::size_t capacity) : Vector(capacity) {}

Stack::Stack(const Stack& stack) : Vector(stack) {}

void Stack::operator=(const Stack& stack) {
    Vector::operator=(stack);
}

int Stack::size() const {
    return Vector::size();
}

int Stack::capacity() const {
    return Vector::capacity(); 
}

void Stack::Push(int elem) {
    Vector::PushBack(elem);
}

int Stack::Pop() {
    assert(!IsEmpty() && "Stack is empty");
    int value = Vector::At(size() - 1);
    Vector::PopBack();
    return value;
}

bool Stack::IsEmpty() const {
    return Vector::IsEmpty();
}
