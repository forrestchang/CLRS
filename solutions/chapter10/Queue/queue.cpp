#include "queue.h"

Queue::Queue(int size) {
  this->head = 0;
  this->tail = 1;
  this->size = size;
  this->items = new int[size];
}

Queue::~Queue() {
  delete[] items;
}

bool Queue::isEmpty() {
  return (head == tail);
}

bool Queue::isFull() {
  return (tail == size);
}

void Queue::enqueue(int value) {
  if (isFull()) {
    throw "Overflow";
  } else {
    items[tail++] = value;
  }
}

int Queue::dequeue() {
  if (isEmpty()) {
    throw "Underflow";
  } else {
    return items[head++];
  }
}

