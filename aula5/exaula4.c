#include <stdio.h>
#include <stdlib.h>

int main(){
    int idade, cntFs = 0,cntFn = 0, cntMs = 0,cntMn = 0, cntMi = 0,cntFi = 0;

    while(1){
        
        printf("Digite sua idade(18-70):\n");
        scanf("%d", &idade);

        //verifica se a idade é válida
        if(idade < 18 || idade > 70){
            printf("Idade invalida, tente novamente.\n");
            continue; // Skip to the next iteration of the loop
        }
        printf("insira M para masculino ou F para feminino:\n");
        printf("Digite S para sim N para Não e I para Indiferente:\n");
        char sexo;
        char resposta;
        scanf(" %c %c", &sexo, &resposta);
        //verifica se o sexo é válido
        if(sexo != 'M' && sexo != 'F'){
            printf("Sexo invalido, tente novamente.\n");
            continue; // Skip to the next iteration of the loop
        }else if(resposta != 'S' && resposta != 'N' && resposta != 'I'){
            printf("Resposta invalida, tente novamente.\n");
            continue; // Skip to the next iteration of the loop
        }
        //conta o número de respostas
        if(sexo == 'F' && resposta == 'S'){
            cntFs++;
        } else if(sexo == 'F' && resposta == 'N'){
            cntFn++;
        } else if(sexo == 'M' && resposta == 'S'){
            cntMs++;
        } else if(sexo == 'M' && resposta == 'N'){
            cntMn++;
        } else if(sexo == 'M' && resposta == 'I'){
            cntMi++;
        } else if(sexo == 'F' && resposta == 'I'){
            cntFi++;
        }

        // Exibe os resultados
        printf("Resultados:\n");
        printf("Total: %d\n", cntFs + cntFn + cntMs + cntMn + cntMi + cntFi);
        printf("Masculino - Sim: %d\n", cntMs);
        printf("Masculino - Não: %d\n", cntMn);
        printf("Masculino - Indiferente: %d\n", cntMi);
        printf("Feminino - Sim: %d\n", cntFs);
        printf("Feminino - Não: %d\n", cntFn);
        printf("Feminino - Indiferente: %d\n", cntFi);
        printf("%% de pessoas que disseram não: %.2f%%\n", 
               (float)(cntFn + cntMn) / (cntMs + cntMn + cntMi + cntFs + cntFn + cntFi) * 100);
        
    }
}