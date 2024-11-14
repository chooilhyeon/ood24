#include "queue.h"

Queue::Queue() : List() {}

Queue::Queue(const Queue& queue) : List(queue) {}

void Queue::operator=(const Queue& queue) {
List::operator=(queue);
}

int Queue::size() const {
return List::size();
}

void Queue::Add(int elem) {
List::PushBack(elem);
}

int Queue::Poll() {
assert(!IsEmpty() && "Out-of-bound");
int value = List::At(0);
List::PopFront();
return value;
}

bool Queue::IsEmpty() const {
return List::IsEmpty();
}
