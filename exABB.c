#include"exABB.h"
void printInOrder(No* p){
  if(p!=NULL){  
    printDado(p->dado);
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
No* criarNo(void *dado, int (*compara_peso)(const void* a, const void* b)) {
  No *NovoNo = (No *)calloc(1, sizeof(No));
  NovoNo->dado = dado;
  NovoNo->compara=compara_peso;
  return NovoNo;
}
void inserirNoArvoreUnico(No** Parv, void* novoNo, int ordem){
    if(*Parv==NULL){
        *Parv=novoNo;
        No* tmp=novoNo;
        tmp->h=ordem;
        return;
    }
    int grandezaAtual=ordem%2;
    if(grandezaAtual==0){
        if((*Parv)->compara((*Parv),novoNo)==1){
            if((*Parv)->dir==NULL){
                (*Parv)->dir=novoNo;
                No* tmp=novoNo;
                tmp->h=ordem;
                return;
            }
            else{
                inserirNoArvoreUnico(&((*Parv)->dir), novoNo, ordem+1);
            }
        }
        else{
            if((*Parv)->esq==NULL){
                (*Parv)->esq=novoNo;
                No* tmp=novoNo;
                tmp->h=ordem;
                return;
            }
            else{
                inserirNoArvoreUnico(&((*Parv)->esq), novoNo, ordem+1);
            }
        }
    }//grandeza x
    else{
        if((*Parv)->compara((*Parv),novoNo)==1){
            if((*Parv)->dir==NULL){
                (*Parv)->dir=novoNo;
                No* tmp=novoNo;
                tmp->h=ordem;
                return;
            }
            else{
                inserirNoArvoreUnico(&((*Parv)->dir), novoNo, ordem+1);
            }
        }
        else{
            if((*Parv)->esq==NULL){
                (*Parv)->esq=novoNo;
                No* tmp=novoNo;
                tmp->h=ordem;
                return;
            }
            inserirNoArvoreUnico(&((*Parv)->esq), novoNo, ordem+1);
        }
    }//grandeza y
    return;
}
void encontraSucessor(No** Parv);
void encontraPredecessor(No** Parv){
  if((*Parv)->esq!=NULL){

  }else{

  }
}