#include "../include/ficheiros.h"
#include <stdio.h>
#include <stdlib.h>

// PARTICIPANTES

void guardarParticipantes(NoParticipante *lista) {
  // abrir file
  FILE *fp = fopen("PARTICIPANTES", "wb");
  if (fp == NULL) {
    printf("Erro ao abrir ficheiro!\n");
    return;
  }

  // percorre a lista e escreve 1 a 1 no file
  NoParticipante *atual = lista;
  while (atual != NULL) {
    fwrite(&atual->participante, sizeof(Participante), 1, fp);
    atual = atual->proximo; // passar ao proximo no da lista
  }

  fclose(fp);
}

void carregarParticipantes(NoParticipante **lista) {
  // abrir file
  FILE *fp = fopen("PARTICIPANTES", "rb");
  if (fp == NULL)
    return;

  Participante p;
  // fread le um de cada vez
  // 1 = True / 0 = END
  while (fread(&p, sizeof(Participante), 1, fp) == 1) {
    // arranjar espaco
    NoParticipante *novo = (NoParticipante *)malloc(sizeof(NoParticipante));
    if (novo == NULL) {
      break;
    }
    novo->participante = p; // copiar os dados lidos para o novo no
    novo->proximo = *lista; // o novo no aponta para a cabeca antiga
    *lista = novo;          // a cabeca passa a ser o novo no
  }

  fclose(fp);
}

// APRESENTACOES

void guardarApresentacoes(NoApresentacao *lista) {
  // abrir file
  FILE *fp = fopen("APRESENTACOES", "wb");
  if (fp == NULL) {
    printf("Erro ao abrir ficheiro!\n");
    return;
  }

  // mesma logica qdos participantes — percorre e escreve no a no
  NoApresentacao *atual = lista;
  while (atual != NULL) {
    fwrite(&atual->Apresentacao, sizeof(Apresentacao), 1, fp);
    atual = atual->proximo; // passar ao proximo no da lista
  }

  fclose(fp);
}

void carregarApresentacoes(NoApresentacao **lista) {
  // abrir file
  FILE *fp = fopen("APRESENTACOES", "rb");
  if (fp == NULL) {
    return;
  }
  Apresentacao a;
  // le uma apresentacao de cada vez
  while (fread(&a, sizeof(Apresentacao), 1, fp) == 1) {
    NoApresentacao *novo = (NoApresentacao *)malloc(sizeof(NoApresentacao));
    if (novo == NULL) {
      break;
    }
    novo->Apresentacao = a; // copiar os dados lidos para o novo no
    novo->proximo = *lista; // o novo no aponta para a cabeca antiga
    *lista = novo;          // a cabeca passa a ser o novo no
  }

  fclose(fp);
}

// UTILIZADORES

void guardarUtilizadores(NoUtilizador *lista) {
  // Abrir file
  FILE *fp = fopen("UTILIZADORES", "wb");
  if (fp == NULL) {
    printf("Erro ao abrir ficheiro!\n");
    return;
  }

  // percorre a lista no a no e escreve cada utilizador no ficheiro
  NoUtilizador *atual = lista;
  while (atual != NULL) {
    fwrite(&atual->Utilizador, sizeof(Utilizador), 1, fp);
    atual = atual->proximo; // passar ao proximo no da lista
  }

  fclose(fp);
}

void carregarUtilizadores(NoUtilizador **lista) {
  // abrir file
  FILE *fp = fopen("UTILIZADORES", "rb");
  if (fp == NULL)
    return;

  Utilizador u;
  // le um utilizador de cada vez
  while (fread(&u, sizeof(Utilizador), 1, fp) == 1) {
    NoUtilizador *novo = (NoUtilizador *)malloc(sizeof(NoUtilizador));
    if (novo == NULL)
      break;
    novo->Utilizador = u;   // copiar os dados lidos para o novo no
    novo->proximo = *lista; // o novo no aponta para a cabeca antiga
    *lista = novo;          // a cabeca passa a ser o novo no
  }

  fclose(fp);
}
