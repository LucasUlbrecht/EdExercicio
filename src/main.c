#include "ex.h"
#include "exABB.h"
#include <math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
int main (void){
    No* Parv=NULL;
    int resposta;
    do{
    printf("Bem vindo ao programa exEd, se deseja ler/gerar arvore kd Fasfood Digite - 0, se deseja ler/gerar arvore kd Municipios Digite - 1\n");
    scanf("%d", &resposta);
    }while(resposta<0 || resposta>1);
    if(resposta==1){
        do{
        resposta=interfaceInserirSimples();
        if(resposta==0){
            lerListaMunic(&Parv);
          if(Parv==NULL){
            printf("dado não incluído");
          }
          else{
            printInOrder(Parv);
          }
        }
        else if(resposta==1){
          float px, py;
          printf("digite os x e o y do ponto mais proximo que deseja procurar");
          scanf("%f %f", &px, &py);
          No* tmp= buscarPonto(Parv, px, py, 0);
          tmp->printDado(tmp->dado);
        }
        else if(resposta == 2){
          int cod;
          printf("Digite o codigo que quer encontrar\n");
          scanf("%d", &cod);
          No*resp=encontrarPontoCod(Parv, cod);
          resp->printDado(resp->dado);
        }else if(resposta==3){
            encerrarPrograma(&Parv);
            return EXIT_SUCCESS;
        }
        }while(1);
    }else if(resposta==0){
      do{
        resposta=interfaceInserirSimples();
        if(resposta==0){
          printf("Gerando arvore\n");
          lerListaFast(&Parv);
        }else if(resposta==1){
          float px, py;
          printf("digite os x e o y do ponto mais proximo que deseja procurar");
          scanf("%f %f", &px, &py);
          FastF tmp;
          tmp.Latitude=py;
          tmp.Longitude=px;
          void*aux=(void*)&tmp;
          No* no;
          no->dado=aux;
          No* resp= buscarFast(Parv, aux, 0);
        }
      }while(1);
      
  }
}