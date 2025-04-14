#ifndef REQUISICAO_H
#define REQUISICAO_H

#define TAM_NOME 40
#define TAM_PROCEDIMENTO 10

typedef struct requisicao Requisicao;


Requisicao* cria_requisicao(const char *nome, int inscricao, const char *procedimento);

const char* get_nome(const Requisicao *req);

int get_inscricao(const Requisicao *req);

const char* get_procedimento(const Requisicao *req);

void libera(Requisicao *req);

#endif
