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

template <typename T> int LinkedList<T>::getLength() const {
    int count = 0;

    Node<T> *current = this->head;
    while(current != nullptr){
        count++;
        current = current->next;
    }
    return count;
}

template <typename T> void LinkedList<T>::sort() const {
Node<T>* current1 = this->head;
    Node<T>* current2 = this->head;

    for (int i = 0; i < getLength(); i++) {
        for (int j = 0; j < getLength() - 1; j++) {
            if (current1->data < current2->data) {
                int temp = current1->data;
                current1->data = current2->data;
                current2->data = temp;

            }
            current2 = current2->next;
        }
            current2 = this->head;
            current1 = this->head->next;
            for (int k = 0; k < i; k++) {
                current1 = current1->next;
        }
    }}

template <typename T> void LinkedList<T>::printList() const {}
