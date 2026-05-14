#ifndef UTILIZADOR_H
#define UTILIZADOR_H

typedef struct {
  char username[50];
  char password[50];
  int perfil; // 0 = admin, 1 = participante
} Utilizador;

// lista ligada user
typedef struct NoUtilizador {
  Utilizador dados;
  struct NoUtilizador *proximo;
} NoUtilizador;

#endif