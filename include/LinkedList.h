#pragma once

#include "Node.h"

template<class T>
class LinkedList {
private:
  int size;
  Node<T>* head = nullptr;

  void pop() {
    Node<T>* temp = head;
    head = head->get_next();
    delete temp;
  }

public:
  LinkedList() {
    size = 0;
  }

  LinkedList(T data, int priority) {
    head = new Node(data, priority);
    size = 1;
  }

  ~LinkedList() {
    delete [] head;
  }

  void add(T data, int priority) {
    Node<T>* start = head;
    Node<T>* temp = new Node(data, priority);
    if (head->get_priority() > priority) {
      temp->set_next(head);
      head = temp;
    } else {
      while (start->get_next() != nullptr
             && start->get_next()->get_priority() < priority) {
        start = start->get_next();
      }
      temp->set_next(start->get_next());
      start->set_next(temp);
    }
    size++;
  }
  void add(Node<T> node) {
    add(node.get_data(), node.get_priority());
  }
  void print_list() {
    Node<T>* tmp = head;
    while (tmp != nullptr) {
      std::cout << tmp->get_data() << " ";
      tmp = tmp->get_next();
    }
    std::cout << std::endl;
  }

  int get_size() {
    return size;
  }

  T operator[](int index) {
    if (index >= size) throw std::invalid_argument("Index out of range");
    int i = 0;
    Node<T>* tmp = head;
    while (tmp != nullptr && i != index) {
      tmp = tmp->get_next();
      i++;
    }
    return tmp->get_data();
  }
};