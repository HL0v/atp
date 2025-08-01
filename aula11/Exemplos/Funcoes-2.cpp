#include <stdio.h>
#include <conio.h>

///Não é variável global, apenas a declaração de um novo tipo de dados
///A declaração de um novo tipo de dados só é visivel dentro do escopo onde foi declarado
///////////////////////
///Maneira de passar um vetor por valor!!!
typedef struct S_Vetor
   {
     int vet[3]={0};
   } Vetor;

///////////////////////
void inicializa_cadastro_v_1(Vetor v, int tam);
void inicializa_cadastro_v_2(Vetor *v, int tam);
void escreva_cadastro_v(Vetor v, int tam);

///////////////////////
int main()
{
  const int tam = 3;
  
  Vetor v;
   
  ///////////////////////
  printf("Não atualiza\n");
  inicializa_cadastro_v_1(v,tam);//erro lógico
  escreva_cadastro_v(v,tam);
  
  ///////////////////////
  printf("Atualiza\n");
  inicializa_cadastro_v_2(&v,tam);
  escreva_cadastro_v(v,tam);
	
  ///////////////////////
  getch();
}

///////////////////////
void inicializa_cadastro_v_1(Vetor v, int tam)//por valor
{
  int i;
  
  for (i=0; i<tam; i++)
    {
	  printf("Entre com o num: ");
      scanf("%d",&v.vet[i]);
      fflush(stdin);
	}
}

void inicializa_cadastro_v_2(Vetor *v, int tam)
{
  int i;
  
  for (i=0; i<tam; i++)
    {
	  printf("Entre com o num: ");
      scanf("%d",&v->vet[i]);
      fflush(stdin);
	}
}

void escreva_cadastro_v(Vetor v, int tam)
{
	int i;
	
	for (i=0; i<tam; i++)
      {
        printf("registro %d: %d \n",i+1,v.vet[i]);
	  }
}

