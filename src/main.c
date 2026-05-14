#include "../include/apresentacao.h"
#include "../include/participante.h"
#include "../include/utilizador.h"
#include "../include/workshop.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // variaveis para guardar o login inserido pelo utilizador
  char nomeUtilizador[15], password[10];

  printf("*******\n");
  printf("Nome de Utilizador: \n");
  scanf("%s", nomeUtilizador);

  printf("Palavra-passe: \n");
  scanf("%s", password);

  // utilizador admin fixo (perfil 0 = admin)
  Utilizador admin = {"admin", "admin", 0};

  // comparar dados inseridos com o admin
  if (strcmp(nomeUtilizador, admin.username) == 0 &&
      strcmp(password, admin.password) == 0) {

    printf("Login Bem Sucedido!\n");

    // lista de participantes inicializada a NULL (vazia)
    NoParticipante *lista = NULL;
    int opcao = 0;

    do {
      printf("**********************\n");
      printf("1 - Inserir Participante\n");
      printf("2 - Listar Participantes\n");
      printf("3 - Remover Participante\n");
      printf("0 - SAIR\n");
      printf("**********************\n");
      printf("Escreva a opcao: \n");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
        menuInserirParticipante(&lista);
        break;
      case 2:
        listarParticipante(lista);
        break;
      case 3:
        menuRemoverParticipante(&lista);
        break;
      case 0:
        printf("A sair...\n");
        break;
      default:
        printf("Opcao invalida!\n");
        break;
      }
    } while (opcao != 0);

  } else {
    printf("Erro - Nome ou Password ERRADOS!\n");
    return -1;
  }

  return 0;
}
