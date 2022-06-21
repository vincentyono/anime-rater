#include "LinkedList.h"

template <typename T1, typename T2> LinkedList<T1, T2>::LinkedList() {
  this->head = nullptr;
}

template <typename T1, typename T2> void LinkedList<T1, T2>::append(T1 data) {
  if (this->head == nullptr) {
    this->head = new Node<T1>(data);
  } else {
    Node<T1> *current = this->head;
    while (current->next != nullptr) {
      current = current->next;
    }

    current->next = new Node<T1>(data);
  }
}

template <typename T1, typename T2>
T1 *LinkedList<T1, T2>::search(T2 value) const {
  Node<T1> *current = this->head;
  while (current != nullptr) {
    if (current->data == value) {
      return &current->data;
    }
    current = current->next;
  }
  return nullptr;
}

template <typename T1, typename T2> void LinkedList<T1, T2>::sort() const {}

template <typename T1, typename T2> void LinkedList<T1, T2>::remove(T2 value) {
  if (this->head->data == value) {
    this->head = this->head->next;
    return;
  }

  Node<T1> *prev = this->head;
  Node<T1> *current = this->head->next;

  while (current != nullptr) {
    if (current->data == value) {
      prev->next = current->next;
    }
    prev = prev->next;
    current = current->next;
  }
}

template <typename T1, typename T2> void LinkedList<T1, T2>::printList() const {
  Node<T1> *current = this->head;
  while (current != nullptr) {
    std::cout << current->data << "\n";
    current = current->next;
  }
}