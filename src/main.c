#include "../include/apresentacao.h"
#include "../include/participante.h"
#include "../include/utilizador.h"
#include "../include/workshop.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // INICIAR
  // lista de utilizadores começa vazia
  NoUtilizador *listaUtilizadores = NULL;

  // admin por defeito — sempre no arranque
  Utilizador admin = {"admin", "admin", 0};
  registarUtilizador(&listaUtilizadores, admin);

  // LOGIN
  char nomeUtilizador[50], password[50];

  system("clear");
  printf("*******************************\n");
  printf("  Sistema de Gestao Workshop   \n");
  printf("*******************************\n");
  printf("Nome de Utilizador: ");
  scanf("%s", nomeUtilizador);
  printf("Palavra-passe: ");
  scanf("%s", password);

  // procurar o utilizador na lista
  Utilizador *u = procurarUtilizador(listaUtilizadores, nomeUtilizador);

  // se nao existir, perguntar se quer registar
  if (u == NULL) {
    char resposta;
    printf("Utilizador nao encontrado. Deseja fazer o Registo? (s/n): ");
    scanf(" %c", &resposta);

    if (resposta == 's' || resposta == 'S') {
      Utilizador novo;
      strcpy(novo.username, nomeUtilizador);
      strcpy(novo.password, password);
      novo.perfil = 1; // novo utilizador e sempre participante

      if (registarUtilizador(&listaUtilizadores, novo) == 0) {
        printf("Registo bem sucedido!\n");
        u = procurarUtilizador(listaUtilizadores, nomeUtilizador);
      } else {
        printf("Erro ao registar utilizador.\n");
        return -1;
      }
    } else {
      printf("A sair...\n");
      return 0;
    }
  }

  // verificar passwod
  if (strcmp(u->password, password) != 0) {
    printf("Password incorreta!\n");
    return -1;
  }

  system("clear");
  printf("Login bem sucedido! Bem-vindo, %s.\n", u->username);

  // MENU ADMIN
  if (u->perfil == 0) {

    NoParticipante *listaParticipantes = NULL;
    int opcao = 0;

    do {
      system("clear");
      printf("\n**********************\n");
      printf("1 - Inserir Participante\n");
      printf("2 - Listar Participantes\n");
      printf("3 - Remover Participante\n");
      printf("0 - SAIR\n");
      printf("**********************\n");
      printf("Opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
        menuInserirParticipante(&listaParticipantes);
        printf("\nCarregue Enter para continuar...");
        getchar(); getchar();
        break;
      case 2:
        listarParticipante(listaParticipantes);
        printf("\nCarregue Enter para continuar...");
        getchar(); getchar();
        break;
      case 3:
        menuRemoverParticipante(&listaParticipantes);
        printf("\nCarregue Enter para continuar...");
        getchar(); getchar();
        break;
      case 0:
        printf("A sair...\n");
        break;
      default:
        printf("Opcao invalida!\n");
        printf("\nCarregue Enter para continuar...");
        getchar(); getchar();
        break;
      }
    } while (opcao != 0);

    // MENU PARTICIPANTE
  } else {
    printf("Menu de participante (em construcao)\n");
    return 0;
  }

  return 0;
}
