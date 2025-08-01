#include <stdio.h>
#include <stdlib.h>

int popow(int base, int exp){
    int result = 1;
    for(int i = 0; i < exp; i++){
        result *= base;
    }
    return result;
}

    


int main(){
    int base, exp;
    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exp);
    
    int result = popow(base, exp);
    printf("%d raised to the power of %d is %d\n", base, exp, result);
    return 0;
}