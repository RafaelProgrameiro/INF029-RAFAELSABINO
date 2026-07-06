#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

// int vetorPrincipal[TAM];

typedef struct Auxiliar
{
  int *numeros;
  int tamanho;
  int qtdAtual;
} Auxiliar;

typedef struct Principal
{
  Auxiliar *aux;
} Principal;

Principal vetorPrincipal[TAM];

// typedef struct No{
//   int valor;
//   struct No *proximo;
// } No;

void ordenarValores(int vetor[], int qtd)
{
  for (int i = 0; i < qtd - 1; i++)
    for (int j = 0; j < qtd - 1 - i; j++)
      if (vetor[j] > vetor[j + 1])
      {
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
}

// int posicaoValida(int posicao)
// {
//   if (posicao < 1 || posicao > 10) 
//     return POSICAO_INVALIDA;

//   return SUCESSO;
// }

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
  if (posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  if (tamanho < 1)
    return TAMANHO_INVALIDO;

  int indice = posicao - 1;

  if (vetorPrincipal[indice].aux != NULL) 
    return JA_TEM_ESTRUTURA_AUXILIAR;
    
  vetorPrincipal[indice].aux = (Auxiliar *)malloc(sizeof(Auxiliar));

  if (vetorPrincipal[indice].aux == NULL) 
    return SEM_ESPACO_DE_MEMORIA;
  
  vetorPrincipal[indice].aux->numeros = (int *)malloc(tamanho * sizeof(int));

  if (vetorPrincipal[indice].aux->numeros == NULL) 
  {
    free(vetorPrincipal[indice].aux);
    vetorPrincipal[indice].aux = NULL;
    return SEM_ESPACO_DE_MEMORIA;
  }

  vetorPrincipal[indice].aux->tamanho = tamanho;
  vetorPrincipal[indice].aux->qtdAtual = 0;

  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
  if (posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  int indice = posicao - 1;

  if (vetorPrincipal[indice].aux == NULL) 
    return SEM_ESTRUTURA_AUXILIAR;

  if (vetorPrincipal[indice].aux->qtdAtual == vetorPrincipal[indice].aux->tamanho) 
    return SEM_ESPACO;
    
  vetorPrincipal[indice].aux->numeros[vetorPrincipal[indice].aux->qtdAtual] = valor;
  vetorPrincipal[indice].aux->qtdAtual++;

  return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  if (posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  int indice = posicao - 1;

  if (vetorPrincipal[indice].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;
  

  if (vetorPrincipal[indice].aux->qtdAtual == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;  

  vetorPrincipal[indice].aux->qtdAtual--;

  return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  if (posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA; 

  int indice = posicao - 1;

  if (vetorPrincipal[indice].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;
  

  if (vetorPrincipal[indice].aux->qtdAtual == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;  

  int encontrado = -1;

  for (int i = 0; i < vetorPrincipal[indice].aux->qtdAtual; i++) 
    if (vetorPrincipal[indice].aux->numeros[i] == valor)
    {
      encontrado = i;
      break;
    }  

  if (encontrado == -1)
    return NUMERO_INEXISTENTE;

  for (int i = encontrado; i < vetorPrincipal[indice].aux->qtdAtual - 1; i++)
    vetorPrincipal[indice].aux->numeros[i] = vetorPrincipal[indice].aux->numeros[i + 1];
    
  vetorPrincipal[indice].aux->qtdAtual--;

  return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
  int retorno = 0;
  if (posicao < 1 || posicao > 10)
  {
    retorno = POSICAO_INVALIDA;
  }
  else
    retorno = SUCESSO;

  return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  if (posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA; 

  int indice = posicao - 1;

  if (vetorPrincipal[indice].aux == NULL) 
    return SEM_ESTRUTURA_AUXILIAR;
    

  for (int i = 0; i < vetorPrincipal[indice].aux->qtdAtual; i++)
    vetorAux[i] = vetorPrincipal[indice].aux->numeros[i];

  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
    
  if (retorno == SUCESSO)
  {
    int indice = posicao - 1;
    ordenarValores(vetorAux, vetorPrincipal[indice].aux->qtdAtual);
  }

  return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int totalElementos = 0;
  int posVetorAux = 0;

  for (int i = 0; i < TAM; i++) 
    if (vetorPrincipal[i].aux != NULL)
    {
      totalElementos += vetorPrincipal[i].aux->qtdAtual;
      for (int j = 0; j < vetorPrincipal[i].aux->qtdAtual; j++)
      {
        vetorAux[posVetorAux] = vetorPrincipal[i].aux->numeros[j];
        posVetorAux++;
      }
    }
  

  if (totalElementos == 0) 
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int totalElementos = 0;
  for (int i = 0; i < TAM; i++) 
    if (vetorPrincipal[i].aux != NULL) 
      totalElementos += vetorPrincipal[i].aux->qtdAtual;
        
  int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);

  if (retorno == SUCESSO)
    ordenarValores(vetorAux, totalElementos);
  
  return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
  if (posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  int indice = posicao - 1;

  if (vetorPrincipal[indice].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;  

  int tamanhoResultante = vetorPrincipal[indice].aux->tamanho + novoTamanho;

  if (tamanhoResultante < 1)
    return NOVO_TAMANHO_INVALIDO;  

  int *temp = (int *)realloc(vetorPrincipal[indice].aux->numeros, tamanhoResultante * sizeof(int));
  if (temp == NULL)
    return SEM_ESPACO_DE_MEMORIA;
  
  vetorPrincipal[indice].aux->numeros = temp;
  vetorPrincipal[indice].aux->tamanho = tamanhoResultante;

  if (vetorPrincipal[indice].aux->qtdAtual > tamanhoResultante)
    vetorPrincipal[indice].aux->qtdAtual = tamanhoResultante;

  return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
  if (posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  int indice = posicao - 1;

  if (vetorPrincipal[indice].aux == NULL)
    return SEM_ESTRUTURA_AUXILIAR;
  

  if (vetorPrincipal[indice].aux->qtdAtual == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

  return vetorPrincipal[indice].aux->qtdAtual;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
  int qtdElementos = 0;
  for(int i = 0; i < TAM; i++)  
    if(vetorPrincipal[i].aux != NULL)
      qtdElementos += vetorPrincipal[i].aux->qtdAtual;    

  if(qtdElementos == 0)
    return NULL;
  
  No *inicio = malloc(sizeof(No));
  if(inicio == NULL)
    return NULL;

  inicio->prox = NULL;

  No *atual = inicio;

  for(int i = 0; i < TAM; i++)
  {
    if(vetorPrincipal[i].aux != NULL)
      for(int j = 0; j < vetorPrincipal[i].aux->qtdAtual; j++)
      {
        No * novoNo = malloc(sizeof(No));
        if(novoNo == NULL)
          return NULL;

        novoNo->conteudo = vetorPrincipal[i].aux->numeros[j];
        novoNo->prox = NULL;

        atual->prox = novoNo;
        atual = novoNo;
      }
  }
  return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
  if(inicio == NULL || inicio->prox == NULL)
    return;

  No *atual = inicio->prox;

  int i = 0;

  while(atual != NULL)
  {
    vetorAux[i] = atual->conteudo;
    i++;
    atual = atual->prox;
  }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
  if(inicio == NULL || *inicio == NULL)
    return;

  No *atual = *inicio;
  No *proximoNo;

  while(atual != NULL)
  {
    proximoNo = atual->prox;

    free(atual);

    atual = proximoNo;
  }
  *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
  for (int i = 0; i < TAM; i++) 
    vetorPrincipal[i].aux = NULL;  
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
  for (int i = 0; i < TAM; i++) 
    if (vetorPrincipal[i].aux != NULL)
    {
      if (vetorPrincipal[i].aux->numeros != NULL)
        free(vetorPrincipal[i].aux->numeros);
      
      free(vetorPrincipal[i].aux);
      vetorPrincipal[i].aux = NULL;
    }
}