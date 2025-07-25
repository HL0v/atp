#include <stdio.h>
#include <stdlib.h>

void fiveVal(){
    int nv[5];
    for(int i = 0; i < 5; i++){
        printf("Enter 5 values: ");
        scanf("%d", &nv[i]);
        printf("| %d | \n", nv[i]);
    }

    //sorting the array using insertion sort
    int i= 0;
    int j= 1;
    int aux = 0;

    while (j < 5)
    {
    aux = nv[j];
    i = j - 1;
     while ((i >= 0) && (nv[i] > aux))
     {
     nv[i + 1] = nv[i];
     i = i - 1;
     }
     nv[i + 1] = aux;
     j = j + 1;
     }
     //end of sorting


    printf("biggest: %d\n", nv[4]);
    printf("smallest: %d\n", nv[0]);
}
int main(){
    fiveVal();  
    return 0;
}
