#include <stdio.h>
#include <conio.h>

int main()
{
  const int tam = 3;
  
  //com aloca��o de espa�o // decalara e aloca
  struct BANCO
   {
     int num;
     char titular[35];
     float saldo;
   } conta, contas[10];

  //ainda consigo declarar outras vari�veis do tipo struct BANCO
  struct BANCO cta = {3, "Maria", 150};//apenas para exemplificar
  
  //n�o consigo declarar outras vari�veis que contenham o conte�do desta struct
  struct
   {
     int num;
     char titular[35];
     float saldo;
   } s_cta;

  int i;
  
  ///////////////////////
  printf("Seja bem-vindo!!!\n\n");
  
  ///////////////////////
  printf("Escrevendo um unico registro\n");
  printf("%d - %s - %.2f",cta.num,cta.titular,cta.saldo);
  
  ///////////////////////
  printf("\n\nCadastrando um unico registro\n");
  
  printf("Entre com o num da conta: ");
  scanf("%d",&conta.num);
  fflush(stdin);
  
  printf("Entre com o nome do titular: ");
  gets(conta.titular);
  
  printf("Entre com o saldo da conta: ");
  scanf("%f",&conta.saldo);
  
  printf("Escrevendo um unico registro\n");
  printf("%d - %s - %.2f",conta.num,conta.titular,conta.saldo);
  
  ///////////////////////
  printf("\n\nCadastrando um vetor de registros\n");
  
  for (i=0; i<tam; i++)
    {
      printf("Entre com o num da conta: ");
      scanf("%d",&contas[i].num);
      fflush(stdin);
  
      printf("Entre com o nome do titular: ");
      gets(contas[i].titular);
  
      printf("Entre com o saldo da conta: ");
      scanf("%f",&contas[i].saldo);
	}
	
	printf("Escrevendo um vetor de registros\n");
	for (i=0; i<tam; i++)
    {
      printf("registro %d: %d - %s - %.2f\n",i+1,contas[i].num,contas[i].titular,contas[i].saldo);
	}
	
	///////////////////////
	getch();
}
