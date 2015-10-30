class Queue {
  int head;
  int tail;
  int size;
  int *items;

public:
  Queue(int);
  ~Queue();
  bool isEmpty();
  bool isFull();
  void enqueue(int);
  int dequeue();
};
