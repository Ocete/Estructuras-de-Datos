
#ifndef _QUEUE_H_
#define _QUEUE_H_

template <class T>
class queue {
  struct Node {
    Node * next;
    T data;
  };
private:
  Node * top;
  Node * tail;
public:
  queue();
  ~queue();
  void add(T data);
  T peak();
  T remove();
  bool isEmpty();
};

#include "../src/queue.cpp"
#endif
