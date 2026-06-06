#include "../include/workshop.h"
#include <stdio.h>

void configurarWorkshop(Workshop *w) {
  // pedir as datas e o preco do bilhete aberto ao admin
  printf("Data de inicio do workshop (ex: 2025-06-10): \n");
  scanf(" %[^\n]", w->data_inicio);

  printf("Data de fim do workshop (ex: 2025-06-12): \n");
  scanf(" %[^\n]", w->data_fim);

  printf("Preco do bilhete aberto (acesso total): \n");
  scanf("%f", &w->preco_inscricao_aberta);

  printf("Workshop configurado! De %s ate %s | Preco aberto: %.2f EUR\n",
         w->data_inicio, w->data_fim, w->preco_inscricao_aberta);
}
