#include <iostream>
#include <algorithm>
using namespace std;

void bubblesort(int arr[], int n){

  for(int j=0; j<n; j++){
    for(int i=0; i< n-1-j; i++){ // will fill the array from big numbers at the end going down to the lowest
      
      if (arr[i] > arr[i+1]) 
      {
       int temp = arr[i];
       arr[i] = arr[i + 1];
       arr[i + 1] = temp;
      }  
      
    }
  }
  
}

void betterBubbleSort(int arr[], int n) {
    bool swapped;
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        for(int j = 0; j < n - 1 - i; j++) {

            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
    }
}

int main() {
  int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};  
  int size = sizeof(arr)/sizeof(arr[0]);
  
  bubblesort(arr, size);
  
  for (int i=0; i<size; i++){
    cout << arr[i] << " ";
  }
}
