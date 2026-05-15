#ifndef FICHEIROS_H
#define FICHEIROS_H

#include "participante.h"
#include "apresentacao.h"
#include "utilizador.h"

// nomes dos ficheiros onde guardamos os dados
#define FICHEIRO_PARTICIPANTES "data/participantes.bin"
#define FICHEIRO_APRESENTACOES "data/apresentacoes.bin"
#define FICHEIRO_UTILIZADORES  "data/utilizadores.bin"

// guardar dados em ficheiro binario
void guardarParticipantes(NoParticipante *lista);
void guardarApresentacoes(NoApresentacao *lista);
void guardarUtilizadores(NoUtilizador *lista);

// carregar dados do ficheiro binario para a lista
void carregarParticipantes(NoParticipante **lista);
void carregarApresentacoes(NoApresentacao **lista);
void carregarUtilizadores(NoUtilizador **lista);

#endif
