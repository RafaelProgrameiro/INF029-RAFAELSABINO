#include <stdio.h>
#include <stdlib.h>
#include "trabalho2.h"

int exibirMenu()
{
  int op;
  printf("\n========= MENU PRINCIPAL =========\n");
  printf("1 - Criar Estrutura Auxiliar\n");
  printf("2 - Inserir Número em Estrutura\n");
  printf("3 - Excluir Número do Final da Estrutura\n");
  printf("4 - Excluir Número Especifico\n");
  printf("5 - Listar Uma Estrutura Auxiliar\n");
  printf("6 - Listar Uma Estrutura Auxiliar (Ordenada)\n");
  printf("7 - Listar Todas as Estruturas Auxiliares\n");
  printf("8 - Listar Todos os Números Ordenados\n");
  printf("9 - Modificar Tamanho de Estrutura Auxiliar\n");
  printf("0 - Sair e Finalizar Programa\n");
  printf("==================================\n");
  printf("Digite a opção desejada: ");
  scanf("%d", &op);
  return op;
}

void imprimirVetor(int vetorAux[], int qtd) {
  printf("Dados da estrutura: ");
  for (int i = 0; i < qtd; i++) {
    printf("[%d] ", vetorAux[i]);
  }
  printf("\n");
}

int main()
{    
  inicializar(); 
    
  int op;
  int sair = 0;
  int posicao, tamanho, valor, retorno, qtd;

  while (!sair)
  {
    op = exibirMenu();
    switch (op)
    {
      case 0:
      {
        sair = 1;
        finalizar();
        printf("\nPrograma finalizado com sucesso e memória liberada.\n");
        break;
      }
      case 1:
      {
        printf("\n--- Criar Estrutura Auxiliar ---\n");
        printf("Digite a posição da estrutura principal (1 a 10): ");
        scanf("%d", &posicao);
        printf("Digite o tamanho da estrutura auxiliar: ");
        scanf("%d", &tamanho);

        retorno = criarEstruturaAuxiliar(posicao, tamanho);

        if (retorno == SUCESSO) printf("Estrutura criada com sucesso!\n");
        else if (retorno == POSICAO_INVALIDA) printf("Erro: Posição inválida (Deve ser entre 1 e 10).\n");
        else if (retorno == TAMANHO_INVALIDO) printf("Erro: Tamanho inválido (Deve ser maior ou igual a 1).\n");
        else if (retorno == JA_TEM_ESTRUTURA_AUXILIAR) printf("Erro: Já existe uma estrutura auxiliar nesta posição.\n");
        else if (retorno == SEM_ESPACO_DE_MEMORIA) printf("Erro: Memória insuficiente no sistema.\n");
        break;
      }
      case 2:
      {
        printf("\n--- Inserir Número ---\n");
        printf("Digite a posicao (1 a 10): ");
        scanf("%d", &posicao);
        printf("Digite o valor inteiro a ser inserido: ");
        scanf("%d", &valor);

        retorno = inserirNumeroEmEstrutura(posicao, valor);

        if (retorno == SUCESSO) printf("Número %d inserido com sucesso!\n", valor);
        else if (retorno == POSICAO_INVALIDA) printf("Erro: Posição inválida.\n");
        else if (retorno == SEM_ESTRUTURA_AUXILIAR) printf("Erro: Não existe estrutura auxiliar criada nesta posicao.\n");
        else if (retorno == SEM_ESPACO) printf("Erro: A estrutura auxiliar correspondente está cheia.\n");
        break;
      }
      case 3:
      {
        printf("\n--- Excluir do Final da Estrutura ---\n");
        printf("Digite a posição (1 a 10): ");
        scanf("%d", &posicao);

        retorno = excluirNumeroDoFinaldaEstrutura(posicao);

        if (retorno == SUCESSO) printf("último número excluido com sucesso!\n");
        else if (retorno == POSICAO_INVALIDA) printf("Erro: Posicao inválida.\n");
        else if (retorno == SEM_ESTRUTURA_AUXILIAR) printf("Erro: Não existe estrutura auxiliar nesta posição.\n");
        else if (retorno == ESTRUTURA_AUXILIAR_VAZIA) printf("Erro: A estrutura auxiliar já está vazia.\n");
        break;
      }     
      case 4:
      {
        printf("\n--- Excluir Número Específico ---\n");
        printf("Digite a posição (1 a 10): ");
        scanf("%d", &posicao);
        printf("Digite o valor a ser removido: ");
        scanf("%d", &valor);

        retorno = excluirNumeroEspecificoDeEstrutura(posicao, valor);

        if (retorno == SUCESSO) printf("Primeira ocorrencia do valor %d removida com sucesso!\n", valor);
        else if (retorno == POSICAO_INVALIDA) printf("Erro: Posicao inválida.\n");
        else if (retorno == SEM_ESTRUTURA_AUXILIAR) printf("Erro: Não existe estrutura auxiliar nesta posição.\n");
        else if (retorno == ESTRUTURA_AUXILIAR_VAZIA) printf("Erro: A estrutura auxiliar está vazia.\n");
        else if (retorno == NUMERO_INEXISTENTE) printf("Erro: O número %d não foi encontrado nesta estrutura.\n", valor);
        break;
      }
      case 5:
      {
        printf("\n--- Listar Estrutura Auxiliar ---\n");
        printf("Digite a posicão (1 a 10): ");
        scanf("%d", &posicao);

        qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

        if (qtd == POSICAO_INVALIDA) printf("Erro: Posição inválida.\n");
        else if (qtd == SEM_ESTRUTURA_AUXILIAR) printf("Erro: Sem estrutura auxiliar nesta posição.\n");
        else if (qtd == ESTRUTURA_AUXILIAR_VAZIA) printf("Erro: A estrutura auxiliar está vazia.\n");
        else 
        {
          int *vetorAux = (int *)malloc(qtd * sizeof(int));
          retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

          if (retorno == SUCESSO)           
            imprimirVetor(vetorAux, qtd);
          
          free(vetorAux);
        }
        break;
      }
      case 6:
      {
        printf("\n--- Listar Estrutura Auxiliar Ordenada ---\n");
        printf("Digite a posição (1 a 10): ");
        scanf("%d", &posicao);

        qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

        if (qtd == POSICAO_INVALIDA) printf("Erro: Posicao inválida.\n");
        else if (qtd == SEM_ESTRUTURA_AUXILIAR) printf("Erro: Sem estrutura auxiliar nesta posição.\n");
        else if (qtd == ESTRUTURA_AUXILIAR_VAZIA) printf("Erro: A estrutura auxiliar está vazia.\n");
        else 
        {
          int *vetorAux = (int *)malloc(qtd * sizeof(int));
          retorno = getDadosOrdenadosEstruturaAuxiliar(posicao, vetorAux);

          if (retorno == SUCESSO) 
            imprimirVetor(vetorAux, qtd);

          free(vetorAux);
        }
        break;
      }

      case 7:
      {
        printf("\n--- Listar de Todas as Estruturas Auxiliares ---\n");
        
        int totalElementos = 0;
        for (int i = 1; i <= 10; i++)
        {
          int tempQtd = getQuantidadeElementosEstruturaAuxiliar(i);
          if (tempQtd > 0) 
            totalElementos += tempQtd;
        }

        if (totalElementos == 0)        
          printf("Não há elementos em nenhuma das estruturas auxiliares.\n");
        
        else 
        {
          int *vetorGeral = (int *)malloc(totalElementos * sizeof(int));
          retorno = getDadosDeTodasEstruturasAuxiliares(vetorGeral);

          if (retorno == SUCESSO) 
            imprimirVetor(vetorGeral, totalElementos);

          free(vetorGeral);
        }
        break;
      }
      case 8:
      {
        printf("\n--- Listar Todos os Numeros de Forma Ordenada Geral ---\n");
        
        int totalElementos = 0;
        for (int i = 1; i <= 10; i++)
        {
          int tempQtd = getQuantidadeElementosEstruturaAuxiliar(i);
          if (tempQtd > 0) 
            totalElementos += tempQtd;
        }

        if (totalElementos == 0)         
          printf("Não há elementos em nenhuma das estruturas auxiliares.\n");        
        else 
        {
          int *vetorGeralOrdenado = (int *)malloc(totalElementos * sizeof(int));
          retorno = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorGeralOrdenado);

          if (retorno == SUCESSO) 
            imprimirVetor(vetorGeralOrdenado, totalElementos);
            
          free(vetorGeralOrdenado);
        }
        break;
      }
      case 9:
      {
        printf("\n--- Modificar Tamanho de Estrutura Auxiliar ---\n");
        printf("Digite a posição (1 a 10): ");
        scanf("%d", &posicao);
        printf("Digite o valor de ajuste (Ex: '3' para somar 3 espaços ou '-2' para reduzir 2 espaços): ");
        scanf("%d", &tamanho);

        retorno = modificarTamanhoEstruturaAuxiliar(posicao, tamanho);

        if (retorno == SUCESSO) printf("Tamanho da estrutura modificado com sucesso!\n");
        else if (retorno == POSICAO_INVALIDA) printf("Erro: Posição inválida.\n");
        else if (retorno == SEM_ESTRUTURA_AUXILIAR) printf("Erro: Sem estrutura auxiliar nesta posicao para redimensionar.\n");
        else if (retorno == NOVO_TAMANHO_INVALIDO) printf("Erro: O tamanho final resultante não pode ser menor que 1.\n");
        else if (retorno == SEM_ESPACO_DE_MEMORIA) printf("Erro: Não foi possível realocar memória no sistema.\n");
        break;
      }
      default:
      {
        printf("\nOpção inválida! Tente novamente.\n");
        break;
      }
    }
  }
  return 0;
}