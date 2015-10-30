#include <iostream>

using namespace std;

int randomizedSelect(int array[], int p, int r, int index);

int main(void) {
  int arraySize;
  cin >> arraySize;
  int *testArray = new int(arraySize);

  for (int i = 0; i < arraySize; i++) {
    cin >> testArray[i];
  }

  int index;
  cin >> index;
  int result = randomizedSelect(testArray, 0, arraySize - 1, index);

  cout << result << endl;


  delete[] testArray;
  return 0;
}

void swap(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

int partition(int array[], int p, int r) {
  int x = array[r];
  int i = p - 1;

  for (int j = p; j <= r; j++) {
    if (array[j] < x) {
      i++;
      swap(array[j], array[i]);
    }
  }

  swap(array[i + 1], array[r]);
  return (i + 1);
}

int randomizedPartition(int array[], int p, int r) {
  int x = rand() % (r - p) + p;
  swap(array[x], array[r]);
  return partition(array, p, r);
}

int randomizedSelect(int array[], int p, int r, int index) {
  if (p == r) {
    return array[p];
  }

  int q = randomizedPartition(array, p, r);
  int k = q - p + 1;

  if (k == q) {
    return array[q];
  } else if (index < k) {
    return randomizedSelect(array, p, q - 1, k);
  } else {
    return randomizedSelect(array, q + 1, r, index - k);
  }


}
