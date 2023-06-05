#include "ex.h"
#include "exABB.h"
#include <math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
void printInOrder(No* p){
  if(p!=NULL){  
    p->printDado(p->dado);
    printInOrder(p->esq);
    printInOrder(p->dir);
  }
  return;
}
void removerPonto(No** Ponto){
  if(Ponto==NULL){
    return;
  }
  if((*Ponto)->dir==NULL && (*Ponto)->esq==NULL){
    free((*Ponto)->dado);
    free((*Ponto));
    Ponto=NULL;
    return;
  }
  else if((*Ponto)->esq!=NULL){
    No* pai=(*Ponto)->pai;
    No* dir=(*Ponto)->dir;
    No* pontotroca=(*Ponto)->esq;
    No* pontotrocaesq;
    while(pontotroca->dir!=NULL){
      pontotroca=pontotroca->dir;
    }
    pontotrocaesq=pontotroca;
    while(pontotrocaesq->esq!=NULL){
      pontotrocaesq=pontotrocaesq->esq;
    }
    if((*Ponto)!=pontotroca){
      (*Ponto)->esq->pai=pontotrocaesq;
      pontotrocaesq->esq=(*Ponto)->esq;
      (*Ponto)->esq->dir=NULL;
      (*Ponto)->esq=pontotroca;
      pontotroca->pai=(*Ponto);
    }
    else{
      pai->esq=pontotroca;
      pontotroca->pai=pai;
    }
    if(dir!=NULL){
      dir->pai=pontotroca;
      pontotroca->dir=dir;
    }
  }
  else{
    No* pai=(*Ponto)->pai;
    No* dir=(*Ponto)->dir;
    pai->dir=dir;
    dir->pai=pai;
  }
  free((*Ponto)->dado);
  free((*Ponto));
}
No* criarNo(void **dado, int (*compara)(const void* a, const void* b, int h)) {
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o nó\n");
        return NULL;
    }
    void* aux=*dado;
    novoNo->dado = dado;
    novoNo->pai = NULL;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->compara = compara;
    novoNo->printDado = NULL;
    
    return novoNo;
}
void inserirNoArvoreUnico(No** Parv, No* novoNo, int ordem) {
    if (*Parv == NULL) {
        *Parv = novoNo;
        printf("Nó foi inserido na primeira posição\n");
        return;
    }
    printf("%d",(*Parv)->compara((*Parv)->dado,novoNo->dado, ordem) == 1);
    printf("Nó não foi inserido na primeira posição\n");

    int grandezaAtual = ordem % 2;

    if ((*Parv)->compara((*Parv)->dado, novoNo->dado, grandezaAtual) == 1) {
      printf("comparação feita");
        if ((*Parv)->dir == NULL) {
            (*Parv)->dir = novoNo;
            novoNo->pai = (*Parv)->dir;
            printf("Incluindo à direita\n");
            return;
        } else {
            inserirNoArvoreUnico(&((*Parv)->dir), &(*novoNo), ordem + 1);
        }
    } else {
      printf("comparação feita");
        if ((*Parv)->esq == NULL) {
            (*Parv)->esq = novoNo;
          novoNo->pai = (*Parv)->esq;
            printf("Incluindo à esquerda\n");
            return;
        } else {
            inserirNoArvoreUnico(&((*Parv)->esq), &(*novoNo), ordem + 1);
        }
    }
}