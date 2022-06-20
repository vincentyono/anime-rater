#ifndef ARRAY_H
#define ARRAY_H

#include "Datastructure.h"

template <typename T> class Array : public Datastructure<T> {
private:
  T *array;    // pointer to array
  int _count;  // number of elements
  int MAXSIZE; // size of the array
  bool isEqual(std::string value) const;

public:
  Array();
  Array(int size);
  void append(T data) override; // insert a new element to the back of the array
  T *search(T value) const override;
  void sort() const override; // sort the array in ascending order
  int count();
  void printList() const override;
  void remove(T value);  // remove an element
  T at(int index) const; // access the element at index
};

#include "Array.cpp"

#endif