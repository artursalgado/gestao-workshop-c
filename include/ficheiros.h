#ifndef FICHEIROS_H
#define FICHEIROS_H

#include "participante.h"
#include "apresentacao.h"
#include "utilizador.h"
#include "workshop.h"

// guardar dados em ficheiro binario
void guardarParticipantes(NoParticipante *lista);
void guardarApresentacoes(NoApresentacao *lista);
void guardarUtilizadores(NoUtilizador *lista);
void guardarWorkshop(Workshop *w);

// carregar dados do ficheiro para a lista
void carregarParticipantes(NoParticipante **lista);
void carregarApresentacoes(NoApresentacao **lista);
void carregarUtilizadores(NoUtilizador **lista);
void carregarWorkshop(Workshop *w);

#endif
