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
  if (this->_count + 1 >= this->MAXSIZE) {
    T1 *newArray = new T1[this->MAXSIZE * 2];
    for (int i = 0; i < this->_count; i++) {
      if (this->array[i] >= data) {
        newArray[i] = data;
        this->_count++;
      } else {
        newArray[i] = this->array[i];
      }
    }
    delete[] this->array;
    this->array = newArray;
  }

  if (this->_count == 0) {
    this->array[0] = data;
    this->_count++;
    return;
  }
  for (int i = this->_count - 1; i >= 0; i--) {
    if (this->array[i] >= data) {
      this->array[i + 1] = this->array[i];
      this->array[i] = data;
    } else if (data > this->array[i]) {
      this->array[i + 1] = data;
      this->_count++;
      return;
    }
  }
  this->_count++;
}

template <typename T1, typename T2>
T1 *Array<T1, T2>::search(
    T2 value) const { // linear search time complexity = O(n)
  for (int i = 0; i < this->_count; i++) {
    if (this->array[i] == value) {
      return &this->array[i];
    }
  }
  return nullptr;
}

template <typename T1, typename T2>
void Array<T1, T2>::printList() const { // time complexity = O(n)
  for (int i = 0; i < this->_count; i++) {
    std::cout << this->array[i] << "\n";
  }
}

template <typename T1, typename T2> int Array<T1, T2>::count() {
  return this->_count;
}

template <typename T1, typename T2>
void Array<T1, T2>::remove(T2 value) { // time complexity = O(n)
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

template <typename T1, typename T2>
std::string Array<T1, T2>::toString(std::string func(T1)) {
  std::string str;
  for (int i = 0; i < this->_count; i++) {
    str += func(this->array[i]);
  }
  return str;
}

template <typename T1, typename T2> T1 Array<T1, T2>::iterate(int index) const {
  return this->array[index];
}