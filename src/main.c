#include "../include/apresentacao.h"
#include "../include/ficheiros.h"
#include "../include/participante.h"
#include "../include/utilizador.h"
#include "../include/workshop.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // INICIAR — listas todas a NULL (vazias)
  NoUtilizador *listaUtilizadores = NULL;
  NoParticipante *listaParticipantes = NULL;
  NoApresentacao *listaApresentacoes = NULL;
  Workshop workshop = {"", "", 0.0}; // dados do workshop (datas e preco aberto)

  // carregar dados guardados anteriormente
  carregarUtilizadores(&listaUtilizadores);
  carregarParticipantes(&listaParticipantes);
  carregarApresentacoes(&listaApresentacoes);
  carregarWorkshop(&workshop);

  // admin por defeito — so regista se ainda nao existir
  if (procurarUtilizador(listaUtilizadores, "admin") == NULL) {
    Utilizador admin = {"admin", "admin", 0};
    registarUtilizador(&listaUtilizadores, admin);
  }

  // LOGIN
  char nomeUtilizador[50], password[50];

  system("clear");
  printf("***********************************************\n");
  printf("  Sistema de Gestao Workshop - ESTG IPVC      \n");
  printf("***********************************************\n");
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

  // verificar password
  if (strcmp(u->password, password) != 0) {
    printf("Password incorreta!\n");
    return -1;
  }

  system("clear");
  printf("Bem-vindo, %s!\n", u->username);

  // MENU ADMIN
  if (u->perfil == 0) {

    int opcao = 0;

    do {
      system("clear");
      printf("\n======================\n");
      printf("--- PARTICIPANTES ---\n");
      printf("1  - Inserir Participante\n");
      printf("2  - Listar Participantes\n");
      printf("3  - Remover Participante\n");
      printf("4  - Ver Participante Especifico\n");
      printf("5  - Participantes Inscricao Aberta\n");
      printf("6  - Participantes de uma Apresentacao\n");
      printf("7  - Total das Inscricoes\n");
      printf("--- APRESENTACOES ---\n");
      printf("8  - Inserir Apresentacao\n");
      printf("9  - Listar Apresentacoes\n");
      printf("10 - Remover Apresentacao\n");
      printf("11 - Alterar Apresentacao\n");
      printf("12 - Definir Horario\n");
      printf("13 - Ordenar por Titulo\n");
      printf("14 - Listar por Data\n");
      printf("15 - Apresentacao com mais Inscricoes\n");
      printf("16 - Imprimir Programa para Ficheiro\n");
      printf("--- WORKSHOP ---\n");
      printf("17 - Configurar Workshop\n");
      printf("======================\n");
      printf("0  - SAIR\n");
      printf("======================\n");
      printf("Opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
        menuInserirParticipante(&listaParticipantes, listaApresentacoes, workshop.preco_inscricao_aberta);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 2:
        listarParticipante(listaParticipantes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 3:
        menuRemoverParticipante(&listaParticipantes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 4:
        listarParticipanteEspecifico(listaParticipantes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 5:
        listarParticipantesInscricaoAberta(listaParticipantes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 6:
        listarParticipantesApresentacao(listaParticipantes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 7:
        somarTotalInscricoes(listaParticipantes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 8:
        while (getchar() != '\n'); // limpar o buffer antes do menu
        menuInserirApresentacao(&listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 9:
        listarApresentacoes(listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 10:
        menuRemoverApresentacao(&listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 11:
        menuAlterarApresentacao(listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 12:
        menuHorarioApresentacao(listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 13:
        ordenarApresentacoesTitulo(listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 14:
        listarApresentacoesPorData(listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 15:
        apresentacaoMaisInscricoes(listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 16:
        imprimirProgramaWorkshop(listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 17:
        configurarWorkshop(&workshop);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 0:
        // guardar tudo antes de sair
        guardarParticipantes(listaParticipantes);
        guardarApresentacoes(listaApresentacoes);
        guardarUtilizadores(listaUtilizadores);
        guardarWorkshop(&workshop);
        printf("Dados guardados. A sair...\n");
        break;
      default:
        printf("Opcao invalida!\n");
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      }
    } while (opcao != 0);

  // MENU PARTICIPANTE
  } else {

    int opcao = 0;

    do {
      system("clear");
      printf("\n======================\n");
      printf("Bem-vindo, %s!\n", u->username);
      printf("--- AGENDA ---\n");
      printf("1 - Consultar a minha inscricao\n");
      printf("2 - Agenda do workshop (por data)\n");
      printf("3 - Ver todas as apresentacoes\n");
      printf("4 - Consultar uma apresentacao\n");
      printf("0 - SAIR\n");
      printf("======================\n");
      printf("Opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
        // procura a inscricao pelo username do participante
        consultarInscricao(listaParticipantes, u->username);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 2:
        listarApresentacoesPorData(listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 3:
        listarApresentacoes(listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 4:
        consultarApresentacaoEspecifica(listaApresentacoes);
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      case 0:
        printf("A sair...\n");
        break;
      default:
        printf("Opcao invalida!\n");
        printf("\nEnter para continuar..."); getchar(); getchar();
        break;
      }
    } while (opcao != 0);
  }

  return 0;
}
