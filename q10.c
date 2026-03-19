#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

//nome, cpf, idade, sexo e cpf
typedef struct {
		char nome[50];
		int idade;
		int cpf;
		char sexo;
	} Pessoa;

#define TAM 5

int main()
{
	// configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");
	
	//variaveis
	Pessoa pessoas[TAM];

	for(int i = 0; i < TAM; i++)
	{
		printf("Digite o nome da pessoa %d: ", i + 1);
		fgets(pessoas[i].nome, 50, stdin);

		printf("Digite a idade da pessoa %d: ", i + 1);
		scanf("%d", &pessoas[i].idade);

		printf("Digite a cpf da pessoa %d: ", i + 1);
		scanf("%d", &pessoas[i].cpf);

		printf("Digite a sexo da pessoa %d: ", i + 1);
		scanf(" %c", &pessoas[i].sexo);

		getchar(); 
	}

	for(int i = 0; i < TAM; i++)
	{
		printf("\nPessoa %d: \n", i + 1);
		printf("Nome: %s", pessoas[i].nome);
		printf("Idade: %d\n", pessoas[i].idade);
		printf("Cpf: %d\n", pessoas[i].cpf);
		printf("Sexo: %c\n", pessoas[i].sexo);
	}
	
  //fim do codigo
  return 0;    
}