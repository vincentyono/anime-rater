#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Datastructure.h"
#include "Node.h"

template <typename T1, typename T2>
class LinkedList : public Datastructure<T1, T2> {
private:
  Node<T1> *head;

public:
  LinkedList();
  void append(T1 data) override;
  T1 *search(T2 value) const override;
  void printList() const override;
  void remove(T2 value);
  std::string toString(std::string func(T1)) override;
};

#include "LinkedList.cpp"

#endif
