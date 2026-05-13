#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAVIOS 5
#define NAVIO_GIGANTE 4
#define NAVIO_GRANDE 3
#define NAVIO_MEDIO 2
#define NAVIO_PEQUENO 1

typedef struct Jogador{
  char tabuleiro[10][10];
  int qtdNavios;  
} Jogador;

Jogador preencherTabuleiro(Jogador jogador);
Jogador criarTabuleiroVazio(Jogador jogador);
void imprimirTabuleiro(Jogador jogador);
void imprimirTabuleiroInimigo(Jogador jogador);
int linhaNum(char posicao);
int colunaNum(char posicao);
int sentidoNavio();
Jogador posicionarNaHorizontal(Jogador jogador, int linha, int coluna, int tamanho);
Jogador posicionarNaVertical(Jogador jogador, int linha, int coluna, int tamanho);
bool jogoEncerrado(Jogador jogador);

int main()
{   
  Jogador jogador1;
  Jogador jogador2;
  int jogada = 0;
  int acao;
  bool encerrado = false;

  jogador1 = criarTabuleiroVazio(jogador1);
  jogador2 = criarTabuleiroVazio(jogador2);

  printf("######BATALHA NAVAL######\n");

  printf("\n##Jogador 1 - Preparação do tabuleiro##\n");
  jogador1 = preencherTabuleiro(jogador1); 

  printf("\n##Jogador 2 - Preparação do tabuleiro##\n");
  jogador2 = preencherTabuleiro(jogador2);  

  while(!encerrado)
  {
    printf("\n##Jogador %d - Ações##\n", (jogada % 2) + 1);
    printf("1 - Ver tabuleiro\n");
    printf("2 - Ver tabuleiro do inimigo\n");
    printf("3 - Realizar ataque\n");
    printf("4 - Encerrar rodada\n");

    scanf("%d", &acao);
    getchar();
    switch(acao)
    {
      case 1:
      {
        if(jogada % 2 == 0)
          imprimirTabuleiro(jogador1);
        else
          imprimirTabuleiro(jogador2);
        break;
      } 
      case 2:
      {
        if(jogada % 2 == 0)
          imprimirTabuleiroInimigo(jogador2);
        else
          imprimirTabuleiroInimigo(jogador1);
        break;
      } 
      case 3: 
      {
        char posicao[10];
        int linha, coluna;
        printf("Digite a posição para o ataque (ex: B5): ");
        fgets(posicao, 10, stdin);
    
        posicao[strcspn(posicao, "\n")] = 0;
    
        if (strlen(posicao) != 2) 
        {        
          printf("Posição inválida, tente novamente.\n");
          continue;
        }
    
        linha = linhaNum(posicao[0]);
        if(linha == -1)
          continue;
    
        coluna = colunaNum(posicao[1]);
        if(coluna == -1)
          continue;

        if(jogada % 2 == 0)
        {
          if(jogador2.tabuleiro[linha][coluna] == 'O' || jogador2.tabuleiro[linha][coluna] == 'X')
          {
            printf("Esta posição já foi atacada, tente novamente\n");
            continue;
          } 
          
          if(jogador2.tabuleiro[linha][coluna] == 'N')
          {
            jogador2.tabuleiro[linha][coluna] = 'O';
            printf("Acertou!\n");
          }
          else
          {
            jogador2.tabuleiro[linha][coluna] = 'X';
            printf("Errou!\n");
          }

          if(jogoEncerrado(jogador2))
          {
            printf("\n##Vitória do Jogador 1##\n");
            encerrado = true;
          }
        }
        else
        {
          if(jogador1.tabuleiro[linha][coluna] == 'O' || jogador1.tabuleiro[linha][coluna] == 'X')
          {
            printf("Esta posição já foi atacada, tente novamente\n");
            continue;
          } 
          
          if(jogador1.tabuleiro[linha][coluna] == 'N')
          {
            jogador1.tabuleiro[linha][coluna] = 'O';
            printf("Acertou!\n");
          }
          else
          {
            jogador1.tabuleiro[linha][coluna] = 'X';
            printf("Errou!\n");
          }

          if(jogoEncerrado(jogador1))
          {
            printf("\n##Vitória do Jogador 2##\n");
            encerrado = true;
          }
        }
        break;
      }
      case 4: printf("Passando a vez para o oponente... \n"); jogada++; break;
      default: printf("Ação inválida, tente novamente.\n"); break;
    }
  }
}

Jogador preencherTabuleiro(Jogador jogador)
{
  bool preparado = false;
  bool navioGigante = false;
  bool navioGrande = false;
  int navioPequeno = 0;
  char posicao[10];
  int direcaoNavio;
  int linha, coluna;

  while(!preparado)
  { 
    if(!navioGigante)
    {      
      printf("Digite a posição inicial do Navio Gigante - 4 espaços (ex: B5): ");
      fgets(posicao, 10, stdin);
  
      posicao[strcspn(posicao, "\n")] = 0;
  
      if (strlen(posicao) != 2) 
      {        
        printf("Posição inválida, tente novamente.\n");
        continue;
      }
  
      linha = linhaNum(posicao[0]);
      if(linha == -1)
        continue;
  
      coluna = colunaNum(posicao[1]);
      if(coluna == -1)
        continue;
  
      if (jogador.tabuleiro[linha][coluna] == 'N')
      {
        printf("Esta jogada ja está ocupada, tente novamente.\n");
        continue;
      }

      direcaoNavio = sentidoNavio();
  
      if(direcaoNavio == 1)
      {
        jogador = posicionarNaHorizontal(jogador, linha, coluna, NAVIO_GIGANTE);
        if(jogador.qtdNavios == -1)
          continue;
      }
  
      if(direcaoNavio == 2)
      {
        jogador = posicionarNaVertical(jogador, linha, coluna, NAVIO_GIGANTE);
        if(jogador.qtdNavios == -1)
          continue;
      }
      navioGigante = true;
    }

    if(!navioGrande)
    {
      printf("Digite a posicao inicial do Návio Grande - 3 espaços (ex: B5): ");
      fgets(posicao, 10, stdin);
  
      posicao[strcspn(posicao, "\n")] = 0;
  
      if (strlen(posicao) != 2) 
      {
        printf("Posição inválida, tente novamente.\n");
        continue;
      }
  
      linha = linhaNum(posicao[0]);
      if(linha == -1)
        continue;
  
      coluna = colunaNum(posicao[1]);
      if(coluna == -1)
        continue;
  
      if (jogador.tabuleiro[linha][coluna] == 'N')
      {
        printf("Esta jogada ja está ocupada, tente novamente.\n");
        continue;
      }
  
      direcaoNavio = sentidoNavio();
  
      if(direcaoNavio == 1)
      {
        jogador = posicionarNaHorizontal(jogador, linha, coluna, NAVIO_GRANDE);
        if(jogador.qtdNavios == -1)
          continue;
      }
  
      if(direcaoNavio == 2)
      {
        jogador = posicionarNaVertical(jogador, linha, coluna, NAVIO_GRANDE);
        if(jogador.qtdNavios == -1)
          continue;
      }
      navioGrande = true;
    }

    if(NAVIOS > 5)
    {
      int navioMedio = 0;
      while(navioMedio < NAVIOS - 5)
      {
        printf("Digite a posicao inicial do Návio Médio - 2 espaços (ex: B5): ");
        fgets(posicao, 10, stdin);
    
        posicao[strcspn(posicao, "\n")] = 0;
    
        if (strlen(posicao) != 2) 
        {
          printf("Posição inválida, tente novamente.\n");
          continue;
        }
    
        linha = linhaNum(posicao[0]);
        if(linha == -1)
          continue;
    
        coluna = colunaNum(posicao[1]);
        if(coluna == -1)
          continue;
    
        if (jogador.tabuleiro[linha][coluna] == 'N')
        {
          printf("Esta jogada ja está ocupada, tente novamente.\n");
          continue;
        }
    
        direcaoNavio = sentidoNavio();
    
        if(direcaoNavio == 1)
        {
          jogador = posicionarNaHorizontal(jogador, linha, coluna, NAVIO_MEDIO);
          if(jogador.qtdNavios == -1)
            continue;
        }
    
        if(direcaoNavio == 2)
        {
          jogador = posicionarNaVertical(jogador, linha, coluna, NAVIO_MEDIO);
          if(jogador.qtdNavios == -1)
            continue;
        } 
        navioMedio++;
      }
    }

    while(navioPequeno < 3)
    {
      printf("Digite a posicao inicial do Navio Pequeno '%d' - 1 espaço (ex: B5): ", navioPequeno + 1);
      fgets(posicao, 10, stdin);
  
      posicao[strcspn(posicao, "\n")] = 0;
  
      if (strlen(posicao) != 2) 
      {
        printf("Posição inválida, tente novamente.\n");
        continue;
      }
  
      linha = linhaNum(posicao[0]);
      if(linha == -1)
        continue;
  
      coluna = colunaNum(posicao[1]);
      if(coluna == -1)
        continue;
  
      if (jogador.tabuleiro[linha][coluna] == 'N')
      {
        printf("Esta jogada ja está ocupada, tente novamente.\n");
        continue;
      }

      jogador.tabuleiro[linha][coluna] = 'N';
      
      navioPequeno++;
    }
    preparado = true;    
  }
  jogador.qtdNavios = NAVIOS;
  return jogador;
}

Jogador criarTabuleiroVazio(Jogador jogador)
{
  for(int i = 0; i < 10; i++) 
    for(int j = 0; j < 10; j++)    
      jogador.tabuleiro[i][j] = ' ';

  return jogador;
}

void imprimirTabuleiro(Jogador jogador)
{
  printf("   ");
  
  for(int i = 0; i < 10; i++)
    printf(" %d ", i);

  printf("\n");

  for(int i = 0; i < 10; i++)
  {    
    printf(" %c ", 'A' + i);

    for(int j = 0; j < 10; j++)    
      printf("[%c]", jogador.tabuleiro[i][j]);

    printf("\n");
  }
}

void imprimirTabuleiroInimigo(Jogador jogador)
{
  printf("   ");

  for(int i = 0; i < 10; i++)
    printf(" %d ", i);

  printf("\n");

  for(int i = 0; i < 10; i++)
  {
    printf(" %c ", 'A' + i);

    for(int j = 0; j < 10; j++)
    {
      if(jogador.tabuleiro[i][j] == 'N')
        printf("[ ]");
      else
        printf("[%c]", jogador.tabuleiro[i][j]);
    }

    printf("\n");
  }
}

int linhaNum(char posicao)
{
  int linha;
  switch(posicao)
  {
    case 'A': linha = 0; break;
    case 'B': linha = 1; break;
    case 'C': linha = 2; break;
    case 'D': linha = 3; break;
    case 'E': linha = 4; break;
    case 'F': linha = 5; break;
    case 'G': linha = 6; break;
    case 'H': linha = 7; break;
    case 'I': linha = 8; break;
    case 'J': linha = 9; break;
    default: printf("Posição inválida, tente novamente.\n"); linha = -1; break;
  }

  return linha;
}

int colunaNum(char posicao)
{
  int coluna;
  switch(posicao)
  {
    case '0': coluna = 0; break;
    case '1': coluna = 1; break;
    case '2': coluna = 2; break;
    case '3': coluna = 3; break;
    case '4': coluna = 4; break;
    case '5': coluna = 5; break;
    case '6': coluna = 6; break;
    case '7': coluna = 7; break;
    case '8': coluna = 8; break;
    case '9': coluna = 9; break;
    default: printf("Posição inválida, tente novamente.\n"); coluna = -1; break;
  }

  return coluna;
}

int sentidoNavio()
{
  int direcaoNavio;
  bool valido = false;

  while(!valido)
  {
    printf("Posição do Navio:\n");
    printf("1 - horizontal || 2 - vertical: ");

    scanf("%d", &direcaoNavio);
    getchar();

    if(direcaoNavio != 1 && direcaoNavio != 2)
      printf("Direção inválida, tente novamente\n");
    else
      valido = true;
  }
  return direcaoNavio;
}

Jogador posicionarNaHorizontal(Jogador jogador, int linha, int coluna, int tamanho)
{   
  if(coluna + tamanho - 1 > 9)
  {
    printf("Este navio não cabe nessa posição, tente novamente.\n");
    jogador.qtdNavios = -1;
    return jogador;
  }

  for(int i = 0; i < tamanho; i++)  
    if(jogador.tabuleiro[linha][coluna + i] == 'N')
    {
      printf("Este navio não cabe nessa posição, tente novamente.\n");
      jogador.qtdNavios = -1;
      return jogador;
    }
  

  for(int i = 0; i < tamanho; i++)  
    jogador.tabuleiro[linha][coluna + i] = 'N';
  
  jogador.qtdNavios = 0;
  return jogador;
}

Jogador posicionarNaVertical(Jogador jogador, int linha, int coluna, int tamanho)
{   
  if(linha + tamanho - 1 > 9)
  {
    printf("Este navio não cabe nessa posição, tente novamente.\n");
    jogador.qtdNavios = -1;
    return jogador;
  }

  for(int i = 0; i < tamanho; i++)  
    if(jogador.tabuleiro[linha + i][coluna] == 'N')
    {
      printf("Este navio não cabe nessa posição, tente novamente.\n");
      jogador.qtdNavios = -1;
      return jogador;
    }
  

  for(int i = 0; i < tamanho; i++)  
    jogador.tabuleiro[linha + i][coluna] = 'N';
  
  jogador.qtdNavios = 0;
  return jogador;
}

bool jogoEncerrado(Jogador jogador)
{
  bool todosAbatidos;
  for(int i = 0; i < 10; i++)  
    for(int j = 0; j < 10; j++)    
      if(jogador.tabuleiro[i][j] == 'N')      
        return false;
  
  return true;
}