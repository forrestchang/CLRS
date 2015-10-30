#include <iostream>

#include "queue.h"

using namespace std;

int main(void) {
  Queue queue(10);

  for (int i = 0 ; !queue.isFull(); i++) {
    queue.enqueue(i);
  }

  while (!queue.isEmpty()) {
    cout << queue.dequeue() << " ";
  }
  cout << endl;

  return 0;
}
