#ifndef _EDTRABAIO_
#define _EDTRABAIO_

typedef struct _node{
    void * item;
    struct _node *esq;
    struct _node *dir;
    int h;
}tnode;


void avl_insere(tnode ** parv,titem reg);
void avl_rebalancear(tnode **parv);

#endif