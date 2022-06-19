#ifndef ARRAY_H
#define ARRAY_H

template <typename T> class Array : public Datastructure {
private:
  T *array; // pointer to array
  int length;

public:
  Array();
  bool append(T data) override; // insert a new element to the end of the array
  T search(std::string value) const override;
  void sort() const override; // sort the array in ascending order
  int length() const override;
};

#include "Array.cpp"

#endif