#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
	// configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");
	
	//variaveis
  int idade;

    printf("Digite a primeira idade: ");
    scanf("%d", &idade);
  
    if(idade >= 18)
      printf("a pessoa é maior\n");
    else 
      printf("a pessoa é menor\n");
    
  //fim do codigo
  return 0;    
}