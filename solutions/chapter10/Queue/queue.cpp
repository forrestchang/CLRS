#include <iostream>

#define SIZE 12

using namespace std;

class Queue
{
public:
  Queue();
  ~Queue();
  bool isEmpty();
  bool isFull();
  void enqueue(int);
  int dequeue();
  void print();

private:
  int Q[SIZE];
  int head;
  int tail;
};

Queue::Queue() {
  head = 0;
  tail = 0;
}

Queue::~Queue(){}

bool Queue::isEmpty() {
  return (head == tail);
}

bool Queue::isFull() {
  return (tail == SIZE);
}

void Queue::enqueue(int value) {
  if (isFull()) {
    throw "The queue is full";
  } else {
    Q[tail++] = value;
  }
}

int Queue::dequeue() {
  if (isEmpty()) {
    throw "The queue is empty";
  } else {
    head++;
    return Q[head - 1];
  }
}

void Queue::print() {
  if (!isEmpty()) {
    for (int i = head; i < tail; i++) {
      cout << Q[i] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  Queue Q;
  Q.enqueue(1);
  Q.print();
  Q.enqueue(3);
  Q.print();
  Q.enqueue(10);
  Q.print();
  Q.enqueue(5);
  Q.print();
  Q.dequeue();
  Q.print();

  return 0;
}
