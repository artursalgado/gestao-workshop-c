#include "../include/apresentacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuInserirApresentacao(NoApresentacao **lista) {

  Apresentacao apresentacao;

  // id automatico — incrementa a cada apresentacao adicionada
  static int contador = 1;
  apresentacao.id = contador++;

  // a data fica vazia ate ser com horario definido
  strcpy(apresentacao.data, "sem horario definido");
  apresentacao.num_inscritos = 0;

  printf("**************\n");
  printf("Escreva o Titulo da Apresentaçao: \n");
  scanf(" %[^\n]", apresentacao.titulo);
  printf("Escreva o nome do Orador: \n");
  scanf(" %[^\n]", apresentacao.orador);
  printf("Escreva o currículo do Orador: \n");
  scanf(" %[^\n]", apresentacao.curriculo);
  printf("Insira a duracao(em minutos): \n");
  scanf("%d", &apresentacao.duracao);
  printf("Insira o preço: \n");
  scanf("%f", &apresentacao.preco);

  printf("**************\n");
  printf("Palavras Chave\n");

  for (int i = 0; i < 5; i++) {
    printf("Escreva a %d palavra-chave: \n", i + 1);
    scanf("%s", apresentacao.palavras_chave[i]);
  }

  if (inserirApresentacao(lista, apresentacao) == 0)
    printf("Apresentacao inserida com sucesso! ID: %d\n", apresentacao.id);
  else
    printf("Erro ao inserir apresentacao!\n");
}

void menuHorarioApresentacao(NoApresentacao *lista) {
  int id;

  printf("Escreva o ID da Apresentacao a definir horario: \n");
  scanf("%d", &id);

  // percorrer a lista para encontrar a apresentacao com esse id
  NoApresentacao *atual = lista;
  while (atual != NULL && atual->Apresentacao.id != id) {
    atual = atual->proximo; // passar ao proximo no
  }

  // se nao encontrou
  if (atual == NULL) {
    printf("Erro - ID nao encontrado!\n");
    return;
  }

  // pedir a data/hora ao utilizador e guardar
  printf("Escreva a data e hora (2025-06-10 14:00): \n");
  scanf(" %[^\n]", atual->Apresentacao.data);

  printf("horario definido com sucesso!\n");
}

void listarApresentacoes(NoApresentacao *lista) {
  NoApresentacao *atual = lista;

  if (atual == NULL) {
    printf("Nao existem apresentacoes registadas.\n");
    return;
  }

  while (atual != NULL) {
    printf("**************\n");
    printf("ID: %d\n", atual->Apresentacao.id);
    printf("Titulo: %s\n", atual->Apresentacao.titulo);
    printf("Orador: %s\n", atual->Apresentacao.orador);
    printf("Curriculo: %s\n", atual->Apresentacao.curriculo);
    printf("Duracao: %d minutos\n", atual->Apresentacao.duracao);
    printf("Preco: %.2f EUR\n", atual->Apresentacao.preco);
    printf("Data: %s\n", atual->Apresentacao.data);
    printf("Palavras-chave: ");
    for (int i = 0; i < 5; i++) {
      printf("%s ", atual->Apresentacao.palavras_chave[i]);
    }
    printf("\n");
    atual = atual->proximo;
  }
}

void menuRemoverApresentacao(NoApresentacao **lista) {
  int id;

  printf("Escreva o ID da Apresentacao que deseja eliminar: \n");
  scanf("%d", &id);

  // enviamos o id e a funcao trabalha
  removerApresentacao(lista, id);
}

void removerApresentacao(NoApresentacao **lista, int id) {
  // variaveis temp para percorrer a lista
  NoApresentacao *atual = *lista;
  NoApresentacao *anterior = NULL;

  // percorre a lista enquanto nao encontrar o id ou chegar ao fim
  while (atual != NULL && atual->Apresentacao.id != id) {
    anterior = atual;
    atual = atual->proximo; // passar ao proximo no
  }

  // se chegou ao fim sem encontrar
  if (atual == NULL) {
    printf("Erro - ID nao encontrado!\n");
    return;
  }

  // se o no a apagar e o primeiro da lista
  if (anterior == NULL) {
    *lista = atual->proximo; // a cabeca passa a ser o proximo
  } else {
    // se esta a meio ou no fim — o anterior salta por cima do atual
    anterior->proximo = atual->proximo;
  }

  // libertar a memoria do no removido
  free(atual);
  printf("Apresentacao removida com sucesso!\n");
}

int inserirApresentacao(NoApresentacao **lista, Apresentacao a) {
  // gaurdar espaco nova apresentacao
  NoApresentacao *novo = (NoApresentacao *)malloc(sizeof(NoApresentacao));

  // verifica o sucesso do malloc
  if (novo == NULL) {
    return -1;
  }

  novo->Apresentacao = a;
  novo->proximo = *lista; // meter o "proximo" a apontar para a cabeça antiga
  *lista = novo;          // a cabeça antiga passa a ser o novo nó

  return 0;
}