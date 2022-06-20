#include "LinkedList.h"
#include "Datastructure.h"

template <typename T> LinkedList<T>::LinkedList() { this->head = nullptr; }

template <typename T> void LinkedList<T>::append(T data) {
  Node<T> *current = this->head;

  while (current->next != nullptr) {
    current = current->next;
  }

  current->next = new Node<T>(data);
}

template <typename T>
T *LinkedList<T>::search(std::string value) override const {
  Node<T> *current = this->head;

  while (current->next != nullptr) {
    if (current->data == value) {
      return current->data;
    }
    current = current->next;
  }

  return nullptr;
}

template <typename T> void LinkedList<T>::sort() const {}

template <typename T> void LinkedList<T>::printList() const {}