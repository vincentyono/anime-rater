#ifndef ARRAY_H
#define ARRAY_H

#include "Datastructure.h"

template <typename T1, typename T2> class Array : public Datastructure<T1, T2> {
private:
  T1 *array;   // pointer to array
  int _count;  // number of elements
  int MAXSIZE; // capacity of the array

public:
  Array();
  Array(int size);
  void
  append(T1 data) override; // insert a new element to the back of the array
  T1 *search(T2 value) const override;
  void sort() const override; // sort the array in ascending order
  int count();
  void printList() const override;
  void remove(T2 value); // remove an element
};

#include "Array.cpp"

#endif