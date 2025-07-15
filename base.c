#include <stdio.h>

int main() {
    // First part: sum of two numbers
    int x = 10;
    int y = 20;
    int sum = y + x;
    printf("The sum of %d and %d is %d\n", x, y, sum);

    // Second part: counting from 1 to 10
    int i = 1;
    while (i <= 10) {
        printf("%d ", i);
        i++;
    }
    
    printf("\n");  // Add a newline at the end
    return 0;
}