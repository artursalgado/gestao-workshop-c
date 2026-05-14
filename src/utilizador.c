#include "../include/utilizador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Utilizador *procurarUtilizador(NoUtilizador *lista, char *username) {

  // crtiar variaveis temp
  NoUtilizador *atual;

  // Inicializar
  atual = lista;

  // enquanto o atual não for NULL e o id não for igual corre o ciclo
  while (atual != NULL && strcmp(atual->Utilizador.username, username) != 0) {

    atual = atual->proximo;
  }
  // se for diferente de NULL retorna o endereco do user
  if (atual != NULL) {
    return &atual->Utilizador;
  } else {
    return NULL;
  }
}

int registarUtilizador(NoUtilizador **lista, Utilizador u) {

  NoUtilizador *novo = (NoUtilizador *)malloc(sizeof(NoUtilizador));

  if (novo == NULL) {
    return -1;
  }

  novo->Utilizador = u;
  novo->proximo = *lista;
  *lista = novo;

  return 0;
}