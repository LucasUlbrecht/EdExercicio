#include"ex.h"
void printInOrder(No* p){
  if(p!=NULL){  
    printDado(p->dado);
    printInOrder(p->esq);
    printInOrder(p->dir);
  }
  return;
}
void removerPonto(No* Ponto){
  if(Ponto==NULL){
    return;
  }
  if((Ponto)->dir==NULL && (Ponto)->esq==NULL){
    if((Ponto)->pai!=NULL){
      if((Ponto)->pai->esq==(Ponto)){
        (Ponto)->pai->esq=NULL;
      }
      else{
        (Ponto)->pai->dir=NULL;
      }
    }
    free((Ponto)->dado);
    free((Ponto));
    return;
  }
  else if((Ponto)->esq!=NULL){
    No* pai=(Ponto)->pai;
    No* dir=(Ponto)->dir;
    No* pontotroca=(Ponto)->esq;
    No* pontotrocaesq;
    while(pontotroca->dir!=NULL){
      pontotroca=pontotroca->dir;
    }
    pontotrocaesq=pontotroca;
    while(pontotrocaesq->esq!=NULL){
      pontotrocaesq=pontotrocaesq->esq;
    }
    if((Ponto)!=pontotroca){
      (Ponto)->esq->pai=pontotrocaesq;
      pontotrocaesq->esq=(Ponto)->esq;
      (Ponto)->esq->dir=NULL;
      (Ponto)->esq=pontotroca;
      pontotroca->pai=(Ponto);
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
    No* pai=(Ponto)->pai;
    No* dir=(Ponto)->dir;
    pai->dir=dir;
    dir->pai=pai;
  }
  free((Ponto)->dado);
  free((Ponto));
}