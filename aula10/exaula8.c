#include <stdio.h>
#include <stdlib.h>

int order(int *a, int *b, int *c, char op) {
    int temp;
    for(int i = 0; i < 10; i++) {
        c[i] = a[i];
        c[i+10] = b[i];

    }
    if(op == 'A'){
        for(int i = 0; i < 20; i++) {
            for(int j = 0; j < 20; j++) {
                if(c[i] < c[j]) {
                    temp = c[i];
                    c[i] = c[j];
                    c[j] = temp;
                }
            }
        }
    } else if(op == 'D') {
        for(int i = 0; i < 20; i++) {
            for(int j = 0; j < 20; j++) {
                if(c[i] > c[j]) {
                    temp = c[i];
                    c[i] = c[j];
                    c[j] = temp;
                }
            }
        }
    }
    return 0; // Return 0 to indicate successful ordering
}
int main() {
    int a[10], b[10], c[20];
    
    // Example initialization of c
    for(int i = 0; i < 10; i++) {
        a[i] = rand() % 100; // Random numbers between 0 and 99
        b[i] = rand() % 100; // Random numbers between 0 and 99
    }
    printf("Enter 'A' for ascending order or 'D' for descending order: ");
    char op;
    scanf(" %c", &op); // Note the space before %c to consume any newline character
    
    // Call the order function
    order(&a[0], &b[0], &c[0], op);
    
    // Print the ordered arrays
    printf("Array a: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Array b: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    printf("Array c: ");
    for(int i = 0; i < 20; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}