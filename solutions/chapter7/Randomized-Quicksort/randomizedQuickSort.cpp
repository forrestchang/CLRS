#include <iostream>

using namespace std;

void swap(int * a, int *b);
int partition(int array[], int p, int r);
int randomizedPartition(int array[], int p, int r);
void randomizedQuickSort(int array[], int p, int r);

int main(void) {
  int arraySize;
  int testArray[1000];

  cin >> arraySize;
  for (int i = 0; i < arraySize; i++) {
    cin >> testArray[i];
  }

  randomizedQuickSort(testArray, 0, arraySize - 1);

  for (int i = 0; i < arraySize; i++) {
    cout << testArray[i] << " ";
  }
  cout << endl;

  return 0;
}

void swap(int * a, int * b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int array[], int p, int r) {
  int x = array[r];
  int i = p - 1;

  for (int j = p; j <= r - 1; j++) {
    if (array[j] < x) {
      i++;
      swap(&array[j], &array[i]);
    }
  }

  swap(&array[i + 1], &array[r]);
  return (i + 1);
}

int randomizedPartition(int array[], int p, int r) {
  int i = rand() % (r - p) + p;
  swap(&array[r], &array[i]);
  return partition(array, p, r);
}

void randomizedQuickSort(int array[], int p, int r) {
  if (p < r) {
    int q = randomizedPartition(array, p, r);
    randomizedQuickSort(array, p, q - 1);
    randomizedQuickSort(array, q + 1, r);
  }
}
