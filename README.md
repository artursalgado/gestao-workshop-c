# Gestão de Inscrições num Workshop

Projeto de Programação I — ESTG IPVC | Turno PL1 | Ano letivo 2025/2026

## Descrição

Sistema em linguagem C para gerir os participantes e apresentações de um workshop organizado pela ESTG. O workshop tem 16 apresentações e suporta inscrição aberta (acesso total) ou inscrição específica (conjunto de apresentações à escolha).

## Funcionalidades

### Administrador
- Registar, remover e alterar apresentações
- Escalonar apresentações (atribuir data/hora)
- Inscrever participantes e calcular total a pagar
- Listar participantes e apresentações
- Exportar programa do workshop para ficheiro

### Participante
- Consultar a sua inscrição
- Consultar agenda e informação das apresentações

## Estrutura do projeto

```
├── include/          # Headers (.h) — structs e protótipos
│   ├── apresentacao.h
│   ├── participante.h
│   ├── utilizador.h
│   └── workshop.h
├── src/              # Código fonte (.c)
│   ├── main.c
│   └── participante.c
├── data/             # Ficheiros binários (persistência)
└── relatorios/       # Ficheiros de texto (relatórios)
```

## Compilação

```bash
gcc src/*.c -I include/ -o programa
```

## Tecnologias

- Linguagem C
- Listas ligadas
- Ficheiros binários e de texto
- Algoritmos de ordenação e pesquisa
