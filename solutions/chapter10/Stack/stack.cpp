#include "stack.h"

Stack::Stack(int size) {
  this->size = size;
  top = -1;
  items = new int[size];
}

Stack::~Stack() {
  delete[] items;
}

void Stack::push(int value) {
  items[++top] = value;
}

int Stack::pop() {
  if (isEmpty()) {
    throw "underflow";
  } else {
    return items[top--];
  }
}

bool Stack::isEmpty() {
  return (top == -1);
}

bool Stack::isFull() {
  return (top + 1 == size);
}
