#include "../include/participante.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inserir participante na lista com logica de inscricao completa
void menuInserirParticipante(NoParticipante **lista, NoApresentacao *listaApresentacoes, float precoAberto) {

  Participante p;
  static int contador = 1; // id automatico — nao reinicia entre chamadas

  printf("Nome do Participante: \n");
  scanf(" %[^\n]", p.nome);

  printf("Instituicao: \n");
  scanf(" %[^\n]", p.instituicao);

  // tipo de inscricao
  printf("Tipo de inscricao:\n");
  printf("0 - Aberta (acesso total ao workshop)\n");
  printf("1 - Especifica (escolhe as apresentacoes)\n");
  scanf("%d", &p.tipo_inscricao);

  if (p.tipo_inscricao == 0) {
    // inscricao aberta — paga o preco fixo do workshop
    p.total_pagar = precoAberto;
    p.num_apresentacoes = 0;
    printf("Inscricao aberta! Total a pagar: %.2f EUR\n", p.total_pagar);

  } else {
    // inscricao especifica — escolhe apresentacoes e soma os precos
    p.num_apresentacoes = 0;
    p.total_pagar = 0;

    // mostrar apresentacoes disponiveis para o participante escolher
    printf("--- Apresentacoes disponiveis ---\n");
    NoApresentacao *a = listaApresentacoes;
    while (a != NULL) {
      printf("ID: %d | %s | %.2f EUR\n",
             a->Apresentacao.id,
             a->Apresentacao.titulo,
             a->Apresentacao.preco);
      a = a->proximo;
    }

    printf("Escreva os IDs das apresentacoes (0 para terminar):\n");
    int id;
    while (p.num_apresentacoes < 16) {
      scanf("%d", &id);
      if (id == 0) break;

      // encontrar a apresentacao e somar o preco
      NoApresentacao *atual = listaApresentacoes;
      while (atual != NULL && atual->Apresentacao.id != id) {
        atual = atual->proximo;
      }

      if (atual != NULL) {
        p.apresentacoes[p.num_apresentacoes++] = id;
        p.total_pagar += atual->Apresentacao.preco;
        atual->Apresentacao.num_inscritos++; // incrementar contador de inscritos
      } else {
        printf("ID %d nao encontrado, tenta outro.\n", id);
      }
    }

    printf("Total a pagar: %.2f EUR\n", p.total_pagar);
  }

  // atribuir id automatico
  p.id = contador++;

  if (inserirParticipante(lista, p) == 0)
    printf("Participante inserido com sucesso! ID: %d\n", p.id);
  else
    printf("Erro ao inserir participante!\n");
}

// pedir id e remover da lista
void menuRemoverParticipante(NoParticipante **lista) {
  int id;
  printf("Escreva o ID do Participante a eliminar: \n");
  scanf("%d", &id);

  removerParticipante(lista, id);
}

// inserir no na lista (logica interna)
int inserirParticipante(NoParticipante **lista, Participante p) {

  // arranjar espaco para o novo no
  NoParticipante *novo = (NoParticipante *)malloc(sizeof(NoParticipante));

  // verificar se o malloc teve sucesso
  if (novo == NULL) return -1;

  novo->participante = p;
  novo->proximo = *lista; // o novo aponta para a cabeca antiga
  *lista = novo;          // a cabeca passa a ser o novo no

  return 0;
}

// listar todos os participantes
void listarParticipante(NoParticipante *lista) {
  NoParticipante *atual = lista;

  if (atual == NULL) {
    printf("Nao existem participantes.\n");
    return;
  }

  while (atual != NULL) {
    printf("**************************\n");
    printf("ID: %d\n", atual->participante.id);
    printf("Nome: %s\n", atual->participante.nome);
    printf("Instituicao: %s\n", atual->participante.instituicao);
    printf("Inscricao: %s\n", atual->participante.tipo_inscricao == 0 ? "Aberta" : "Especifica");
    printf("Total a pagar: %.2f EUR\n", atual->participante.total_pagar);
    atual = atual->proximo; // passar ao proximo no
  }
}

// listar informacao de um participante especifico pelo ID
void listarParticipanteEspecifico(NoParticipante *lista) {
  int id;
  printf("Escreva o ID do participante: \n");
  scanf("%d", &id);

  // percorrer a lista ate encontrar o id
  NoParticipante *atual = lista;
  while (atual != NULL && atual->participante.id != id) {
    atual = atual->proximo;
  }

  if (atual == NULL) {
    printf("Participante nao encontrado!\n");
    return;
  }

  printf("**************************\n");
  printf("ID: %d\n", atual->participante.id);
  printf("Nome: %s\n", atual->participante.nome);
  printf("Instituicao: %s\n", atual->participante.instituicao);
  printf("Inscricao: %s\n", atual->participante.tipo_inscricao == 0 ? "Aberta" : "Especifica");
  printf("Total a pagar: %.2f EUR\n", atual->participante.total_pagar);

  // se inscricao especifica, mostrar as apresentacoes escolhidas
  if (atual->participante.tipo_inscricao == 1) {
    printf("Apresentacoes escolhidas: ");
    for (int i = 0; i < atual->participante.num_apresentacoes; i++) {
      printf("%d ", atual->participante.apresentacoes[i]);
    }
    printf("\n");
  }
}

// listar so os participantes com inscricao aberta
void listarParticipantesInscricaoAberta(NoParticipante *lista) {
  NoParticipante *atual = lista;
  int encontrou = 0;

  while (atual != NULL) {
    if (atual->participante.tipo_inscricao == 0) {
      printf("ID: %d | Nome: %s | Inst: %s\n",
             atual->participante.id,
             atual->participante.nome,
             atual->participante.instituicao);
      encontrou = 1;
    }
    atual = atual->proximo;
  }

  if (!encontrou)
    printf("Nenhum participante com inscricao aberta.\n");
}

// listar participantes inscritos numa apresentacao especifica
void listarParticipantesApresentacao(NoParticipante *lista) {
  int idApresentacao;
  printf("Escreva o ID da Apresentacao: \n");
  scanf("%d", &idApresentacao);

  NoParticipante *atual = lista;
  int encontrou = 0;

  while (atual != NULL) {
    // inscricao aberta — tem acesso a todas as apresentacoes
    if (atual->participante.tipo_inscricao == 0) {
      printf("ID: %d | Nome: %s (inscricao aberta)\n",
             atual->participante.id, atual->participante.nome);
      encontrou = 1;
    } else {
      // inscricao especifica — verificar se escolheu esta apresentacao
      for (int i = 0; i < atual->participante.num_apresentacoes; i++) {
        if (atual->participante.apresentacoes[i] == idApresentacao) {
          printf("ID: %d | Nome: %s\n",
                 atual->participante.id, atual->participante.nome);
          encontrou = 1;
          break;
        }
      }
    }
    atual = atual->proximo;
  }

  if (!encontrou)
    printf("Nenhum participante inscrito nesta apresentacao.\n");
}

// remover participante da lista por ID
void removerParticipante(NoParticipante **lista, int id) {
  NoParticipante *atual = *lista;
  NoParticipante *anterior = NULL;

  // percorre a lista enquanto nao encontrar o id ou chegar ao fim
  while (atual != NULL && atual->participante.id != id) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL) {
    printf("Erro - ID nao encontrado!\n");
    return;
  }

  // se o no a apagar e o primeiro da lista
  if (anterior == NULL) {
    *lista = atual->proximo; // a cabeca passa a ser o proximo
  } else {
    anterior->proximo = atual->proximo; // o anterior salta por cima do atual
  }

  free(atual); // libertar a memoria
  printf("Participante removido com sucesso!\n");
}

// somar o total de todas as inscricoes
void somarTotalInscricoes(NoParticipante *lista) {
  NoParticipante *atual = lista;
  float total = 0;

  while (atual != NULL) {
    total += atual->participante.total_pagar;
    atual = atual->proximo;
  }

  printf("Total de todas as inscricoes: %.2f EUR\n", total);
}

// consultar a inscricao do participante logado (procura pelo username)
void consultarInscricao(NoParticipante *lista, char *username) {
  NoParticipante *atual = lista;

  // procurar um participante cujo nome corresponda ao username
  while (atual != NULL) {
    if (strcmp(atual->participante.nome, username) == 0) {
      printf("**************************\n");
      printf("ID: %d\n", atual->participante.id);
      printf("Nome: %s\n", atual->participante.nome);
      printf("Instituicao: %s\n", atual->participante.instituicao);
      printf("Inscricao: %s\n", atual->participante.tipo_inscricao == 0 ? "Aberta" : "Especifica");
      printf("Total a pagar: %.2f EUR\n", atual->participante.total_pagar);

      if (atual->participante.tipo_inscricao == 1) {
        printf("Apresentacoes escolhidas (IDs): ");
        for (int i = 0; i < atual->participante.num_apresentacoes; i++) {
          printf("%d ", atual->participante.apresentacoes[i]);
        }
        printf("\n");
      }
      return;
    }
    atual = atual->proximo;
  }

  printf("Nao tem inscricao registada no sistema.\n");
}
