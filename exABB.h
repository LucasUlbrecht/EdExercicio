#ifndef _EXABB_
#define _EXABB_
#include <stdio.h>
#include <stdlib.h>
typedef struct EstruturaNo{
    void *dado;
    struct EstruturaNo *pai;
    struct EstruturaNo *esq;
    struct EstruturaNo *dir;
}No;
void printInOrder(No* p);
void removerPonto(No* Ponto);
void inserir(No** Parv, void* dado);
No* criarNo(void* dado);
void encerrarPrograma(No** Parv);
#endif