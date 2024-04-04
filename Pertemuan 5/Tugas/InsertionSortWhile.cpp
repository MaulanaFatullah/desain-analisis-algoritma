#include <iostream>
using namespace std;

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main() {
  int data[] = {21, 5, 41, 15, 13};
  int size = sizeof(data) / sizeof(data[0]);
  
  cout<<"Array before sort:\n";
  printArray(data, size);
  
  insertionSort(data, size);
  cout << endl;
  cout << "Array after sort:\n";
  printArray(data, size);
}