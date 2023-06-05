#ifndef _EXABB_
#define _EXABB_
#include <stdio.h>
#include <stdlib.h>
typedef struct EstruturaNo{
    void *dado;
    struct EstruturaNo *pai;
    struct EstruturaNo *esq;
    struct EstruturaNo *dir;
    int (*compara) (const void *a, const void *b, int h);
    void (*printDado) (const void*no);
}No;
void printInOrder(No* p);
void removerPonto(No** Ponto);
void inserirNoArvoreUnico(No** Parv, No* novoNo, int ordem);
No* criarNo(void **dado, int (*compara)(const void* a, const void* b, const int h));
void encerrarPrograma(No** Parv);
void encontraPredecessor(No* Parv, int* tamSbr,float p[], int tamAnt, int k, No* lista);
void encontraKSucessores(No* Parv,int* k, No* lista);
#endif