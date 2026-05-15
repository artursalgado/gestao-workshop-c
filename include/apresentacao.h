#ifndef APRESENTACAO_H
#define APRESENTACAO_H

typedef struct {
  int id;
  char titulo[100];
  char orador[100];
  char curriculo[500];
  char palavras_chave[5][50];
  int duracao; // em minutos
  float preco;
  char data[30]; // data/hora do horario
  int num_inscritos;
} Apresentacao;

typedef struct NoApresentacao {
  Apresentacao Apresentacao;
  struct NoApresentacao *proximo;
} NoApresentacao;

int inserirApresentacao(NoApresentacao **lista, Apresentacao a);
void menuInserirApresentacao(NoApresentacao **lista);
void listarApresentacoes(NoApresentacao *lista);
void menuRemoverApresentacao(NoApresentacao **lista);
void removerApresentacao(NoApresentacao **lista, int id);
void menuHorarioApresentacao(NoApresentacao *lista);

#endif