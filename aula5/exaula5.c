#include <stdio.h>
#include <stdlib.h>

int main(){
    int Num, aux = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &Num);

    for(int i = 1; i < Num; i++ ){
        if(Num % i == 0){
            aux += i;
        }
    }
    if(aux == Num){
        printf("%d é um número perfeito.\n", Num);
    } else {
        printf("%d não é um número perfeito.\n", Num);
    }
    return 0;
}

