#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

typedef struct {
  int id;
  char nome[100];
  char instituicao[100];
  int tipo_inscricao;    // 0 = aberta e 1 = x(escolhida)
  int apresentacoes[16]; // id das apresentacoes que escolheu
  int num_apresentacoes; // numero de apresentacoes escolhido
  float total_pagar;
} Participante;

typedef struct NoParticipante {
  Participante participante;
  struct NoParticipante *proximo;
} NoParticipante;

void inserirParticipante(NoParticipante **lista, Participante p);
void listarParticipante(NoParticipante *lista);
void removerParticipante(NoParticipante **lista, int id);

#endif