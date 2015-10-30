#include <iostream>

#include "queue.h"

using namespace std;

int main(void) {
  Queue queue(10);

  for (int i = 0; i < 9; i++) {
    queue.enqueue(i);
  }

  for (int i = 0; i < 9; i++) {
    cout << queue.dequeue() << " ";
  }

  cout << endl;

  return 0;
}
