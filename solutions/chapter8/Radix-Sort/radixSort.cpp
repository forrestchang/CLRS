#include <iostream>
#include <cmath>

using namespace std;

int max(int array[], int arraySize);
void radixSort(int array[],int arraySize, int result[]);
int digit(int value);
void swap(int * a, int * b);

int main(void) {
  int arraySize;
  cin >> arraySize;

  int * testArray = (int *)malloc(arraySize * sizeof(int));
  int * result = (int *)malloc(arraySize * sizeof(int));

  for (int i = 0; i < arraySize; i++) {
    cin >> testArray[i];
  }

  radixSort(testArray, arraySize, result);

  for (int i = 0; i < arraySize; i++) {
    cout << result[i] << " ";
  }
  cout << endl;

  free(result);
  free(testArray);

  return 0;
}

void radixSort(int array[], int arraySize, int result[]) {
  int d = digit(max(array, arraySize));
  int * digitArray = (int *)malloc(arraySize * sizeof(int));

  // 最高位有d位，所以循环d次
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < arraySize; j++) {
      digitArray[j] = (array[j] % (int)pow(10, (i + 1))- array[j] % (int)pow(10, i)) / pow(10, i); // 拆分第(i+1)位到一个新的数组
    }

    int k = max(digitArray, arraySize);
    int * tempArray = (int *)malloc((k + 1) * sizeof(int));
    int tempArraySize = k + 1;

    // 对这个新的数组使用计数排序
    for (int j = 0; j < tempArraySize; j++) {
      tempArray[j] = 0;
    }

    for (int j = 0; j < arraySize; j++) {
      tempArray[digitArray[j]]++;
    }

    for (int j = 1; j < tempArraySize; j++) {
      tempArray[j] += tempArray[j - 1];
    }

    for (int j = arraySize - 1; j >= 0; j--) {
      result[--tempArray[digitArray[j]]] = array[j]; // 将原数组中的数插入到相应的位置中
    }

    // 把result数组（对第(i+1)位进行排序后的数组）赋值给array，以备下一次计数排序的使用
    for (int j = 0; j < arraySize; j++) {
      array[j] = result[j];
    }

    free(tempArray);
  }

  free(digitArray);
}

void swap(int * a, int * b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int digit(int value) {
  int digit = 0;
  while (value) {
    value /= 10;
    digit++;
  }

  return digit;
}

int max(int array[], int arraySize) {
  int largest = array[0];
  for (int i = 0; i < arraySize; i++) {
    largest = largest > array[i] ? largest : array[i];
  }

  return largest;
}
