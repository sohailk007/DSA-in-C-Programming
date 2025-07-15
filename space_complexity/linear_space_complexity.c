#include <stdio.h>

/**
 * @brief Computes the sum of an array and prints memory usage.
 * @param a[] The input array.
 * @param n   Size of the array.
 * @return Sum of array elements.
 */
int Sum(int a[], int n) {
    int i, sum = 0;
    
    printf("\n--- Memory Usage Analysis ---\n");
    printf("Array size: %zu Bytes\n", sizeof(a[0]) * n);  // 4n Bytes (if int = 4 Bytes)
    printf("Integer size: %zu Bytes\n", sizeof(int));      // 4 Bytes (fixed)
    printf("Variable 'n' size: %zu Bytes\n", sizeof(n));   // 4 Bytes
    printf("Variable 'sum' size: %zu Bytes\n", sizeof(sum)); // 4 Bytes
    printf("Variable 'i' size: %zu Bytes\n", sizeof(i));   // 4 Bytes
    
    // Total Space Complexity = Array (4n) + Variables (4 + 4 + 4) = 4n + 12
    printf("Total Space Complexity: %zu Bytes\n", sizeof(a[0]) * n + 3 * sizeof(int));
    
    for (i = 0; i < n; i++) {
        sum += a[i];  // Accumulates sum
    }
    
    return sum;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);  // Takes array size
    
    int arr[size];  // Declares array of given size
    printf("Enter %d elements:\n", size);
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);  // Reads array elements
    }
    
    int total = Sum(arr, size);  // Computes sum
    printf("\nSum of Array values: %d\n", total);
    
    return 0;
}

/*
Output:
Enter the size of the array: 3
Enter 3 elements:
10 20 30

--- Memory Usage Analysis ---
Array size: 12 Bytes
Integer size: 4 Bytes
Variable 'n' size: 4 Bytes
Variable 'sum' size: 4 Bytes
Variable 'i' size: 4 Bytes
Total Space Complexity: 24 Bytes

Sum of Array values: 60
*/