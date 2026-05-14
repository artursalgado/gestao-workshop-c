#include "../include/participante.h"
#include <stdio.h>
#include <stdlib.h>
// modificar a lista "**"
void inserirParticipante(NoParticipante **lista, Participante p) {

  // guardar espaço para o novo participante
  NoParticipante *novo = (NoParticipante *)malloc(sizeof(NoParticipante));

  // copiar os dados para o no
  novo->participante = p;
  novo->proximo = *lista; // meter o "proximo" a apontar para a cabeça antiga
  *lista = novo;          // a cabeça antiga passa a ser o novo nó
}
// ler a lista 1 "*"
void listarParticipante(NoParticipante *lista) {
  // criar variavel temp e incializar nao com ZERO e sim com o inicil da
  // lista(argumento passado em cima)
  NoParticipante *atual;
  atual = lista;
  while (atual != NULL) {
    printf("Nome: %s", atual->participante.nome);
    atual = atual->proximo; // passar ao proximo nó "atual->proximo"
  }
}

void removerParticipante(NoParticipante **lista, int id) {
  // crtiar variaveis temp
  NoParticipante *atual;
  NoParticipante *anterior;

  // Inicializar
  atual = *lista; // O PROXIMO FAZ A MAGIA
  anterior = NULL;

  // enquanto o atual não for NULL e o id não for igual corre o ciclo
  while (atual != NULL && atual->participante.id != id) {

    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL) {
    printf("Erro - Id não encontrado !");
  } else if (anterior == NULL) { // se o nó for o primeiro
    *lista = atual->proximo;     // atualizar a cabeça para o prox
    free(atual);                 // libertar memoria
  } else {                       // se o nó for a meio ou no fim
    anterior->proximo = atual->proximo;
    free(atual);
  }
}