/*
Controle de Estoque
Criar um programa para manter um controle de estoque com as seguintes informa��es 
para cada item: Nome, Quantidade, Pre�o, emUso (indica se no vetor uma determinada posi��o esta em 
uso (1) ou n�o (0))
Criar as seguintes fun��es:
a. inicializaEstoque: inicializa o vetor usado para armazenar os itens do estoque
b. cadastraItem: cadastra um item para posteriormente ser inclu�do no estoque
c. imprimeItem: imprime os dados de um item
d. imprimeEstoque: imprime os dados de todos os itens do estoque
e. insereItem: insere um novo item no estoque, se houver espaco dispon�vel
f. removeItem: remove um item de nome dado, se ele estiver no estoque
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <conio.h>

typedef struct {
     char nome[50];
     int quantidade;
     float preco;
     int emUso;
} Item;

///////////////////////////////
void inicializaEstoque(Item *estoque, int tam);
void cadastraItem(Item *item);
void imprimeItem(Item item);
void imprimeEstoque(Item *estoque, int tam);
int insereItem(Item *estoque, int tam, Item item);
int removeItem(Item *estoque, int tam, char *nome);
///
int buscaItem(Item *estoque, int tam, char *nome);
void compacta(Item *estoque, int tam);
int incrementaItem(Item *estoque, int tam, char *nome, int inc);

///////////////////////////////
int main()
{
	const int tam=15;
	Item estoque[tam];
	int opcao, ret;
	
	inicializaEstoque(estoque,tam);
	
	do
	{
		printf("1: Insere Item\n");
		printf("2: Remove Item\n");
		printf("3: Imprime Estoque\n");
		printf("4: Busca Item\n");
		printf("5: Compacta\n");
		printf("6: Incrementa Item\n");
		printf("7: Sair\n");
		printf("Opcao: ");
		scanf("%d",&opcao);
		getchar(); // Limpa o buffer de entrada para evitar problemas com fgets
		system("clear");//for windows use system("cls");

		switch(opcao)
		{
			//insere item
			case 1:
				{
					Item i;
					cadastraItem(&i);
					ret = insereItem(estoque,tam,i);
					if (ret)
					  printf("Inserido com sucesso\n");
					else printf("Item nao inserido (falha)\n");
					break;
				}
			//remove item
			case 2:
				{
					char nome[50];
					printf("nome do item a ser removido: ");
					fgets(nome, sizeof(nome), stdin);
					getchar();

					ret = removeItem(estoque,tam,nome);
					if (ret)
					  printf("Removido com sucesso\n");
					else printf("Item nao removido (falha)\n");
					break;
				}
			//imprime estoque
			case 3:
				{
					imprimeEstoque(estoque,tam);
					break;
				}
			//busca item
			case 4:
				{
					char nome[50];
					printf("nome do item a ser procurado: ");
					fgets(nome, sizeof(nome), stdin);
					

					ret = buscaItem(estoque,tam,nome);
					if (ret!=-1)
					  printf("Item encontrado na pos: %d\n",ret);
					else printf("Item nao encontrado\n");
					break;
				}
			//compacta
			case 5:
				{
					compacta(estoque,tam);
					break;
				}
			//incrementa
			case 6:
				{
					char nome[50];
					int inc;
					
					printf("nome do item a ser procurado: ");
					fgets(nome, sizeof(nome), stdin);
					getchar();

					printf("qtdade a ser incrementada: ");
					scanf("%d",&inc);
					fflush(stdin);
					
					ret = incrementaItem(estoque,tam,nome,inc);
					if (ret!=-1)
					  printf("Item incrementado\n");
					else printf("Item nao encontrado\n");
					break;
				}
			//sair
			case 7:
				{
					printf("Encerrando\n");
					break;
				}
			default: printf("Opcao invalida\n");
		}
		
		//getch();
		//system("clear");//for windows use system("cls");
		
	}while (opcao!=7);
	
	//getch();
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void inicializaEstoque(Item *estoque, int tam)
{
  int i;
  /* Inicialmente nenhuma posicao do estoque esta em uso */
  for (i=0; i<tam; i++)
    estoque[i].emUso = 0;
}

//////////////////////////
void imprimeItem(Item item)
{
  printf("----- Imprimindo Item -----\n");
  printf("Nome: %s\n", item.nome);
  printf("Quantidade: %d\n", item.quantidade);
  printf("Preco: R$%0.2f\n", item.preco);
}

void imprimeEstoque(Item *estoque, int tam)
{
  int i;
  
  for (i=0; i<tam; i++)
  {
  	/* Se a posicao i estiver em uso, imprime o item */
    if (estoque[i].emUso)
      imprimeItem(estoque[i]);
  }
}

//////////////////////////
void cadastraItem(Item *item)
{
   printf("----- Cadastrando um Item -----\n");
   printf("Digite o nome do item: ");
   fgets(item->nome, sizeof(item->nome), stdin);
   ///getchar(); // Limpa o buffer de entrada para evitar problemas com fgets
   printf("Digite a quantidade do item: ");
   scanf("%d", &(item->quantidade));
   printf("Digite o preco do item: ");
   scanf("%f", &(item->preco));
}

int insereItem(Item *estoque, int tam, Item item)
{
   int i;
   
   for (i=0; i<tam; i++)
   {
   	 /* Se a posicao i nao estiver em uso ... */
     if (estoque[i].emUso == 0)
	 {
		estoque[i] = item;
        /* ... a posicao i passa a estar em uso */
        estoque[i].emUso = 1;
        
        /* Item inserido com sucesso */
        return 1;
     }
   }
   
   /* Nao foi possivel inserir o item */
   return 0;
}

//////////////////////////
int buscaItem(Item *estoque, int tam, char *nome)
{
	int i;
  
    for (i=0; i<tam; i++)
    {
      /* Se achou o item no estoque... */
      if ((estoque[i].emUso) && (strcmp(estoque[i].nome, nome) == 0))
	  {  
         /* Item encontrado na pos i+1*/
         return i+1;
      }else{
		printf("Item nao encontrado\n");
	  }
	}
  
  /* Nao foi possivel encontrar o item */
  
  return -1;
}

//////////////////////////
int removeItem(Item *estoque, int tam, char *nome)
{
  int i;
  
  for (i=0; i<tam; i++)
    {
      /* Se achou o item no estoque... */
      if ((estoque[i].emUso) && (strcmp(estoque[i].nome, nome) == 0))
	  {
         /* ... remove o item do estoque */
         estoque[i].emUso = 0;
         
         /* Item removido com sucesso */
         return 1;
      }
	}
  
  /* Nao foi possivel remover o item */
  return 0;
}

//////////////////////////
void compacta(Item *estoque, int tam)
{
   int i,j=0;
   Item aux[tam];
   
   inicializaEstoque(aux,tam);
   for (i=0; i<tam; i++)
   {
   	 /* Se a posicao i estiver em uso ... */
     if (estoque[i].emUso == 1)
	 {
		aux[j] = estoque[i];
		j++;
     }
   }
   
   inicializaEstoque(estoque,tam);
   for (i=0; i<tam; i++)
   {
   	 estoque[i] = aux[i];
   }
}

//////////////////////////
int incrementaItem(Item *estoque, int tam, char *nome, int inc)
{
	int ret;
	
	ret = buscaItem(estoque,tam,nome);
	if (ret != -1)
	  estoque[ret-1].quantidade = estoque[ret-1].quantidade + inc;
	
	return ret;
}

