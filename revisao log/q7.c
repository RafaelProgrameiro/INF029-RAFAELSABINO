#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
	// configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");
	
	//variaveis
  int numero;
  bool ePrimo = true;
  printf("digite um numero: ");
  scanf("%d", &numero);

  for(int i = 2; i < numero; i++)
  {
    if(numero % i == 0)
    {
      ePrimo = false;
      break;
    }     
  }
  if (ePrimo)
    printf("O numero é primo\n");
  else
    printf("O numero nao é primo\n");

  //fim do codigo
  return 0;    
}