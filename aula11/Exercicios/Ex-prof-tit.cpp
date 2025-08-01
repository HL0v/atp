#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

typedef struct
{
	int cod_prof, cod_tit, total_semanal;
	char nome[50];
} professor;

typedef struct
{
	int cod_tit;
	float valor_ha;
	char descr[50];
} titulo;

void cadastra_tit(titulo *tit, int tam2);
void cadastra_prof(professor *prof, titulo *tit, int tam1, int tam2);
void lista(professor *prof, titulo *tit, int tam1, int tam2);

int main()
{
	const int tam1 = 2;//prof
	const int tam2 = 3;//tit
	
	professor prof[tam1];
	titulo tit[tam2];
	
	cadastra_tit(tit,tam2);
	system("cls");
	
	cadastra_prof(prof,tit,tam1,tam2);
	system("cls");
	
	lista(prof,tit,tam1,tam2);
	
	//getch();
}

/////////////////////////////////
void cadastra_tit(titulo *tit, int tam2)
{
	int i;
	
	for (i=0; i<tam2; i++)
	  {
	  	printf("Codigo do titulo: ");
	  	scanf("%d",&tit[i].cod_tit);
		getchar();
	  	
	  	printf("Descricao do titulo: ");
	  	fgets(tit[i].descr, sizeof(tit[i].descr), stdin);
	  	getchar();

	  	printf("Valor da h/a: ");
	  	scanf("%f",&tit[i].valor_ha);
	  	getchar();
	  }
}

/////////////////////////////////
void cadastra_prof(professor *prof, titulo *tit, int tam1, int tam2)
{
	int i, j, achou;
	
	for (i=0; i<tam1; i++)//prof
	  {
	  	printf("Codigo do professor: ");
	  	scanf("%d",&prof[i].cod_prof);
	  	getchar();
	  	
	  	printf("Nome do professor: ");
	  	fgets(prof[i].nome, sizeof(prof[i].nome),stdin);
	  	getchar();
	  	
	  	do{
	  		printf("Codigo do titulo ");
	  	    scanf("%d",&prof[i].cod_tit);
	  	    getchar();
	  	    
	  	    //busca
	  	    achou=0;
	  	    for (j=0; j<tam2; j++)//tit
	  	      {
	  	      	if (prof[i].cod_tit == tit[j].cod_tit)
	  	      	  {
	  	      	  	achou = 1;
	  	      	  	break;
				  }
			  }
			  
			if (!achou)
			  printf("Titulo nao cadastrado, digite outro titulo\n");  
		  }while(!achou);
	  	
	  	printf("Carga horaria semanal: ");
	  	scanf("%d",&prof[i].total_semanal);
	  	getchar();
	  }
}

void lista(professor *prof, titulo *tit, int tam1, int tam2)
{
	int i, j;
	float total_geral;
	
	for (i=0; i<tam1; i++)//prof
	  {
	  	printf("%d, %s, ",prof[i].cod_prof,prof[i].nome);
	  	for (j=0; j<tam2; j++)//tit
	  	      {
	  	      	if (prof[i].cod_tit == tit[j].cod_tit)
	  	      	  {
	  	      	  	printf("%s, %.2f, ",tit[j].descr,tit[j].valor_ha);
	  	      	  	
	  	      	  	total_geral = tit[j].valor_ha * prof[i].total_semanal;
	  	      	  	
	  	      	  	printf("%d, %.2f\n",prof[i].total_semanal,total_geral);
	  	      	  	break;
				  }
			  }
	  }
}

