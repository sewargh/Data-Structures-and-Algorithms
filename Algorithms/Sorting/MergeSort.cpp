#include <bits/stdc++.h>
using namespace std;

// Merge two subarrays of arr[].
// First subarray is arr[low..mid]
// Second subarray is arr[mid+1..high]
void mergeArray(int arr[], int low, int mid, int high) {
  // Initialize iterators for left, right, and temporary arrays
  int iLeft = low; // Iterator for left subarray
  int iRight = mid + 1; // Iterator for right subarray
  int iTemp = 0; // Iterator for temporary array
  int temp[high - low + 1]; // Temporary array to store merged elements

  // Merge elements from left and right subarrays into temporary array
  while (iLeft <= mid && iRight <= high) {
    if (arr[iLeft] < arr[iRight])
      temp[iTemp++] = arr[iLeft++];
    else
      temp[iTemp++] = arr[iRight++];
  }

  // Add remaining elements from left subarray, if any
  while (iLeft <= mid)
    temp[iTemp++] = arr[iLeft++];

  // Add remaining elements from right subarray, if any
  while (iRight <= high)
    temp[iTemp++] = arr[iRight++];

  // Copy elements from temporary array back to original array
  iTemp = 0;
  for (int i = low; i <= high; i++) {
    arr[i] = temp[iTemp++];
  }
}

// Main function to perform merge sort
void mergeSort(int arr[], int low, int high) {
  if (low < high) {
    // Find the middle point
    int mid = (high + low) / 2;

    // Recursively sort the left and right halves
    mergeSort(arr, low, mid); // Sort left subarray
    mergeSort(arr, mid + 1, high); // Sort right subarray

    // Merge the sorted halves
    mergeArray(arr, low, mid, high);
  }
}

int main() {
  // Example array to be sorted
  int numbers[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
  int n = sizeof(numbers) / sizeof(numbers[0]);

  // Perform merge sort
  mergeSort(numbers, 0, n - 1);

  // Print sorted array
  for (int i = 0; i < n; i++) {
    cout << numbers[i] << " ";
  }

  return 0;
}
