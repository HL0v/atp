#include <stdio.h>
//#include <conio.h>

///N�o � vari�vel global, apenas a declara��o de um novo tipo de dados
///A declara��o de um novo tipo de dados s� � visivel dentro do escopo onde foi declarado
///////////////////////
typedef struct S_BANCO
   {
     int num;
     char titular[35];
     float saldo;
   } BANCO;

///////////////////////
void inicializa_cadastro_r(BANCO *conta);//refer�ncia
void escreva_cadastro_r(BANCO conta);//valor

void inicializa_cadastro_v(BANCO *contas, int tam);//refer�ncia
void escreva_cadastro_v(BANCO *contas, int tam);//refer�ncia

///////////////////////
int main()
{
  const int tam = 3;
  
  BANCO conta;
  BANCO contas[tam];
  
  ///////////////////////
  inicializa_cadastro_r(&conta);
  escreva_cadastro_r(conta);
  
  ///////////////////////
  inicializa_cadastro_v(contas,tam);
  escreva_cadastro_v(contas,tam);
	
  ///////////////////////
 // getch();
}

///////////////////////
void inicializa_cadastro_r(BANCO *conta)
{
  printf("\n\nCadastrando um unico registro\n");
  
  printf("Entre com o num da conta: ");
  scanf("%d", &conta->num);//conta->num equivalente a (*conta).num
  //fflush(stdin); does not work in all compilers, use getchar() instead
  
  getchar(); // Limpa o buffer de entrada para evitar problemas com fgets
  
  printf("Entre com o nome do titular: ");
  fgets(conta->titular, sizeof(conta->titular), stdin);
 

  printf("Entre com o saldo da conta: ");
  scanf("%f",&(*conta).saldo);//(*conta).saldo equivalente a conta->saldo
}

void escreva_cadastro_r(BANCO conta)
{
  printf("Escrevendo um unico registro\n");
  printf("%d - %s - %.2f",conta.num,conta.titular,conta.saldo);
}

///////////////////////
void inicializa_cadastro_v(BANCO *contas, int tam)
{
  int i;
  
  printf("\n\nCadastrando um vetor de registros\n");
  
  for (i=0; i<tam; i++)
    {
      //-> and (*). both represent the same
	  printf("Entre com o num da conta: ");
      //scanf("%d",&(*(contas+i)).num);//contas[i].num //OU
      scanf("%d",&(contas+i)->num);//contas[i].num
      
  
      printf("Entre com o nome do titular: ");
      getchar(); // Limpa o buffer de entrada para evitar problemas com fgets
      fgets(contas[i].titular, sizeof(contas[i].titular), stdin);
      
      
      printf("Entre com o saldo da conta: ");
      scanf("%f",&contas[i].saldo);
	}
}

void escreva_cadastro_v(BANCO *contas, int tam)
{
	int i;
	
	printf("Escrevendo um vetor de registros\n");
	for (i=0; i<tam; i++)
      {
        printf("registro %d: %d - %s - %.2f\n",i+1,contas[i].num,contas[i].titular,contas[i].saldo);
	  }
}

