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
  char data[30];     // data/hora do horario
  int num_inscritos; // quantos participantes estao inscritos
} Apresentacao;

// struct apresentacao
typedef struct NoApresentacao {
  Apresentacao Apresentacao;
  struct NoApresentacao *proximo;
} NoApresentacao;

// operacoes basicas
int inserirApresentacao(NoApresentacao **lista, Apresentacao a);
void menuInserirApresentacao(NoApresentacao **lista);
void menuRemoverApresentacao(NoApresentacao **lista);
void removerApresentacao(NoApresentacao **lista, int id);
void menuAlterarApresentacao(NoApresentacao *lista);
void menuHorarioApresentacao(NoApresentacao *lista);

// listagens
void listarApresentacoes(NoApresentacao *lista);
void listarApresentacoesPorData(NoApresentacao *lista);
void consultarApresentacaoEspecifica(NoApresentacao *lista);

// extras
void ordenarApresentacoesTitulo(NoApresentacao *lista);
void apresentacaoMaisInscricoes(NoApresentacao *lista);
void imprimirProgramaWorkshop(NoApresentacao *lista);

#endif
