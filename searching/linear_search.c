#include <stdio.h>

int main() {
    int item;
    int found = 0;  // Initialize found flag to 0 (false)

    int arr[5] = {32, 43, 76, 29, 87};
    printf("Enter the number: ");
    scanf("%d", &item);

    for (int i = 0; i < 5; i++) {
        if (arr[i] == item) {
            printf("Item found position is %d\n", i);
            found = 1;  // Set found flag to 1 (true) when item is found
            break;
        }
    }
    
    if (!found) {
        printf("Item not found\n");
    }
    
    return 0;
}