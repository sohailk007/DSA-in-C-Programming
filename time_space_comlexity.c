#include <stdio.h>

// This constant space complexity values may be different but size is fixed.

int Square(int n)
{
    printf("%i Bytes\n", sizeof(int));
    printf("%i Bytes\n", sizeof(n));
    return n * n;
}

main()
{
    int num;
    printf("Enter a Number: ");
    scanf("%d", &num);
    int value = Square(num);
    printf("%i", value);
}

////////////////////////////////////

// Linear Space Complexity No fixed sized it depend on the input size 


//#include <stdio.h>

int Sum(int a[], int n){
    int i, s = 0;
    printf("Array size: %d Bytes\n", sizeof(a)*n); // Array:- 4n
    printf("Integer size: %d Bytes\n", sizeof(int)); // Integer:- 4
    printf("%d Bytes of n\n", sizeof(n)); // Integer size for n:- 4
    printf("%d Bytes of s\n", sizeof(s)); // Integer size for s:- 4
    printf("%d Bytes of i\n", sizeof(i)); // Integer size for i:- 4
    printf("Total Space Complexity: %d Bytes\n", sizeof(a)*n + 4*4); // Total Space Complexity: 4n + 16
   
    for (i = 0; i < n; i++) {
        s = s+a[i];
    }
    return s;
}

main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int value = Sum(arr, size);
    printf("Sum of Array values: %d\n", value);

}

// Time complexity is how long it takes to run the program, while space complexity is how much memory it uses.