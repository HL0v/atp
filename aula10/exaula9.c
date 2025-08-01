#include <stdio.h>
#include <stdlib.h>

void linemultiply(int *a , int sizeL, int sizeC) {
    for (int c = 0; c < sizeC; c++){
        for(int l = 0; l < sizeL; l++){
            if(c == l){ // Check if it's a diagonal element and not the first row
                int aux = (*(a + (c * sizeL + l)));
                for(int m = 0; m < sizeL; m++){
                    (*(a + (c * sizeL + m)) *= aux); // Multiply each element in the line by the diagonal element
                }
            }
        }
    }
}

int main(){
    const int sizeL = 6, sizeC = 6;
    int a[sizeL][sizeC];

    // Initialize the matrix with random values
    for (int i = 0; i < sizeL; i++) {
        for (int j = 0; j < sizeC; j++) {
            a[i][j] = rand() % 10; // Random values between 0 and 9
            printf(" | %d ", a[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");

    linemultiply(&a[0][0], sizeL, sizeC);
    for(int i = 0; i < sizeC; i++){
        for(int j = 0; j < sizeL; j++){
            printf(" | %d ", a[i][j]);
        }
        printf("\n");
    }
}
