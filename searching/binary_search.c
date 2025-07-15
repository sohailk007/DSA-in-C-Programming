#include <stdio.h>

int main() {
    int a[5] = {10, 20, 30, 40, 50};  // Sorted array (required for binary search)
    int lr = 0, up = 4, mid, item, f = 0;
    
    printf("Enter searching item: ");
    scanf("%d", &item);

    while (lr <= up) {
        mid = (lr + up) / 2;
        
        if (a[mid] == item) {
            f = 1;
            break;
        }
        if (a[mid] < item) {
            lr = mid + 1;  // Search right half
        } else {
            up = mid - 1;  // Search left half
        }
    }

    if (f == 1) {
        printf("Item found at index %d\n", mid);  // Added missing semicolon and "index" for clarity
    } else {
        printf("Item not found\n");  // Added missing semicolon and newline
    }

    return 0;
}