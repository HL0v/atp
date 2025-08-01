#include <stdio.h>
#include <stdlib.h> 

void copy(int *m, int *v){
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            *(v + (i * 4 + j)) = *(m + (i * 4 + j)); // Copy each element from matrix to vector
        }
    }   
}

int main(){
    const int sizeC = 3, sizeL = 4, s = 12;
    int m[sizeL][sizeC], v[s];

    for(int i = 0; i < sizeL; i++){
        for(int j = 0; j < sizeC; j++){
            m[i][j] = rand() % 10; // Fill the matrix with random numbers between 0 and 99
            printf(" | %d ", m[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");

    copy(&m[0][0], &v[0]);
    for(int i = 0; i < 12; i++){
        printf(" | %d ", v[i]);
    }
    printf("\n");
    return 0;
}