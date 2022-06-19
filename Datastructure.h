#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

template <typename T> class Datastructure {
public:
  virtual bool append(T data) = 0;
  virtual T search(std::string value) const = 0;
  virtual void sort() const = 0;
  virtual int length() const = 0;
  virtual void printList() const = 0;
};

#endif