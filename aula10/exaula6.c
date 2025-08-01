#include <stdio.h>
#include <stdlib.h>

int converte(int *h, int *m, int *s) 
{
    *h =  (*s /3600); // Convert seconds to hours
    *m =  (*s / 60); // Remaining seconds converted to minutes
    return 0;
}

int main() 
{
    int s[3];
  
    printf("Digite os segundos: ");
    scanf("%d", &s[0]);


    if (s[0] < 0) {
        printf("Valores negativos nao sao permitidos.\n");
        return 1;
    }
    
    converte(&s[2], &s[1], &s[0]);
    printf("%d hora(s) , %d minuto(s), %d segundo(s)\n", s[2]  , s[1], s[0]);

    return 0;
}