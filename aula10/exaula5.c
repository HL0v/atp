#include <stdio.h>
#include <stdlib.h>


int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}





int sum(int n){
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result += (long double)1 / factorial(i);
        
    }
    printf("S = %f \n", result);
    return result;
}



int main(){
    int n;
    printf("enter N \n");
    scanf("%d", &n);

    if (n == 0) {
        printf("undefined value for S/%d\n", n);
        return 1;
    };
    sum(n);
    return 0;

}