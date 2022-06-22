#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

template <typename T1, typename T2> class Datastructure {
public:
  virtual void append(T1 data) = 0;
  virtual T1 *search(T2 value) const = 0;
  virtual void printList() const = 0;
  virtual void remove(T2 value) = 0;
  virtual std::string toString(std::string func(T1)) = 0;
};

#endif