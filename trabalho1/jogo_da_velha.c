#include <stdio.h>
#include <stdlib.h>

int main()
{
  char matriz[3][3] = {""};
  int encerrado = 0;
  int jogadaValida;
  int jogadas = 0;
  char jogada[10];
  int linhaNum, colunaNum;

  while(!encerrado && jogadas < 9)
  {
    printf("#####JOGO DA VELHA######\n");
    printf("      1    2    3\n");
    printf(" A  __%c__|__%c__|__%c__\n", matriz[0][0], matriz[0][1], matriz[0][2]);
    printf(" B  __%c__|__%c__|__%c__\n", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf(" C    %c  |  %c  |  %c  \n", matriz[2][0], matriz[2][1], matriz[2][2]);
    printf("########################\n");

    jogadaValida = 0;
    while (!jogadaValida) 
    {
      if(jogadas % 2 == 0)
        printf("Digite a jogada para o 'X' (A1, B2, C3): ");
      else
        printf("Digite a jogada para o 'O' (A1, B2, C3): ");
          
      fgets(jogada, sizeof(jogada), stdin);
  
      jogada[strcspn(jogada, "\n")] = 0;
  
      if (strlen(jogada) != 2) 
      {
        printf("Jogada inválida, tente novamente.\n");
        continue;
      }
  
      switch(jogada[0])
      {
        case 'A': linhaNum = 0; break;
        case 'B': linhaNum = 1; break;
        case 'C': linhaNum = 2; break;
        default: printf("Linha inválida, use A, B ou C.\n"); continue;
      }

      switch(jogada[1])
      {
        case '1': colunaNum = 0; break;
        case '2': colunaNum = 1; break;
        case '3': colunaNum = 2; break;
        default: printf("Coluna inválida, use 1, 2 ou 3.\n"); continue;
      }

      if(matriz[linhaNum][colunaNum] == 'X' || matriz[linhaNum][colunaNum] == 'O')
      {
        printf("Esta jogada ja foi realizada.\n");
        continue;
      }
      else
      {
        if(jogadas % 2 == 0)
          matriz[linhaNum][colunaNum] = 'X';
        else
          matriz[linhaNum][colunaNum] = 'O';
      }
      
      jogadaValida = 1;      
    }
    if
    (
      matriz[0][0] != '\0' && (matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2]) ||
      matriz[1][0] != '\0' && (matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2]) ||
      matriz[2][0] != '\0' && (matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2]) ||
      
      matriz[0][0] != '\0' && (matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0]) ||
      matriz[0][1] != '\0' && (matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1]) ||
      matriz[0][2] != '\0' && (matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2]) ||
      
      matriz[0][0] != '\0' && (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) ||
      matriz[2][0] != '\0' && (matriz[2][0] == matriz[1][1] && matriz[1][1] == matriz[0][2])
    )
    {
      if(jogadas % 2 == 0)
        printf("JOGO ENCERRADO! O 'X' GANHOU!\n");
      else
        printf("JOGO ENCERRADO! O 'O' GANHOU!\n");
          
      encerrado = 1;
        
    }
    
    jogadas++;
    if(jogadas == 9)
      printf("DEU VELHA!\n");
  }
  
  printf("#####JOGO DA VELHA######\n");
  printf("      1    2    3\n");
  printf(" A  __%c__|__%c__|__%c__\n", matriz[0][0], matriz[0][1], matriz[0][2]);
  printf(" B  __%c__|__%c__|__%c__\n", matriz[1][0], matriz[1][1], matriz[1][2]);
  printf(" C    %c  |  %c  |  %c  \n", matriz[2][0], matriz[2][1], matriz[2][2]);
  printf("########################\n");

  return 0;
}