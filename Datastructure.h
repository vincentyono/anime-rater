#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

template <typename T> class Datastructure {
public:
  virtual void append(T data) = 0;
  virtual T *search(T value) const = 0;
  virtual void sort() const = 0;
  virtual void printList() const = 0;
  virtual void remove(T value) = 0;
};

#endif