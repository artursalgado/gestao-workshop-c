#include "../include/apresentacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inserir apresentacao na lista (logica interna)
int inserirApresentacao(NoApresentacao **lista, Apresentacao a) {
  // arranjar espaco para o novo no
  NoApresentacao *novo = (NoApresentacao *)malloc(sizeof(NoApresentacao));

  // verificar se o malloc teve sucesso
  if (novo == NULL) return -1;

  novo->Apresentacao = a;
  novo->proximo = *lista; // o novo aponta para a cabeca antiga
  *lista = novo;          // a cabeca passa a ser o novo no

  return 0;
}

// pedir dados ao admin e inserir nova apresentacao
void menuInserirApresentacao(NoApresentacao **lista) {

  Apresentacao apresentacao;

  // id automatico — incrementa a cada apresentacao adicionada
  static int contador = 1;
  apresentacao.id = contador++;

  // a data fica vazia ate o admin definir o horario
  strcpy(apresentacao.data, "sem horario definido");
  apresentacao.num_inscritos = 0;

  printf("**************\n");
  printf("Titulo da Apresentacao: \n");
  scanf(" %[^\n]", apresentacao.titulo);
  printf("Nome do Orador: \n");
  scanf(" %[^\n]", apresentacao.orador);
  printf("Curriculo do Orador: \n");
  scanf(" %[^\n]", apresentacao.curriculo);
  printf("Duracao (em minutos): \n");
  scanf("%d", &apresentacao.duracao);
  printf("Preco: \n");
  scanf("%f", &apresentacao.preco);

  printf("--- Palavras Chave ---\n");
  for (int i = 0; i < 5; i++) {
    printf("Palavra-chave %d: \n", i + 1);
    scanf("%s", apresentacao.palavras_chave[i]);
  }

  if (inserirApresentacao(lista, apresentacao) == 0)
    printf("Apresentacao inserida! ID: %d\n", apresentacao.id);
  else
    printf("Erro ao inserir apresentacao!\n");
}

// pedir ID e alterar os dados da apresentacao
void menuAlterarApresentacao(NoApresentacao *lista) {
  int id;
  printf("ID da Apresentacao a alterar: \n");
  scanf("%d", &id);

  // percorrer a lista para encontrar a apresentacao
  NoApresentacao *atual = lista;
  while (atual != NULL && atual->Apresentacao.id != id) {
    atual = atual->proximo;
  }

  if (atual == NULL) {
    printf("Erro - ID nao encontrado!\n");
    return;
  }

  // pedir novos dados (mostra o atual para referencia)
  printf("Novo titulo (atual: %s): \n", atual->Apresentacao.titulo);
  scanf(" %[^\n]", atual->Apresentacao.titulo);

  printf("Novo orador (atual: %s): \n", atual->Apresentacao.orador);
  scanf(" %[^\n]", atual->Apresentacao.orador);

  printf("Nova duracao em minutos (atual: %d): \n", atual->Apresentacao.duracao);
  scanf("%d", &atual->Apresentacao.duracao);

  printf("Novo preco (atual: %.2f): \n", atual->Apresentacao.preco);
  scanf("%f", &atual->Apresentacao.preco);

  printf("Apresentacao alterada com sucesso!\n");
}

// pedir ID e remover apresentacao da lista
void menuRemoverApresentacao(NoApresentacao **lista) {
  int id;
  printf("ID da Apresentacao a eliminar: \n");
  scanf("%d", &id);

  removerApresentacao(lista, id);
}

// remover no da lista por ID (logica interna)
void removerApresentacao(NoApresentacao **lista, int id) {
  NoApresentacao *atual = *lista;
  NoApresentacao *anterior = NULL;

  // percorre a lista enquanto nao encontrar o id ou chegar ao fim
  while (atual != NULL && atual->Apresentacao.id != id) {
    anterior = atual;
    atual = atual->proximo; // passar ao proximo no
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
  printf("Apresentacao removida com sucesso!\n");
}

// definir a data/hora de uma apresentacao pelo ID
void menuHorarioApresentacao(NoApresentacao *lista) {
  int id;
  printf("ID da Apresentacao a definir horario: \n");
  scanf("%d", &id);

  // percorrer a lista para encontrar a apresentacao
  NoApresentacao *atual = lista;
  while (atual != NULL && atual->Apresentacao.id != id) {
    atual = atual->proximo; // passar ao proximo no
  }

  if (atual == NULL) {
    printf("Erro - ID nao encontrado!\n");
    return;
  }

  // pedir a data/hora e guardar
  printf("Data e hora (ex: 2025-06-10 14:00): \n");
  scanf(" %[^\n]", atual->Apresentacao.data);

  printf("Horario definido com sucesso!\n");
}

// listar todas as apresentacoes
void listarApresentacoes(NoApresentacao *lista) {
  NoApresentacao *atual = lista;

  if (atual == NULL) {
    printf("Nao existem apresentacoes registadas.\n");
    return;
  }

  while (atual != NULL) {
    printf("**************\n");
    printf("ID: %d\n", atual->Apresentacao.id);
    printf("Titulo: %s\n", atual->Apresentacao.titulo);
    printf("Orador: %s\n", atual->Apresentacao.orador);
    printf("Curriculo: %s\n", atual->Apresentacao.curriculo);
    printf("Duracao: %d minutos\n", atual->Apresentacao.duracao);
    printf("Preco: %.2f EUR\n", atual->Apresentacao.preco);
    printf("Data: %s\n", atual->Apresentacao.data);
    printf("Inscritos: %d\n", atual->Apresentacao.num_inscritos);
    printf("Palavras-chave: ");
    for (int i = 0; i < 5; i++) {
      printf("%s ", atual->Apresentacao.palavras_chave[i]);
    }
    printf("\n");
    atual = atual->proximo;
  }
}

// mostrar info de uma apresentacao especifica (para o menu participante)
void consultarApresentacaoEspecifica(NoApresentacao *lista) {
  int id;
  printf("ID da Apresentacao: \n");
  scanf("%d", &id);

  // percorrer ate encontrar
  NoApresentacao *atual = lista;
  while (atual != NULL && atual->Apresentacao.id != id) {
    atual = atual->proximo;
  }

  if (atual == NULL) {
    printf("Apresentacao nao encontrada!\n");
    return;
  }

  printf("**************\n");
  printf("ID: %d\n", atual->Apresentacao.id);
  printf("Titulo: %s\n", atual->Apresentacao.titulo);
  printf("Orador: %s\n", atual->Apresentacao.orador);
  printf("Curriculo: %s\n", atual->Apresentacao.curriculo);
  printf("Duracao: %d minutos\n", atual->Apresentacao.duracao);
  printf("Preco: %.2f EUR\n", atual->Apresentacao.preco);
  printf("Data: %s\n", atual->Apresentacao.data);
  printf("Palavras-chave: ");
  for (int i = 0; i < 5; i++) {
    printf("%s ", atual->Apresentacao.palavras_chave[i]);
  }
  printf("\n");
}

// ordenar apresentacoes por titulo — bubble sort trocando os dados dos nos
void ordenarApresentacoesTitulo(NoApresentacao *lista) {
  if (lista == NULL || lista->proximo == NULL) {
    printf("Nada para ordenar.\n");
    return;
  }

  int trocou;
  NoApresentacao *atual;

  // bubble sort — passa pela lista ate nao haver mais trocas
  do {
    trocou = 0;
    atual = lista;
    while (atual->proximo != NULL) {
      if (strcmp(atual->Apresentacao.titulo, atual->proximo->Apresentacao.titulo) > 0) {
        // trocar os dados dos dois nos (nao os ponteiros)
        Apresentacao temp = atual->Apresentacao;
        atual->Apresentacao = atual->proximo->Apresentacao;
        atual->proximo->Apresentacao = temp;
        trocou = 1;
      }
      atual = atual->proximo;
    }
  } while (trocou);

  printf("Apresentacoes ordenadas por titulo!\n");
}

// listar apresentacoes ordenadas por data
void listarApresentacoesPorData(NoApresentacao *lista) {
  if (lista == NULL) {
    printf("Nao existem apresentacoes.\n");
    return;
  }

  // copiar para array (max 16 apresentacoes) para ordenar sem alterar a lista original
  Apresentacao arr[16];
  int n = 0;

  NoApresentacao *atual = lista;
  while (atual != NULL && n < 16) {
    arr[n++] = atual->Apresentacao;
    atual = atual->proximo;
  }

  // bubble sort por data — formato YYYY-MM-DD permite comparar como string
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(arr[j].data, arr[j + 1].data) > 0) {
        Apresentacao temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  // imprimir na ordem certa
  printf("--- Apresentacoes por data ---\n");
  for (int i = 0; i < n; i++) {
    printf("**************\n");
    printf("Data: %s\n", arr[i].data);
    printf("ID: %d | Titulo: %s\n", arr[i].id, arr[i].titulo);
    printf("Orador: %s | Duracao: %d min | Preco: %.2f EUR\n",
           arr[i].orador, arr[i].duracao, arr[i].preco);
  }
}

// encontrar e mostrar a apresentacao com mais inscritos
void apresentacaoMaisInscricoes(NoApresentacao *lista) {
  if (lista == NULL) {
    printf("Nao existem apresentacoes.\n");
    return;
  }

  NoApresentacao *atual = lista;
  NoApresentacao *maisInscritos = lista; // comecar com a primeira

  // percorre a lista toda e guarda a que tiver mais inscritos
  while (atual != NULL) {
    if (atual->Apresentacao.num_inscritos > maisInscritos->Apresentacao.num_inscritos) {
      maisInscritos = atual;
    }
    atual = atual->proximo;
  }

  printf("Apresentacao com mais inscricoes:\n");
  printf("Titulo: %s | Inscritos: %d\n",
         maisInscritos->Apresentacao.titulo,
         maisInscritos->Apresentacao.num_inscritos);
}

// guardar o programa do workshop (ordenado por data) num ficheiro texto
void imprimirProgramaWorkshop(NoApresentacao *lista) {
  FILE *f = fopen("relatorios/programa_workshop.txt", "w");
  if (f == NULL) {
    printf("Erro ao criar ficheiro de relatorio!\n");
    return;
  }

  fprintf(f, "=== PROGRAMA DO WORKSHOP ===\n\n");

  // copiar para array e ordenar por data
  Apresentacao arr[16];
  int n = 0;
  NoApresentacao *atual = lista;
  while (atual != NULL && n < 16) {
    arr[n++] = atual->Apresentacao;
    atual = atual->proximo;
  }

  // ordenar por data
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(arr[j].data, arr[j + 1].data) > 0) {
        Apresentacao temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  // escrever cada apresentacao no ficheiro
  for (int i = 0; i < n; i++) {
    fprintf(f, "Data/Hora: %s\n", arr[i].data);
    fprintf(f, "Titulo: %s\n", arr[i].titulo);
    fprintf(f, "Orador: %s\n", arr[i].orador);
    fprintf(f, "Duracao: %d minutos\n", arr[i].duracao);
    fprintf(f, "Preco: %.2f EUR\n", arr[i].preco);
    fprintf(f, "Inscritos: %d\n", arr[i].num_inscritos);
    fprintf(f, "---\n");
  }

  fclose(f);
  printf("Programa guardado em relatorios/programa_workshop.txt\n");
}
