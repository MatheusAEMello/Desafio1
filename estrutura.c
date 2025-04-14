#include <stdlib.h>
#include "estrutura.h"

typedef struct nodo {
    Requisicao *req;
    struct nodo *prox;   
} Nodo;

struct estrutura {
    Nodo *head;
    Nodo *tail;
    int size;
};

Estrutura* create(void) {
    Estrutura *e = (Estrutura*) malloc(sizeof(Estrutura));
    if(e) {
        e->head = NULL;
        e->tail = NULL;
        e->size = 0;
    }
    return e;
}

void inserir(Estrutura* estrutura, Requisicao* requisicao) {
    if(!estrutura)
        return;
    
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    if(!novo)
        return;
    
    novo->req = requisicao;
    novo->prox = NULL;
    
    if(estrutura->tail == NULL) {
        estrutura->head = novo;
        estrutura->tail = novo;
    } else {
        estrutura->tail->prox = novo;
        estrutura->tail = novo;
    }
    estrutura->size++;
}

Requisicao* remover(Estrutura* estrutura) {
    if(!estrutura || estrutura->head == NULL)
        return NULL;
    
    Nodo *temp = estrutura->head;
    Requisicao *req = temp->req;
    
    estrutura->head = temp->prox;
    if(estrutura->head == NULL)
        estrutura->tail = NULL;
    
    free(temp);
    estrutura->size--;
    return req;
}

int get_size(Estrutura* estrutura) {
    return (estrutura ? estrutura->size : 0);
}
void libera_estrutura(Estrutura* estrutura) {
    if(!estrutura)
        return;
    
    Nodo *atual = estrutura->head;
    while(atual) {
        Nodo *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(estrutura);
}
