#include "Array.h"

template <typename T1, typename T2> Array<T1, T2>::Array() {
  this->array = new T1[100];
  this->_count = 0;
  this->MAXSIZE = 100;
}
template <typename T1, typename T2> Array<T1, T2>::Array(int size) {
  this->array = new T1[size];
  this->_count = 0;
  this->MAXSIZE = size;
}

template <typename T1, typename T2> void Array<T1, T2>::append(T1 data) {
  if (this->_count == this->MAXSIZE) { // if array is full
    T1 *newArray = new T1[this->MAXSIZE * 2];
    this->MAXSIZE = this->MAXSIZE * 2;
    for (int i = 0; i < this->_count; i++) {
      newArray[i] = this->array[i];
    }
  }

  this->array[this->_count] = data;
  this->_count++;
}

template <typename T1, typename T2> T1 *Array<T1, T2>::search(T2 value) const {
  for (int i = 0; i < this->_count; i++) {
    if (this->array[i] == value) {
      return &this->array[i];
    }
  }
  return nullptr;
}

template <typename T1, typename T2> void Array<T1, T2>::sort() const {}

template <typename T1, typename T2> void Array<T1, T2>::printList() const {
  for (int i = 0; i < this->_count; i++) {
    std::cout << this->array[i] << "\n";
  }
}

template <typename T1, typename T2> int Array<T1, T2>::count() {
  return this->_count;
}

template <typename T1, typename T2> void Array<T1, T2>::remove(T2 value) {
  int j = 0;
  for (int i = 0; i < this->_count; i++) { // find target index
    if (this->array[i] == value) {
      j = i;
      break;
    }
  }

  for (j; j <= this->_count; j++) {
    this->array[j] = this->array[j + 1];
  }
  this->_count--;
}
