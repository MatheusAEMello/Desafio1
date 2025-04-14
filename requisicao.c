#include <stdlib.h>
#include <string.h>
#include "requisicao.h"

struct requisicao {
    char nome[TAM_NOME];
    int inscricao;
    char procedimento[TAM_PROCEDIMENTO];
};

Requisicao* cria_requisicao(const char *nome, int inscricao, const char *procedimento) {
    Requisicao *req = (Requisicao *) malloc(sizeof(Requisicao));
    if (req) {
        strncpy(req->nome, nome, TAM_NOME - 1);
        req->nome[TAM_NOME - 1] = '\0';
        req->inscricao = inscricao;
        strncpy(req->procedimento, procedimento, TAM_PROCEDIMENTO - 1);
        req->procedimento[TAM_PROCEDIMENTO - 1] = '\0';
    }
    return req;
}

const char* get_nome(const Requisicao *req) {
    return req->nome;
}

int get_inscricao(const Requisicao *req) {
    return req->inscricao;
}

const char* get_procedimento(const Requisicao *req) {
    return req->procedimento;
}

void libera(Requisicao *req) {
    free(req);
}
