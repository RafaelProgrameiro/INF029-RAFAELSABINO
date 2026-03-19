#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
	// configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");
	
	//variaveis
  int idade = 0;

  do
  {
    printf("Digite uma idade: ");
    scanf("%d", &idade);

    if(idade >= 18)
      printf("a pessoa é de maior\n");
    else
      printf("a pessoa e de menor\n");
  }
  while (idade >= 0);

  //fim do codigo
  return 0;    
}