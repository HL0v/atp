#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
	int num;
	float saldo;
	char nome[50];
} banco;

int busca(banco *conta, int num_conta, int tam);
void cadastra(banco *conta, int num_conta, float saldo, char *nome, int *posi);
void lista(banco *conta, char *nome_cliente, int tam);
void remove_menor_saldo(banco* conta, int *posi);

int main()
{
	const int tam=5;
	banco conta[tam];
	int i, op, posi, achou, num_conta;
	float saldo;
	char nome_cliente[50];
	
	posi=0;//controla a posição onde estou no vetor conta
	do
	{
		printf("1: Cadastrar contas\n");
		printf("2: Visualizar todas as contas de determinado cliente\n");
		printf("3: Excluir conta de menor saldo\n");
		printf("4: Sair\n");
		printf("Opcao: ");
		scanf("%d",&op);
		fflush(stdin);
		
		switch(op)
		{
			//cadastrar
			case 1:
				{
					if (posi == tam)
					  {
					  	printf("Todas as contas ja foram cadastradas [vetor cheio]\n");
					  }
					else
					  {
					  	printf("Digite o numero da conta a ser incluida: ");
					  	scanf("%d",&num_conta);
					  	fflush(stdin);
					  	
					  	achou = busca(conta,num_conta,posi);
					  	
						if (achou)
						  {
						  	printf("Ja existe conta cadastrada com esse numero\n");
						  }  
						else
						  {
						  	printf("Digite o nome do cliente: ");
						  	gets(nome_cliente);
						  	printf("Digite o saldo do cliente: ");
						  	scanf("%f",&saldo);
							cadastra(conta,num_conta,saldo,nome_cliente,&posi);
						  	printf("Conta cadastrada com sucesso\n");
						  }
					  }  
					break;
				}
			//visualizar
			case 2:
				{
					printf("Digite o nome do cliente a ser consultado: ");
					gets(nome_cliente);
					lista(conta,nome_cliente,posi);
					break;
				}
			//excluir
			case 3:
				{
					remove_menor_saldo(conta,&posi);
					break;
				}
			//sair
			case 4:
				{
					printf("Encerrando...\n");
					break;
				}
			default: printf("Opcao invalida\n");
		}
		
		getch();
		system("cls");
		
	}while(op != 4);
	
	getch();
}

////////////////////////////////////////////
int busca(banco *conta, int num_conta, int tam)
{
	int achou, i;
	
	achou = 0;
	for (i=0; i<tam; i++)
	  {
	  	if (num_conta == conta[i].num)
	  	  {
	  	  	achou = 1;
	  	  	break;
		  }
	  }
	
	return achou;
}

////////////////////////////////////////////
void cadastra(banco *conta, int num_conta, float saldo, char *nome, int *posi)
{
	conta[*posi].num = num_conta;
	strcpy(conta[*posi].nome,nome);
	conta[*posi].saldo = saldo;
	*posi = *posi + 1;
}

////////////////////////////////////////////
void lista(banco *conta, char *nome_cliente, int tam)
{
	int achou, i;
	
	//Quebrar essa função em duas: busca_cliente e o lista apenas
	achou = 0;
	for (i=0; i<tam; i++)
	  {
	  	if (strcmp(conta[i].nome,nome_cliente) == 0)
	  	  {
	  	  	printf("%d - %.2f\n",conta[i].num,conta[i].saldo);
	  	  	achou = 1;
		  }
	  }
	if (!achou)
	  {
	  	printf("Nao existe conta cadastrada para este cliente\n");
	  }
}

////////////////////////////////////////////
void remove_menor_saldo(banco* conta, int *posi)
{
	int i, pos, menor_saldo;
	
	if (*posi == 0)
	  printf("Nenhuma conta foi cadastrada\n");
	else
	  {
	  	//busca pelo menor saldo
		menor_saldo = conta[0].saldo;
	  	pos = 0;
	  	for (i=1; i<*posi; i++)
	  	  {
	  	  	if (conta[i].saldo < menor_saldo)
	  	  	  {
	  	  	  	menor_saldo = conta[i].saldo;
	  	  	  	pos = i;
			  }
		  }
		  
		//remoção
		for (i=pos; i<*posi-1; i++)
		  {
		  	conta[i].num = conta[i+1].num;
		  	strcpy(conta[i].nome,conta[i+1].nome);
		  	conta[i].saldo = conta[i+1].saldo;
		  }
		  
		printf("Conta excluida com sucesso\n");
		*posi = *posi - 1;
	  }
}

