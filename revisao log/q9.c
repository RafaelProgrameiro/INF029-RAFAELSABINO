#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

#define TAM 10
int main()
{
	// configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");
	
	//variaveis
  int numeros[TAM];
  int numero;
  bool ePrimo;
  int acumulador = 0;
  

  for(int i = 0; i < TAM; i++)
  {
    ePrimo = true;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    for(int j = 2; j < numero; j++)
    {
      if(numero % j == 0)
      {
        ePrimo = false;
        break;
      }
    }
    if(ePrimo)
      numeros[i] = numero;
    else
      numeros[i] = 0;    
  }

  printf("numeros primos: \n");
  for(int i = 0; i < TAM; i++)
  {
    if(numeros[i] > 0)
    {
      printf("%d, ", numeros[i]);
      acumulador += numeros[i];
    }
  }    
  printf("\n");
  printf("%d\n", acumulador);  

  //fim do codigo
  return 0;    
}