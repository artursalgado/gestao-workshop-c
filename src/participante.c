#include "../include/participante.h"
#include <stdio.h>
#include <stdlib.h>

void menuInserirParticipante(NoParticipante **lista) {

  // variavel participante
  Participante p;
  static int contador = 1;

  printf("Insira o nome do Participante: \n");
  scanf(" %[^\n]", p.nome);

  printf("Insira o nome da Instituiçao: \n");
  scanf("%s", p.instituicao);

  // atribuir id automatico antes de inserir
  p.id = contador++;

  // enviamos os dados que queremos e a funcao trabalha
  if (inserirParticipante(lista, p) == 0)
    printf("Participante Inserido com Sucesso!\n");
  else
    printf("Erro ao inserir participante!\n");

  return;
}

void menuRemoverParticipante(NoParticipante **lista) {

  Participante p; // alternativa int id = 0; funcina igual

  printf("Escreva o ID do Participante que deseja eliminar: \n");
  scanf("%d", &p.id);

  // enviamos os dados que queremos e a funcao trabalha
  removerParticipante(lista, p.id);

  printf("Participante Removido com Sucesso !");

  return;
}
// modificar a lista "**"
int inserirParticipante(NoParticipante **lista, Participante p) {

  // guardar espaço para o novo participante
  NoParticipante *novo = (NoParticipante *)malloc(sizeof(NoParticipante));

  // verificar se o malloc teve sucesso
  if (novo == NULL)
    return -1;

  // copiar os dados para o no
  novo->participante = p;
  novo->proximo = *lista; // meter o "proximo" a apontar para a cabeça antiga
  *lista = novo;          // a cabeça antiga passa a ser o novo nó

  return 0;
}
// ler a lista 1 "*"
void listarParticipante(NoParticipante *lista) {
  // criar variavel temp e incializar nao com ZERO e sim com o inicil da
  // lista(argumento passado em cima)
  NoParticipante *atual;
  atual = lista;
  while (atual != NULL) {
    printf("Nome: %s\n", atual->participante.nome);
    printf("ID: %d\n", atual->participante.id);
    printf("Instituiçao: %s\n", atual->participante.instituicao);
    printf("**************************");

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