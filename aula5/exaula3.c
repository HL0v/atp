#include <stdio.h>
#include <stdbool.h>

int main(){
  int N, cnt = 0;
    printf("Digite N \n");
    scanf("%d",&N);
    for(int i = 1; i <= N; i++ ){
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                cnt++;
            }
        }
        if(cnt <= 2){
            printf("%d é primo \n", i); 
        }
        cnt = 0; // Reset count for the next number
    }
}