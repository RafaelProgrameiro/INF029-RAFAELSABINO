#include <stdio.h>
#include <stdlib.h>

typedef struct Auxiliar{
  int *numeros;
  int tamanho;
  int qtdAtual;
} Auxiliar;

typedef struct Principal{
  Auxiliar *aux;
} Principal;

Principal *inicialiarPrincipal();
int menu(int opcao);
int receberPosicao();
void criarEstruturaAuxliar(Principal principal[], int posicao);
void inserirNumero(Principal principal[], int posicao);
void exibirTodasEstruturas(Principal principal[]);
void exibirAuxiliar(Auxiliar *aux);
void exibirTodosAuxiliaresOrdenados(Principal principal[]);
void exibirTodosOsNumerosOrdenados(Principal principal[]);
void ordenarVetor(int *ordenados[], int qtd);
void removerNumero(Principal principal[], int posicao);
void aumentarTamanhoAuxiliar(Principal principal[], int posicao);

int main()
{
  int opcao = -1;
  int posicao;
  int numero;
  Principal *principal;

  principal = inicialiarPrincipal();

  printf("\n##### Estrutura de Dados#####\n");
  
  while(opcao != 0)
  {
    opcao = menu(opcao);

    switch(opcao)
    {
      case 1:
      {
        printf("##1 - Inserir número##\n");

        posicao = receberPosicao();
        if(posicao == -1)
          break;

        if(principal[posicao].aux == NULL)
          criarEstruturaAuxliar(principal, posicao);

        if(principal[posicao].aux->qtdAtual == principal[posicao].aux->tamanho)
        {
          printf("\nA lista já está cheia. É necessario aumentar a lista antes de inserir um novo número\n");
          break;
        }

        inserirNumero(principal, posicao);

        printf("\n########################\n");

        break;
      } 
      case 2:
      {
        printf("##2 - Listar número de todas as estruturas##\n");
        
        exibirTodasEstruturas(principal);

        printf("\n########################\n");
        
        break;
      } 
      case 3:
      {
        printf("##3 - Listar números ordenados de cada estrutura##\n"); 
        
        exibirTodosAuxiliaresOrdenados(principal);

        printf("\n########################\n");
        
        break;
      } 
      case 4:
      {
        printf("##4 - Listar todos os números ordenados##\n");
        
        exibirTodosOsNumerosOrdenados(principal);

        printf("\n########################\n");
        
        break;        
      } 
      case 5:
      {
        printf("##5 - Remover um número##\n");
        
        posicao = receberPosicao();
        if(posicao == -1)
          break;

        if(principal[posicao].aux == NULL)
        {
          printf("\nNão existe estrutura auxiliar para essa posição\n");
          break;
        }

        removerNumero(principal, posicao);

        printf("\n########################\n");
        
        break;        
      } 
      case 6:
      {
        printf("##6 - Aumentar tamanho da estrutura auxiliar##\n");

        posicao = receberPosicao();
        if(posicao == -1)
          break;

        if(principal[posicao].aux == NULL)
        {
          printf("\nNão existe estrutura auxiliar para essa posição\n");
          break;
        }
        
        aumentarTamanhoAuxiliar(principal, posicao);

        printf("\n########################\n");

        break;
        }
      case 0: printf("0 - Sair\n"); break;
      default: printf("0 - Opção inválida\n"); break;
    }
  }

  for(int i = 0; i < 10; i++)
    if(principal[i].aux != NULL)
    {
      free(principal[i].aux->numeros);
      free(principal[i].aux);
    }
  free(principal);

  return 0;
}

Principal *inicialiarPrincipal()
{
  Principal *principal;
  principal = malloc(10 * sizeof(Principal));

  if(principal == NULL)
  {
    printf("Erro ao inicializar\n");
    return NULL;
  }

  for(int i = 0; i < 10; i++)
    principal[i].aux = NULL;

  principal[0].aux = malloc(sizeof(Auxiliar));
  principal[0].aux->tamanho = 2;
  principal[0].aux->numeros= malloc(principal[0].aux->tamanho * sizeof(int));
  principal[0].aux->qtdAtual = 0;
  principal[0].aux->numeros[principal[0].aux->qtdAtual] = 4;
  principal[0].aux->qtdAtual++;

  principal[1].aux = malloc(sizeof(Auxiliar));
  principal[1].aux->tamanho = 4;
  principal[1].aux->numeros= malloc(principal[1].aux->tamanho * sizeof(int));
  principal[1].aux->qtdAtual = 0;
  principal[1].aux->numeros[principal[1].aux->qtdAtual] = 5;
  principal[1].aux->qtdAtual++;
  principal[1].aux->numeros[principal[1].aux->qtdAtual] = 3;
  principal[1].aux->qtdAtual++;

  principal[3].aux = malloc(sizeof(Auxiliar));
  principal[3].aux->tamanho = 8;
  principal[3].aux->numeros= malloc(principal[3].aux->tamanho * sizeof(int));
  principal[3].aux->qtdAtual = 0;
  principal[3].aux->numeros[principal[3].aux->qtdAtual] = 2;
  principal[3].aux->qtdAtual++;
  principal[3].aux->numeros[principal[3].aux->qtdAtual] = 35;
  principal[3].aux->qtdAtual++;
  principal[3].aux->numeros[principal[3].aux->qtdAtual] = 23;
  principal[3].aux->qtdAtual++;

  principal[4].aux = malloc(sizeof(Auxiliar));
  principal[4].aux->tamanho = 3;
  principal[4].aux->numeros= malloc(principal[4].aux->tamanho * sizeof(int));
  principal[4].aux->qtdAtual = 0;
  principal[4].aux->numeros[principal[4].aux->qtdAtual] = 6;
  principal[4].aux->qtdAtual++;

  principal[6].aux = malloc(sizeof(Auxiliar));
  principal[6].aux->tamanho = 5;
  principal[6].aux->numeros= malloc(principal[6].aux->tamanho * sizeof(int));
  principal[6].aux->qtdAtual = 0;
  principal[6].aux->numeros[principal[6].aux->qtdAtual] = -1;
  principal[6].aux->qtdAtual++;
  principal[6].aux->numeros[principal[6].aux->qtdAtual] = 18;
  principal[6].aux->qtdAtual++;
  principal[6].aux->numeros[principal[6].aux->qtdAtual] = -16;
  principal[6].aux->qtdAtual++;

  return principal;
}

int menu(int opcao)
{  
  printf("1 - Inserir número\n");
  printf("2 - Listar número de todas as estruturas\n");
  printf("3 - Listar números ordenados de cada estrutura\n");
  printf("4 - Listar todos os números ordenados\n");
  printf("5 - Remover um número\n");
  printf("6 - Aumentar tamanho da estrutura auxiliar\n");
  printf("0 - Sair\n");
  
  scanf("%d", &opcao);
  
  return opcao;
}

int receberPosicao()
{
  int posicao;
  printf("Digite a posição da lista principal que será inserido o número: ");
  scanf("%d", &posicao);
  
  if(posicao <= 0 || posicao > 10)
  {
    printf("\nPosição inválida para o vetor principal\n");
    return -1;
  }

  posicao--;  
  return posicao;
}

void criarEstruturaAuxliar(Principal principal[], int posicao)
{
  int tamListaAux;
  printf("Lista auxiliar ainda não foi criada para esta posição, informe o tamanho da lista auxiliar: ");
  scanf("%d", &tamListaAux);

  principal[posicao].aux = malloc(sizeof(Auxiliar));
  principal[posicao].aux->tamanho = tamListaAux;
  principal[posicao].aux->numeros= malloc(principal[posicao].aux->tamanho * sizeof(int));
  principal[posicao].aux->qtdAtual = 0;
}

void inserirNumero(Principal principal[], int posicao)
{
  int numero;
  printf("Digite o valor a ser inserido: ");
  scanf("%d", &numero);

  principal[posicao].aux->numeros[principal[posicao].aux->qtdAtual] = numero;
  principal[posicao].aux->qtdAtual++;
}

void exibirTodasEstruturas(Principal principal[])
{
  for(int i = 0; i < 10; i++)
  {
    printf("Posição: %d - ", i + 1);

    if(principal[i].aux != NULL)
      exibirAuxiliar(principal[i].aux);
    else
      printf("Sem estrutura auxiliar");

    printf("\n");
  }
}

void exibirAuxiliar(Auxiliar *aux)
{
  printf("Tamanho: %d - números: ", aux->tamanho);
  for(int i = 0; i < aux->tamanho; i++)
  {
    if(i < aux->qtdAtual)
      printf("[%d] ", aux->numeros[i]);
    else
      printf("[ ] ");
  }
}

void exibirTodosAuxiliaresOrdenados(Principal principal[])
{
  for(int i = 0; i < 10; i++)
  {
    printf("Posição: %d - ", i + 1);

    if(principal[i].aux != NULL)
    {
      int *numerosOrdenados[principal[i].aux->qtdAtual];
      
      for(int j = 0; j < principal[i].aux->qtdAtual; j++)
      {
        numerosOrdenados[j] = &principal[i].aux->numeros[j];
      }

      ordenarVetor(numerosOrdenados, principal[i].aux->qtdAtual);

      for(int j = 0; j < principal[i].aux->qtdAtual; j++)
        printf("[%d] ", *numerosOrdenados[j]);

    }
    else
      printf("Sem estrutura auxiliar");

    printf("\n");
  }
}

void exibirTodosOsNumerosOrdenados(Principal principal[])
{
  int qtd = 0;
  for(int i = 0; i < 10; i ++)
    if(principal[i].aux != NULL)
      qtd+= principal[i].aux->qtdAtual;
  
  int **ponteirosOrdenados;

  ponteirosOrdenados = malloc(qtd * sizeof(int *));
  
  int pos = 0;

  for(int i = 0; i < 10; i++)
  {    
    if(principal[i].aux != NULL)
    {
      for(int j = 0; j < principal[i].aux->qtdAtual; j++)
      {
        ponteirosOrdenados[pos] = &principal[i].aux->numeros[j];
        pos++;
      }
    }
  }

  ordenarVetor(ponteirosOrdenados, qtd);

  for(int i = 0; i < qtd; i++)
    printf("[%d] ", *ponteirosOrdenados[i]);

  printf("\n");
  free(ponteirosOrdenados);
}

void ordenarVetor(int *ordenados[], int qtd)
{
  for(int i = 0; i < qtd - 1; i++)  
    for(int j = 0; j < qtd - 1 - i; j++)    
      if(*ordenados[j] > *ordenados[j + 1])
      {
        int *temp = ordenados[j];
        ordenados[j] = ordenados[j + 1];
        ordenados[j + 1] = temp;
      }   
}

void removerNumero(Principal principal[], int posicao)
{
  int numero;
  int encontrado = -1;
  int indice;
  printf("Digite o número que deve ser removido: ");
  scanf("%d", &numero);

  for(int i = 0; i < principal[posicao].aux->qtdAtual; i++)
  {
    if(principal[posicao].aux->numeros[i] == numero)
    {
      encontrado = 1;
      indice = i;
      break;
    }    
  }
  if(encontrado == -1)
  {
    printf("\n'%d' não foi encontrado nessa estrutura\n", numero);
  }
  else
  {
    for(int i = indice; i < principal[posicao].aux->qtdAtual - 1; i++)
    {
      principal[posicao].aux->numeros[i] = principal[posicao].aux->numeros[i + 1];
    }
    principal[posicao].aux->qtdAtual--;
  }
}

void aumentarTamanhoAuxiliar(Principal principal[], int posicao)
{
  int tamAumento;
  printf("Digite quantos espaços serão adicionados a estrutura auxiliar: ");
  scanf("%d", &tamAumento);

  if(tamAumento <= 0)
  {
    printf("\nNúmero inválido\n");
    return;
  }

  int novoTamanho = principal[posicao].aux->tamanho + tamAumento;

  principal[posicao].aux->numeros = realloc(principal[posicao].aux->numeros, novoTamanho * sizeof(int));
  principal[posicao].aux->tamanho = novoTamanho;
}