#include "LinkedList.h"

template <typename T1, typename T2> LinkedList<T1, T2>::LinkedList() {
  this->head = nullptr;
}

template <typename T1, typename T2>
void LinkedList<T1, T2>::append(
    T1 data) { // insert an element but keep LinkedList sorted
               //  time complexity = O(n)
  if (this->head == nullptr) {
    this->head = new Node<T1>(data);
    return;
  }

  Node<T1> *current = this->head;
  Node<T1> *prev = nullptr;

  if (data <= current->data) {
    this->head = new Node<T1>(data, current);
  } else {
    while (current != nullptr) {
      if (data <= current->data) {
        prev->next = new Node<T1>(data, current);
        return;
      }
      prev = current;
      current = current->next;
    }
    prev->next = new Node<T1>(data);
  }
}

template <typename T1, typename T2>
T1 *LinkedList<T1, T2>::search(
    T2 value) const { // linear search, time complexity = O(n)
  Node<T1> *current = this->head;
  while (current != nullptr) {
    if (current->data == value) {
      return &current->data;
    }
    current = current->next;
  }
  return nullptr;
}

template <typename T1, typename T2>
void LinkedList<T1, T2>::remove(T2 value) { // time complexity = O(n)
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

template <typename T1, typename T2>
void LinkedList<T1, T2>::printList() const { // time complexity = O(n)
  Node<T1> *current = this->head;
  while (current != nullptr) {
    std::cout << current->data << "\n";
    current = current->next;
  }
}

template <typename T1, typename T2>
std::string LinkedList<T1, T2>::toString(std::string func(T1)) {
  std::string str;
  Node<T1> *current = this->head;
  while (current != nullptr) {
    str = str + func(current->data);
    current = current->next;
  }
  return str;
}