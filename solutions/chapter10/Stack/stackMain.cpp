#include <iostream>

#include "stack.h"

using namespace std;

int main(void) {
  Stack stack(10);
  for (int i = 0; !stack.isFull(); i++) {
    stack.push(i);
  }

  while (!stack.isEmpty()) {
    cout << stack.pop() << " ";
  }
  cout << endl;

  return 0;
}
