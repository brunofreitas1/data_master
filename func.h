#ifndef FUNC_H
#define FUNC_H

#include <stdbool.h>

// Estruturas de dados
typedef struct Registro {
    char cpf[12];
    char nome[100];
    char endereco[200];
    char telefone[15];
    char email[100];
} Registro;

typedef struct NoArvore {
    char cpf[12];
    int registroNum;
    struct NoArvore *esq, *dir;
} NoArvore;

typedef struct NoLista {
    Registro dados;
    int registroNum;
    struct NoLista *prox;
} NoLista;

typedef struct NoDuplo {
    char nome[100];
    int registroNum;
    struct NoDuplo *prev, *next;
} NoDuplo;

// Funções gerais
void menuPrincipal();

// Funções da árvore binária
NoArvore* inserirArvore(NoArvore *raiz, char *cpf, int registroNum);
NoArvore* buscarArvore(NoArvore *raiz, char *cpf);
NoArvore* excluirArvore(NoArvore *raiz, char *cpf);
void liberarArvore(NoArvore *raiz);

// Funções da lista dinâmica
NoLista* adicionarLista(NoLista *inicio, Registro dados, int registroNum);
void alterarLista(NoLista *inicio, int registroNum, Registro dados);
NoLista* buscarLista(NoLista *inicio, int registroNum);
void listarTodos(*NoLista *inicio)

// Funções da lista duplamente ligada
NoDuplo* inserirListaDupla(NoDuplo *inicio, char *nome, int registroNum);
NoDuplo* excluirListaDupla(NoDuplo *inicio, char *nome);
void listarOrdenados(NoDuplo *inicio);

// Funções de persistência
void salvarEmArquivo(NoLista *inicio);
NoLista* carregarDeArquivo();

#endif // FUNC_H
