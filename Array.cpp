#include "Array.h"

template <typename T> Array<T>::Array() {
  this->array = new T[100];
  this->_count = 0;
  this->MAXSIZE = 100;
}
template <typename T> Array<T>::Array(int size) {
  this->array = new T[size];
  this->_count = 0;
  this->MAXSIZE = size;
}

template <typename T> void Array<T>::append(T data) {
  this->array[this->_count++] = data;
}

template <typename T> T *Array<T>::search(T value) const {
  for (int i = 0; i < this->_count; i++) {
    if (this->array[i] == value) {
      return &this->array[i];
    }
  }
  return nullptr;
}

template <typename T> void Array<T>::sort() const {
  int i, key, j;
    for (i = 1; i < this->_count; i++)
    {
        key = this->array[i];
        j = i - 1;

        while (j >= 0 && this->array[j] > key)
        {
            this->array[j + 1] = this->array[j];
            j = j - 1;
        }
        this->array[j + 1] = key;
    }
}

template <typename T> T Array<T>::at(int index) const {
  return this->array[index];
}

template <typename T> void Array<T>::printList() const {
  for (int i = 0; i < this->_count; i++) {
  }
}

template <typename T> int Array<T>::count() { return this->_count; }

template <typename T> void Array<T>::remove(const T value) {
  bool overwrite = false;
  for (int i = 0; i < this->_count; i++) {
    if (this->array[i] == value || overwrite) {
      this->array[i] = this->array[i + 1];
      overwrite = true;
    }
  }
}
