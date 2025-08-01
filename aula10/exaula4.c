#include <stdio.h>
#include <stdlib.h>

int times(int a){
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= i; j++){
            printf(" %d", i*j);
        }
        printf("\n");
    }
}
int main(){
    int a;
    printf("Enter a number from 1-9: ");
    scanf("%d", &a);

    if (a < 1 || a > 9) {
        printf("Invalid input. Please enter a number between 1 and 9.\n");
        return 1;
    }

    times(a);
    return 0;
}