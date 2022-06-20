#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Datastructure.h"
#include "Node.h"

template <typename T> class LinkedList : public Datastructure {
private:
  Node<T> *head;

public:
  LinkedList();
  void append(T data) override;
  T *search(T value) const override;
  void sort() const override;
  void printList() const override;
  void remove(T value);
};

#include "LinkedList.cpp"

#endif