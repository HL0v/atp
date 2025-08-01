int main()
{
    int N, i;
    int *vetor;

    printf("Entre com o valor do vetor: ");
    scanf("%d",&N);
    vetor = (int *)malloc(sizeof(int)*N);


    for(i=0;i<N;i++){
        vetor[i]=i+1;
    }
    for(i=0;i<N;i++){
        printf("%d ",vetor[i]); //como vetor
        printf("\n\n");
    }

    for(i=0;i<N;i++){
        printf("%d ",*(vetor+i)); //como ponteiro
    }
    free(vetor); // libera memória alocada

}
