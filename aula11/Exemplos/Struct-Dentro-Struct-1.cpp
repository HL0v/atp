#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>

////////////////////////
typedef struct
{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct S_Pessoa
{
	char cpf[15];
	char nome[50];
	Data nascimento;
} Pessoa;

int main()
{	
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	Pessoa Joao;
	
	//strcpy, strcmp
	strcpy(Joao.cpf,"123.321.789-12");//Joao.cpf = "123.321.789-12";
	strcpy(Joao.nome,"Joao da Silva");
	Joao.nascimento.dia = 5;
	Joao.nascimento.mes = 2;
	Joao.nascimento.ano = 2000;
	printf("Dados do %s: %s ",Joao.nome,Joao.cpf);
	printf("%d/%d/%d\n\n",Joao.nascimento.dia,Joao.nascimento.mes,Joao.nascimento.ano);
		
	//getch();
}

