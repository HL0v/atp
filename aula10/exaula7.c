#include<stdio.h>
#include<stdlib.h>


float grades(float *n, float p, char op){
    float media;
    if (op == 'A') {
        *n = (*n + *(n + 1) + *(n + 2)) / 3; // Sum the grades

    } else if (op == 'P') {
        int p1, p2, p3;

        printf("Digite o peso da primeira nota: ");
        scanf("%d", &p1);
        printf("Digite o peso da segunda nota: ");
        scanf("%d", &p2);
        printf("Digite o peso da terceira nota: ");
        scanf("%d", &p3);

        *n = ((*n * p1) + (*(n + 1) * p2) + (*(n + 2) * p3)) / (p1 + p2 + p3); // Weighted average
    } else {
        printf("Operacao invalida.\n");
        return -1; // Invalid operation
    }
    return media;
}

int main() {
    float n[3];
    char op;
for(int i = 0; i < 3; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &n[i]);
        if (n[i] < 0 || n[i] > 10) {
            printf("Nota invalida. Digite um valor entre 0 e 10.\n");
            return 1; // Exit if invalid input
        }
    }

    printf("Digite 'A' para media aritmetica ou 'P' para media ponderada: ");
    scanf(" %c", &op); // Note the space before %c to consume any newline character
    
    float result = grades(&n[0] , &n[1] , op);

    if (result != -1) {
        printf("Resultado: %.2f\n", n[0]);
    }

    return 0;
}