#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main()
{
	// configuracao da localizacao para acentuacao das palavras
	setlocale(LC_ALL, "Portuguese");
	
	//variaveis
  int idade1, idade2;

    printf("Digite a primeira idade: ");
    scanf("%d", &idade1); //20
  
    printf("Digite a segunda idade: ");
    scanf("%d", &idade2); //30

    idade1 = idade1 + idade2; //20 + 30 = 50
    idade2 = idade1 - idade2; // 50 - 30 = 20
    idade1 = idade1 - idade2; // 50 - 20 = 30

    printf("A idade1 agora é %d e a idade2 agora é %d\n", idade1, idade2);
    
  //fim do codigo
  return 0;    
}