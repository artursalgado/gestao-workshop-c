#ifndef UTILIZADOR_H
#define UTILIZADOR_H

typedef struct {
  char username[50];
  char password[50];
  int perfil; // 0 = admin, 1 = participante
} Utilizador;

// lista ligada user
typedef struct NoUtilizador {
  Utilizador Utilizador;
  struct NoUtilizador *proximo;
} NoUtilizador;

Utilizador *procurarUtilizador(NoUtilizador *lista, char *username);
int registarUtilizador(NoUtilizador **lista, Utilizador u);

#endif