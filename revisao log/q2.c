#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main() {
  // configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");

  //variaveis
  int idade1;
  int idade2;

  printf("Digite a primeira idade: ");
  scanf("%d", &idade1);
  
  printf("Digite a segunda idade: ");
  scanf("%d", &idade2);

  printf("a soma de %d e %d é: %d\n", idade1, idade2, idade1 + idade2);
  
  //fim do codigo
  return 0;
}