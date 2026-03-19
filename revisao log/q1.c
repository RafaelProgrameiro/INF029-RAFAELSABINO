#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main() {
  // configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");

  
  printf("Rafael Sabino\n");
  printf("Matricula: 2025216003\n");
  printf("Semestre: 2026.1\n");

  //fim do codigo
  return 0;
}