#pragma once

#include <iostream>

template<class T>
class Node {
private:
  T data;
  Node *next;
  int priority;
public:
  Node(T data, int priority) {
    this->priority = priority;
    this->data = data;
  }

  T get_data() {
    return data;
  }

  Node* get_next() {
    return next;
  }

  int get_priority() {
    return priority;
  }

  void set_next(Node* ptr) {
    next = ptr;
  }
};