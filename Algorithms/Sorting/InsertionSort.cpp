#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int insert_index = -1;
        // Find the correct insert_index for the current element
        for (int j = i; j > 0; j--) {
            if (arr[i] > arr[j - 1]) {
                insert_index = j;
                break; // Break out of the loop once the insert_index is found
            }
        }
        // If no insert_index is found, it means the element is the smallest so far
        if (insert_index == -1)
            insert_index = 0;

        // Store the current element to be inserted
        int element = arr[i];

        // Shift elements to the right to make space for the new element
        for (int k = i; k > insert_index; k--) {
            arr[k] = arr[k - 1];
        }

        // Insert the element at the correct position
        arr[insert_index] = element;
    }
}

int main() {
    int numbers[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    insertionSort(numbers, n);

  cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}
