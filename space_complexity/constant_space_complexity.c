#include <stdio.h>

/**
 * @brief Computes the square of a number and prints memory usage.
 * @param n The input number.
 * @return The square of n (n²).
 */
int Square(int n) {
    printf("Size of 'int' data type: %zu Bytes\n", sizeof(int));  // Typically 4 Bytes
    printf("Size of parameter 'n': %zu Bytes\n", sizeof(n));      // Same as sizeof(int)
    return n * n;
}

int main() {
    int num;
    printf("Enter a Number: ");
    scanf("%d", &num);  // Takes user input
    
    int result = Square(num);  // Calls Square() and stores result
    printf("Square of %d is: %d\n", num, result);
    
    return 0;
}

/* Output:
Enter a Number: 5
Size of 'int' data type: 4 Bytes
Size of parameter 'n': 4 Bytes
Square of 5 is: 25
*/