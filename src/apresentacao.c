#include "../include/apresentacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuInserirApresentacao(NoApresentacao **lista) {

  Apresentacao apresentacao;

  printf("**************\n");
  printf("Escreva o Titulo da Apresentaçao: \n");
  scanf("%s", apresentacao.titulo);
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

  inserirApresentacao(lista, apresentacao);
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