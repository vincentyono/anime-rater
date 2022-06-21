#include "Node.h"

template <typename T> Node<T>::Node() {
  this->data = nullptr;
  this->next = nullptr;
}

template <typename T> Node<T>::Node(T data) {
  this->data = data;
  this->next = nullptr;
}

template <typename T> Node<T>::Node(T data, Node<T> *next) {
  this->data = data;
  this->next = next;
}

template <typename T> Node<T>::~Node() {
  this->next = nullptr;
  delete this->data;
  delete this;
}