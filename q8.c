#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
	// configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");
	
	//variaveis
  int numero;
  int acumulador = 1;
  printf("digite um numero: ");
  scanf("%d", &numero);

  for(int i = 1; i <= numero; i++)
  {
    acumulador *= i;    
  }
  printf("fatorial de %d é: %d\n", numero, acumulador);

  //fim do codigo
  return 0;    
}