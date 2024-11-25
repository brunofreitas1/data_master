#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

// Implementação da Árvore Binária

// Função para criar um novo nó da árvore
NoArvore* novoNo(char *cpf, int registroNum) {
    NoArvore *novo = (NoArvore *)malloc(sizeof(NoArvore));
    strcpy(novo->cpf, cpf);
    novo->registroNum = registroNum;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Inserir na árvore binária
NoArvore* inserirArvore(NoArvore *raiz, char *cpf, int registroNum) {
    if (raiz == NULL) {
        return novoNo(cpf, registroNum);
    }
    if (strcmp(cpf, raiz->cpf) < 0) {
        raiz->esq = inserirArvore(raiz->esq, cpf, registroNum);
    } else if (strcmp(cpf, raiz->cpf) > 0) {
        raiz->dir = inserirArvore(raiz->dir, cpf, registroNum);
    }
    return raiz;
}

// Buscar na árvore binária
NoArvore* buscarArvore(NoArvore *raiz, char *cpf) {
    if (raiz == NULL || strcmp(cpf, raiz->cpf) == 0) {
        return raiz;
    }
    if (strcmp(cpf, raiz->cpf) < 0) {
        return buscarArvore(raiz->esq, cpf);
    } else {
        return buscarArvore(raiz->dir, cpf);
    }
}

// Excluir da árvore binária
NoArvore* excluirArvore(NoArvore *raiz, char *cpf) {
    if (raiz == NULL) {
        return NULL;
    }

    if (strcmp(cpf, raiz->cpf) < 0) {
        raiz->esq = excluirArvore(raiz->esq, cpf);
    } else if (strcmp(cpf, raiz->cpf) > 0) {
        raiz->dir = excluirArvore(raiz->dir, cpf);
    } else {
        if (raiz->esq == NULL) {
            NoArvore *temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            NoArvore *temp = raiz->esq;
            free(raiz);
            return temp;
        }
        NoArvore *temp = menorNo(raiz->dir);
        strcpy(raiz->cpf, temp->cpf);
        raiz->registroNum = temp->registroNum;
        raiz->dir = excluirArvore(raiz->dir, temp->cpf);
    }
    return raiz;
}

// Liberar memória da árvore
void liberarArvore(NoArvore *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

// Implementação da Lista Dinâmica


// Função para adicionar um novo registro à lista dinâmica
NoLista* adicionarLista(NoLista *inicio, Registro dados, int registroNum) {
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return inicio;
    }

    novo->dados = dados;
    novo->registroNum = registroNum;
    novo->prox = inicio;
    return novo;
}

// Função para alterar um registro existente na lista dinâmica
void alterarLista(NoLista *inicio, int registroNum, Registro novosDados) {
    NoLista *atual = inicio;

    while (atual != NULL) {
        if (atual->registroNum == registroNum) {
            atual->dados = novosDados;
            printf("Registro alterado com sucesso!\n");
            return;
        }
        atual = atual->prox;
    }
    printf("Registro não encontrado.\n");
}

// Função para buscar um registro na lista dinâmica pelo número de registro
NoLista* buscarLista(NoLista *inicio, int registroNum) {
    NoLista *atual = inicio;

    while (atual != NULL) {
        if (atual->registroNum == registroNum) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

// Função auxiliar para listar todos os registros (debug ou relatório simples)
void listarTodos(NoLista *inicio) {
    NoLista *atual = inicio;

    while (atual != NULL) {
        printf("Registro %d:\n", atual->registroNum);
        printf("  CPF: %s\n", atual->dados.cpf);
        printf("  Nome: %s\n", atual->dados.nome);
        printf("  Endereço: %s\n", atual->dados.endereco);
        printf("  Telefone: %s\n", atual->dados.telefone);
        printf("  Email: %s\n", atual->dados.email);
        atual = atual->prox;
    }
}

// Implementação da Lista Duplamente Ligada
NoDuplo* inserirListaDupla(NoDuplo *inicio, char *nome, int registroNum) { /* Implementação da função */ }
NoDuplo* excluirListaDupla(NoDuplo *inicio, char *nome) { /* Implementação da função */ }
void listarOrdenados(NoDuplo *inicio) { /* Implementação da função */ }

// Implementação de Persistência
void salvarEmArquivo(NoLista *inicio) { /* Implementação da função */ }
NoLista* carregarDeArquivo() { /* Implementação da função */ }

// Menu Principal
void menuPrincipal() {
    int opcao;
    do {
        printf("\nMenu Principal:\n");
        printf("1. Adicionar\n");
        printf("2. Alterar\n");
        printf("3. Excluir\n");
        printf("4. Procurar\n");
        printf("5. Relatório\n");
        printf("6. Salvar em Arquivo\n");
        printf("7. Carregar do Arquivo\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: /* Chamar função de adicionar */ break;
            case 2: /* Chamar função de alterar */ break;
            case 3: /* Chamar função de excluir */ break;
            case 4: /* Chamar função de procurar */ break;
            case 5: /* Chamar função de relatório */ break;
            case 6: /* Chamar salvarEmArquivo */ break;
            case 7: /* Chamar carregarDeArquivo */ break;
            case 8: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while(opcao != 8);
}
