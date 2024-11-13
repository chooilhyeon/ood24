#ifndef _LIST_H_
#define _List_H_


class List {
 public:
List();
List(List& list);
virtual ~List();
void operator=(List& list);
int size() const;
void PushBack(int elem);
void PushFront(int elem);
void PopBack();
void PopFront();
int& At(int index);
bool IsEmpty() const;
 private:
struct Elem {
int value;
Elem* next;
};
Elem* head;
int size_;
};

#endif  //  _LIST_H_
