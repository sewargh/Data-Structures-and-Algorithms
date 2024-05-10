#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {

  for (int j = 0; j < n; j++) 
  {
    int min = pow(2, 31) - 1; // suppose all elements are positiove numbers;
    int min_index = j;
    
    for (int i = j; i < n; i++)
    {
      if (arr[i] < min) 
      {
        min = arr[i];
        min_index = i;
      }
    }
    swap(arr[j], arr[min_index]);
  }

}

int main() {
  int arr[] = {8,2, 10, 3, 6, 5, 4, 7, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, size);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}
