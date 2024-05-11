#include <bits/stdc++.h>
using namespace std;

// Function to partition the array into two halves around a pivot element
int partition(int arr[], int start, int end) {
  int pivot = arr[end]; // Choose the pivot element (last element)
  int pIndex = start; // to keep track of elements smaller than pivot

  // Iterate through the array from start to end-1
  for(int i = start; i < end; i++) {
    // If current element is less than the pivot, swap it with element at pIndex
    if(arr[i] < pivot) {
      swap(arr[i], arr[pIndex]);
      pIndex++; // Increment pIndex only when swapping occurs
    }
  }

  // After loop, swap the pivot element with the element at pIndex
  swap(arr[pIndex], arr[end]);

  return pIndex; // Return the pivot Index
}

// Function to perform Quick Sort recursively
void quickSort(int arr[], int low, int high) {
  // Base case: If low is less than high, array has more than one element
  if(low < high) {
    // Partition the array and get the pivot index
    int pivot = partition(arr, low, high);

    // Recursively sort the left and right subarrays
    quickSort(arr, low, pivot - 1); // Sort left subarray
    quickSort(arr, pivot + 1, high); // Sort right subarray
  }
}

int main() {
  // Example array to be sorted
  int numbers[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
  int n = sizeof(numbers) / sizeof(numbers[0]);

  // Perform Quick Sort
  quickSort(numbers, 0, n - 1);

  // Print sorted array
  for (int i = 0; i < n; i++) {
    cout << numbers[i] << " ";
  }

  return 0;
}
