#include "queue.h"

Queue::Queue() : List() {}

Queue::Queue(Queue& queue) : List(queue) {}

void Queue::operator=(Queue& queue) {
	List::operator=(queue);
}

int Queue::size() const {
	return List::size();
}

void Queue::Add(int elem) {
	List::PushBack(elem);
}

int Queue::Poll() {
	assert(!IsEmpty() && "Queue is empty");
	int value = List::Front();
	List::PopFront();
	return value;
}

bool Queue::IsEmpty() const {
	return List::IsEmpty();
}
