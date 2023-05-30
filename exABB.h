#ifndef _EXABB_
#define _EXABB_
#include <stdio.h>
#include <stdlib.h>
typedef struct EstruturaNo{
    void *dado;
    struct EstruturaNo *pai;
    struct EstruturaNo *esq;
    struct EstruturaNo *dir;
    int h;
    int (*compara) (cons void *a, const void *b);
}No;
void printInOrder(No* p);
void removerPonto(No** Ponto);
void inserir(No** Parv, void* dado);
No* criarNo(void *dado, int (*compara_peso)(const void* a, const void* b));s
void encerrarPrograma(No** Parv);
void encontraPredecessor(No** Parv);
void encontraSucessor(No** Parv);
#endif