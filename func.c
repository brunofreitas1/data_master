#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

//Constantes menu
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_ALTERAR,
    OP_EXCLUIR,
    OP_PROCURAR,
    OP_RELATORIO,
    OP_SALVAR,
    OP_CARREGAR,
    OP_SAIR
};

//menu
int menu() {
    int op = OP_NAO_SELECIONADA;
    printf("\n--- Menu Principal ---\n");
    printf("%d - Adicionar\n", OP_ADICIONAR);
    printf("%d - Alterar\n", OP_ALTERAR);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Procurar\n", OP_PROCURAR);
    printf("%d - Relatório\n", OP_RELATORIO);
    printf("%d - Salvar em Arquivo\n", OP_SALVAR);
    printf("%d - Carregar do Arquivo\n", OP_CARREGAR);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opção: ");
    scanf("%d", &op);

    return op;
}


// Implementação da Árvore Binária

//MenorNo
NoArvore* menorNo(NoArvore *raiz) {
    while (raiz != NULL && raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

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

// Inserir na lista duplamente ligada, mantendo a ordenação por nome
NoDuplo* inserirListaDupla(NoDuplo *inicio, char *nome, int registroNum) {
    NoDuplo *novo = (NoDuplo *)malloc(sizeof(NoDuplo));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return inicio;
    }

    strcpy(novo->nome, nome);
    novo->registroNum = registroNum;
    novo->prev = NULL;
    novo->next = NULL;

    // Caso lista esteja vazia
    if (inicio == NULL) {
        return novo;
    }

    // Inserção ordenada
    NoDuplo *atual = inicio;
    NoDuplo *anterior = NULL;
    while (atual != NULL && strcmp(nome, atual->nome) > 0) {
        anterior = atual;
        atual = atual->next;
    }

    if (anterior == NULL) { // Inserir no início
        novo->next = inicio;
        inicio->prev = novo;
        return novo;
    }

    // Inserir no meio ou no final
    anterior->next = novo;
    novo->prev = anterior;
    novo->next = atual;
    if (atual != NULL) {
        atual->prev = novo;
    }

    return inicio;
}

// Excluir da lista duplamente ligada pelo nome
NoDuplo* excluirListaDupla(NoDuplo *inicio, char *nome) {
    NoDuplo *atual = inicio;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            // Reorganizar os ponteiros
            if (atual->prev != NULL) {
                atual->prev->next = atual->next;
            } else { // Caso seja o primeiro elemento
                inicio = atual->next;
            }
            if (atual->next != NULL) {
                atual->next->prev = atual->prev;
            }

            free(atual);
            printf("Registro com nome '%s' excluído com sucesso.\n", nome);
            return inicio;
        }
        atual = atual->next;
    }

    printf("Registro com nome '%s' não encontrado.\n", nome);
    return inicio;
}

// Listar todos os registros ordenados por nome
void listarOrdenados(NoDuplo *inicio) {
    NoDuplo *atual = inicio;

    printf("Registros ordenados por nome:\n");
    while (atual != NULL) {
        printf("  Nome: %s, Registro: %d\n", atual->nome, atual->registroNum);
        atual = atual->next;
    }
}

// Implementação de Persistência

// Percorre a lista dinâmica salvando os dados de registros em um arquivo .bin
void salvarEmArquivo(NoLista *inicio) {
    FILE *arquivo = fopen("registros.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    NoLista *atual = inicio;
    while (atual != NULL) {
        if (fwrite(&(atual->dados), sizeof(Registro), 1, arquivo) != 1) {
            printf("Erro ao salvar os dados no arquivo.\n");
            fclose(arquivo);
            return;
        }
        atual = atual->prox;
    }

    fclose(arquivo);
    printf("Registros salvos com sucesso no arquivo 'registros.bin'.\n");
}

// Lê os dados e recria a lista dinâmica com os arquivos recuperados
NoLista* carregarDeArquivo() {
    FILE *arquivo = fopen("registros.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo 'registros.bin' não encontrado. Nenhum dado carregado.\n");
        return NULL;
    }

    NoLista *inicio = NULL;
    Registro dados;
    int registroNum = 0;

    while (fread(&dados, sizeof(Registro), 1, arquivo) == 1) {
        inicio = adicionarLista(inicio, dados, registroNum);
        registroNum++;
    }

    fclose(arquivo);
    printf("Registros carregados com sucesso do arquivo 'registros.bin'.\n");
    return inicio;
}


// Menu Principal
void menuPrincipal() {
    NoArvore *raizArvore = NULL; // Árvore binária para índice de CPF
    NoLista *inicioLista = NULL; // Lista dinâmica para registros completos
    NoDuplo *inicioDuplo = NULL; // Lista duplamente ligada para ordenar por nome
    int opcao = OP_NAO_SELECIONADA;
    int registroNum = 0; // Contador para números de registro

    while (opcao != OP_SAIR) {
        opcao = menu();

        switch (opcao) {
            case OP_ADICIONAR: {
                Registro novoRegistro;
                printf("Digite o CPF: ");
                scanf("%s", novoRegistro.cpf);

                // Verificar se CPF já está na árvore
                if (buscarArvore(raizArvore, novoRegistro.cpf) != NULL) {
                    printf("Erro: CPF já cadastrado.\n");
                    break;
                }

                printf("Digite o Nome: ");
                scanf(" %[^\n]", novoRegistro.nome);
                printf("Digite o Endereço: ");
                scanf(" %[^\n]", novoRegistro.endereco);
                printf("Digite o Telefone: ");
                scanf("%s", novoRegistro.telefone);
                printf("Digite o Email: ");
                scanf("%s", novoRegistro.email);

                // Inserir na lista dinâmica
                inicioLista = adicionarLista(inicioLista, novoRegistro, registroNum);

                // Inserir na árvore binária
                raizArvore = inserirArvore(raizArvore, novoRegistro.cpf, registroNum);

                // Inserir na lista duplamente ligada
                inicioDuplo = inserirListaDupla(inicioDuplo, novoRegistro.nome, registroNum);

                printf("Registro adicionado com sucesso!\n");
                registroNum++;
                break;
            }

                case OP_ALTERAR: {
                    char cpf[12];
                    printf("Digite o CPF para alterar: ");
                    scanf("%s", cpf);

                    NoArvore *noEncontrado = buscarArvore(raizArvore, cpf);
                    if (noEncontrado == NULL) {
                    printf("Erro: CPF não encontrado.\n");
                    break;
                    }

                    int registroNum = noEncontrado->registroNum;
                    NoLista *registro = buscarLista(inicioLista, registroNum);

                    if (registro == NULL) {
                    printf("Erro: Registro não encontrado.\n");
                    break;
                    }

                    Registro novosDados = registro->dados;
                    printf("Digite o novo Nome (atual: %s): ", novosDados.nome);
                    scanf(" %[^\n]", novosDados.nome);
                    printf("Digite o novo Endereço (atual: %s): ", novosDados.endereco);
                    scanf(" %[^\n]", novosDados.endereco);
                    printf("Digite o novo Telefone (atual: %s): ", novosDados.telefone);
                    scanf("%s", novosDados.telefone);
                    printf("Digite o novo Email (atual: %s): ", novosDados.email);
                    scanf("%s", novosDados.email);

                    // Alterar na lista dinâmica
                    alterarLista(inicioLista, registroNum, novosDados);

                    // Atualizar na lista duplamente ligada (remover e reinserir para reordenar)
                    inicioDuplo = excluirListaDupla(inicioDuplo, registro->dados.nome);
                    inicioDuplo = inserirListaDupla(inicioDuplo, novosDados.nome, registroNum);

                    printf("Registro alterado com sucesso!\n");
                    break;
                }

                case OP_EXCLUIR: {
                    char cpf[12];
                    printf("Digite o CPF para excluir: ");
                    scanf("%s", cpf);

                    NoArvore *noEncontrado = buscarArvore(raizArvore, cpf);
                    if (noEncontrado == NULL) {
                    printf("Erro: CPF não encontrado.\n");
                    break;
                    }

                    int registroNum = noEncontrado->registroNum;

                    // Excluir da árvore binária
                    raizArvore = excluirArvore(raizArvore, cpf);

                    // Excluir da lista duplamente ligada
                    NoLista *registro = buscarLista(inicioLista, registroNum);
                    if (registro != NULL) {
                    inicioDuplo = excluirListaDupla(inicioDuplo, registro->dados.nome);
                    }

                    printf("Registro excluído com sucesso!\n");
                    break;
                }

                case OP_PROCURAR: {
                char cpf[12];
                printf("Digite o CPF para procurar: ");
                scanf("%s", cpf);

                NoArvore *noEncontrado = buscarArvore(raizArvore, cpf);
                if (noEncontrado == NULL) {
                    printf("Erro: CPF não encontrado.\n");
                    break;
                }

                int registroNum = noEncontrado->registroNum;
                NoLista *registro = buscarLista(inicioLista, registroNum);

                if (registro != NULL) {
                    printf("CPF: %s\n", registro->dados.cpf);
                    printf("Nome: %s\n", registro->dados.nome);
                    printf("Endereço: %s\n", registro->dados.endereco);
                    printf("Telefone: %s\n", registro->dados.telefone);
                    printf("Email: %s\n", registro->dados.email);
                } else {
                    printf("Erro: Registro não encontrado.\n");
                }
                break;
            }

                case OP_RELATORIO: {
                listarOrdenados(inicioDuplo);
                break;
            }

            case OP_SALVAR: {
                salvarEmArquivo(inicioLista);
                break;
            }

            case OP_CARREGAR: {
                inicioLista = carregarDeArquivo();
                printf("Os registros carregados precisarão ser reintegrados às listas e à árvore.\n");
                break;
            }

                case OP_SAIR: {
                printf("Encerrando o programa...\n");
                liberarArvore(raizArvore);
                break;
            }

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

