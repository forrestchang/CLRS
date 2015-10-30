class Stack {
  int top;
  int size;
  int *items;

public:
  Stack(int);
  ~Stack();
  void push(int);
  int pop();
  bool isEmpty();
  bool isFull();
};
