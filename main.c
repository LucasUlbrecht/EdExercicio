#include"ex.h"
#include"test.h"
int main (void){
    No* Parv=NULL;
    int resposta;
    do{
    printf("Bem vindo ao programa exEd, se deseja ler/gerar lista Digite - 0, se deseja realizar rápido checkup das funções basicas Digite - 1\n");
    scanf("%d", &resposta);
    }while(resposta<0 || resposta>1);
    if(resposta==1){
        do{
        resposta=interfaceInserirSimples();
        if(resposta==0){
            void* dado=coletarDado();
            No* aux=criarNo(dado, compara_peso());
            inserirNoArvoreUnico(&Parv, aux, 0);
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
          printDado(tmp->dado);
        }
        else if(resposta == 2){
          int cod;
          printf("Digite o codigo que quer encontrar\n");
          scanf("%d", &cod);
          No*resp=encontrarPontoCod(Parv, cod);
          printDado(resp->dado);
        }else if(resposta==3){
            encerrarPrograma(&Parv);
            return EXIT_SUCCESS;
        }
        }while(1);
    }else if(resposta==1){
      test();
      return EXIT_SUCCESS;
  }
}