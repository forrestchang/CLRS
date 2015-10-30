#include <iostream>
#include <cmath>

using namespace std;

void swap(int * a, int * b);
int parent(int i);
int left(int i);
int right(int i);
void maxHeapify(int array[], int i, int heapSize);
void buildMaxHeap(int array[], int heapSize);
void heapSort(int array[], int heapSize);

int main(void) {
  int heapSize;
  int testArray[1000];

  cin >> heapSize;
  for (int i = 0; i < heapSize; i++) {
    cin >> testArray[i];
  }

  heapSort(testArray, heapSize);

  for (int i = 0; i < heapSize; i++) {
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

// Get parent
int parent(int i) {
  return (int)((i - 1) / 2);
}

// Get left
int left(int i) {
  return i * 2 + 1;
}

// Get right
int right(int i) {
  return i * 2 + 2;
}

// Max-heapify
void maxHeapify(int array[], int i, int heapSize) {
  int l = left(i);
  int r = right(i);
  int largest;

  if (l < heapSize && array[l] > array[i]) {
    largest = l;
  } else {
    largest = i;
  }

  if (r < heapSize && array[r] > array[largest]) {
    largest = r;
  }

  if (largest != i) {
    swap(&array[i], &array[largest]);
    maxHeapify(array, largest, heapSize);
  }
}

// Build-Max-Heap
void buildMaxHeap(int array[], int heapSize) {
  for (int i = (int)((heapSize - 2) / 2); i >= 0; i--) {
    maxHeapify(array, i, heapSize);
  }
}

// Heap-Sort
void heapSort(int array[], int heapSize) {
  buildMaxHeap(array, heapSize);
  for (int i = heapSize - 1; i >= 1; i--) {
    swap(&array[0], &array[i]);
    heapSize--;
    maxHeapify(array, 0, heapSize);
  }
}

