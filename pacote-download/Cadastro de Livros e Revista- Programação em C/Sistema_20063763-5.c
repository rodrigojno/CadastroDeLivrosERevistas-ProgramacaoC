#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100

typedef struct cadastro
{
	int tipo;
	char titulo[50];
	char autor[50];
	char editora[20];
	char isbn[20];
	int edicao;
	int ano;
	int quantidadeExemplares;
	int caixa;
} obra;

int i=0;

void identificacao();
void cadastrarLivro(obra obras[]);
void cadastrarRevista(obra obras[]);
void listarLivro(int tipo, obra obras[]);
void listarRevista(int tipo, obra obras[]);
void listarObrasCaixa(int caixa, obra obras[]);
int ler_arquivo(obra obras[]);

int main(){
	setlocale(LC_ALL,"");
	obra obras[MAX];
	int op, tipo, caixa;
	char resp;
		
	do{
	system("cls");
		identificacao();
		printf("\n1 - Cadastrar Obras");
		printf("\n2 - Listar todos os Livros");
		printf("\n3 - Listar todas as Revistas");
		printf("\n4 - Listar Obras por caixa");
		printf("\n0 - Sair");
		printf("\nEscolha Opção: ");
		fflush(stdin);
		scanf("%d", &op);
		
	switch(op){
		case 1:
			resp= 's';
			while ((resp=='s') || (resp=='S')){
			i++;
			system("cls");
			
			printf("\nInforme o Tipo da obra para cadastrar, [1] Livro | [2] Revista: ");
			fflush(stdin);
			scanf("%d", &obras[i].tipo);
			
				if(obras[i].tipo == 1){
					cadastrarLivro(obras);
				}
				else{
					if(obras[i].tipo == 2){
						cadastrarRevista(obras);
					}
					else{
						printf("\nDigite uma opção válida!");
					}
				}
			
			printf("\nDeseja cadastrar nova obra? [s] Sim | [n] Não: ");
			fflush(stdin);
			scanf("%c", &resp);
			}
			break;
		case 2:
			system("cls");
			tipo = 1;
			listarLivro(tipo, obras);
			break;
		case 3:
			system("cls");
			tipo = 2;
			listarRevista(tipo, obras);
			break;
		case 4:
			system("cls");
			printf("\nInforme o número da caixa a ser pesquisada: ");
			fflush(stdin);
			scanf("%d", &caixa);			
			listarObrasCaixa(caixa, obras);
			break;
		case 0:
			printf("\nSaindo do sistema!!!");
			break;
		default:
			printf("\nValor indefinido. Digite um valor válido!\n");
			system("pause");
			break;
		}
	}while(op!=0);
	return 0;
}

void identificacao(){
	system("cls");
	int t;
	for(t=0; t<80; t++) printf("-");
		printf("\n >>>> RODRIGO JUNQUEIRA NUNES DE OLIVEIRA <<<<");
		printf("\n >>>> RA: 20063763-5 <<<< ");
		printf("\n >>>> Engenharia de Software <<<< \n");
	for(t=0; t<80; t++) printf("-");
}

void cadastrarLivro(obra obras[]){
	identificacao();
	FILE * arq;
	arq = fopen("arquivo.txt", "a+");
	if(arq != NULL)
	{
		printf("\n\nInforme o Título: ");
		fflush(stdin);
		gets(obras[i].titulo);
		printf("\nInforme o Autor: ");
		fflush(stdin);
		gets(obras[i].autor);
		printf("\nInforme a Editora: ");
		fflush(stdin);
		gets(obras[i].editora);	
		printf("\nInforme o ISBN: ");
		fflush(stdin);
		gets(obras[i].isbn);
		printf("\nInforme a Edição: ");
		fflush(stdin);
		scanf("%d", &obras[i].edicao);
		printf("\nInforme a Ano: ");
		fflush(stdin);
		scanf("%d", &obras[i].ano);
		printf("\nInforme a quantidade de exemplares: ");
		fflush(stdin);
		scanf("%d", &obras[i].quantidadeExemplares);
		printf("\nInforme a caixa: ");
		fflush(stdin);
		scanf("%d", &obras[i].caixa);
		
		fwrite(&obras[i], sizeof(obra), 1, arq);
		fclose(arq);		
	}
	else{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}

void cadastrarRevista(obra obras[]){
	identificacao();
	FILE * arq;
	arq = fopen("arquivo.txt", "a+");
	if(arq != NULL)
	{
		printf("\n\nInforme o Título: ");
		fflush(stdin);
		gets(obras[i].titulo);
		printf("\nInforme o Autor: ");
		fflush(stdin);
		gets(obras[i].autor);
		printf("\nInforme a Editora: ");
		fflush(stdin);
		gets(obras[i].editora);	
		printf("\nInforme o ISBN: ");
		fflush(stdin);
		gets(obras[i].isbn);
		printf("\nInforme a Edição: ");
		fflush(stdin);
		scanf("%d", &obras[i].edicao);
		printf("\nInforme a Ano: ");
		fflush(stdin);
		scanf("%d", &obras[i].ano);
		printf("\nInforme a quantidade de exemplares: ");
		fflush(stdin);
		scanf("%d", &obras[i].quantidadeExemplares);
		printf("\nInforme a caixa: ");
		fflush(stdin);
		scanf("%d", &obras[i].caixa);
		
		fwrite(&obras[i], sizeof(obra), 1, arq);
		fclose(arq);		
	}
	else{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}

int ler_arquivo(obra obras[]){
	FILE * arq = fopen("arquivo.txt", "r");
	if(arq != NULL){
		int contador = 0;
		while(1){
			obra k;
			int cadastro = fread(&k, sizeof(obra), 1, arq);
			if(cadastro < 1)
				break;
			else
				obras[contador] = k;
				contador++;
		}
		fclose(arq);
		return contador;
	}
	else{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1);
	}
}

void listarLivro(int tipo, obra obras[]){
	identificacao();
	FILE * arq;
	arq = fopen ("arquivo.txt", "r");
	fread(obras, sizeof (int), 10, arq);
	int leituraObras = ler_arquivo(obras);
	int i;
	char livro = 'f';
	int totalLivro = 0;	
	int m;
	printf("\n>>>> Lista de Livros <<<<\n");
	for(i = 0; i < leituraObras; i++){
		if(obras[i].tipo == tipo){
			printf("\n\nItem: %d\t\t", i+1);
			printf("Título: %s\n", obras[i].titulo);
			printf("Autor: %s\t\t", obras[i].autor);
			printf("Editora: %s\n", obras[i].editora);
			printf("ISBN: %s\t\t", obras[i].isbn);
			printf("Edição: %d\t\t", obras[i].edicao);
			printf("Ano: %d\n", obras[i].ano);
			printf("Quantidade de Exemplares: %d\t\t", obras[i].quantidadeExemplares);
			printf("Caixa: %d\n\n", obras[i].caixa);
			livro = 's';
			if (livro == 's'){
			totalLivro = totalLivro + 1;
			}			
			
			for(m=0; m<80; m++) printf("*");
		}
	}
	printf("\nConstam cadastrados %d livros nas caixas.\n", totalLivro);
	printf("\n");
	system("pause");
	fclose(arq);
	getch();
}

void listarRevista(int tipo, obra obras[]){
	identificacao();
	FILE * arq;
	arq = fopen ("arquivo.txt", "r");
	fread(obras, sizeof (int), 10, arq);
	int leituraObras = ler_arquivo(obras);
	int i;
	char revista = 'f';
	int totalRevista = 0;
	int m;
	printf("\n>>>> Lista de Revistas <<<<\n");
	for(i = 0; i < leituraObras; i++){
			if(obras[i].tipo == tipo){
			printf("\n\nItem: %d\t\t", i+1);
			printf("Título: %s\n", obras[i].titulo);
			printf("Autor: %s\t\t", obras[i].autor);
			printf("Editora: %s\n", obras[i].editora);
			printf("ISBN: %s\t\t", obras[i].isbn);
			printf("Edição: %d\t\t", obras[i].edicao);
			printf("Ano: %d\n", obras[i].ano);
			printf("Quantidade de Exemplares: %d\t\t", obras[i].quantidadeExemplares);
			printf("Caixa: %d\n\n", obras[i].caixa);
			revista = 's';
			if (revista == 's'){
			totalRevista = totalRevista + 1;
			}
	
		for(m=0; m<80; m++) printf("*");
		}
	}
	printf("\nConstam cadastradas %d revistas nas caixas.\n", totalRevista);
	printf("\n");
	system("pause");
	fclose(arq);
	getch();
}

void listarObrasCaixa(int caixa, obra obras[]){
	identificacao();
	FILE * arq;
	arq = fopen ("arquivo.txt", "r");
	fread(obras, sizeof (int), 10, arq);
	int leituraObras = ler_arquivo(obras);
	int i;
	char semObra = 'f';
	int total = 0;
	int m;
	printf("\n>>>> Lista de Obras por caixa <<<<\n");
	printf("\nCaixa selecionada: %d", caixa);
	for(i = 0; i < leituraObras; i++){
			if(obras[i].caixa == caixa){
				if (obras[i].tipo == 1){
					printf("\n\nLivro");
				}
				else{printf("\n\nRevista");
				}
			printf("\nItem: %d\t\t", i+1);
			printf("Título: %s\n", obras[i].titulo);
			printf("Autor: %s\t\t", obras[i].autor);
			printf("Editora: %s\n", obras[i].editora);
			printf("ISBN: %s\t\t", obras[i].isbn);
			printf("Edição: %d\t\t", obras[i].edicao);
			printf("Ano: %d\n", obras[i].ano);
			printf("Quantidade de Exemplares: %d\t\t", obras[i].quantidadeExemplares);
			printf("Caixa: %d\n\n", obras[i].caixa);
			semObra = 's';
			if (semObra =='s'){
				total = total + 1;
			}
			
		for(m=0; m<80; m++) printf("*");
		}
	}
	if(semObra != 's'){
		printf("\nNão há obras cadastradas!\n");
	}
	else{
		printf("\nConstam cadastradas %d obras na caixa.\n", total);
	}
	printf("\n");
	system("pause");
	fclose(arq);
	getch();
}
