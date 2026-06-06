#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include "apresentacao.h"

typedef struct {
  int id;
  char nome[100];
  char instituicao[100];
  int tipo_inscricao;      // 0 = aberta, 1 = especifica
  int apresentacoes[16];   // ids das apresentacoes escolhidas
  int num_apresentacoes;   // quantas apresentacoes escolheu
  float total_pagar;       // calculado automaticamente
} Participante;

typedef struct NoParticipante {
  Participante participante;
  struct NoParticipante *proximo;
} NoParticipante;

// operacoes basicas
int  inserirParticipante(NoParticipante **lista, Participante p);
void menuInserirParticipante(NoParticipante **lista, NoApresentacao *listaApresentacoes, float precoAberto);
void menuRemoverParticipante(NoParticipante **lista);
void removerParticipante(NoParticipante **lista, int id);

// listagens
void listarParticipante(NoParticipante *lista);
void listarParticipanteEspecifico(NoParticipante *lista);
void listarParticipantesInscricaoAberta(NoParticipante *lista);
void listarParticipantesApresentacao(NoParticipante *lista);

// extras
void somarTotalInscricoes(NoParticipante *lista);
void consultarInscricao(NoParticipante *lista, char *username);

#endif
