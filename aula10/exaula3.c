#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b) {
    int small, big;
    int result = 0;

    if (a > b){
        small = b;
        big = a;
    }else if (a < b){
        small = a;
        big = b;
    }   

    for(int i = small; i <= big; i++){
      result += i;
    }
    return result;
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    int result = sum(a, b);
    printf("The sum of all integers between %d and %d is: %d\n", a, b, result);   
    return 0;
}