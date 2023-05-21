#include"ex.h"
#include"test.h"
int main (void){
    No* Parv=NULL;
    int resposta;
    do{
    printf("Bem vindo ao programa exEd, se deseja realizar funcionalidades de kd tree Digite - 0, se deseja ler/gerar lista Digite - 1, se deseja realizar rápido checkup das funções basicas Digite - 2\n");
    scanf("%d", &resposta);
    }while(resposta<0 || resposta>3);
    if(resposta==0){
        do{
        resposta=interfaceInserirSimples();
        if(resposta==0){
            void* dado=coletarDado();
            inserirNoArvoreUnico(&Parv, dado, 0);
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
    }
    else if(resposta==1){
      do{
        resposta = interfaceInserirLista();
    
        if (resposta == 0) { //: 0 - Receber uma lista com os estados
          MunicBr* MunicBr;
          printf("%p", MunicBr);
          
          MunicBr=GerarListaMunicBr(); // Passar o endereço de listaMunicBr
          
          printf("sai");
          int tam = 5570;
    
          //inserirNoArvore(Ttree, (lMunicBr)->dado, 0, tam - 1, tipoOp); // Passar listaMunicBr
        } else if (resposta == 1) { //: 1 - encontrarPonto
          int px, py;
          scanf("%d %d", &px, &py);
          encontrarPonto(Parv, px, py, 0);
        } else if(resposta==2) { // resposta==2: 2 - encontrarPontoFora
          int px, py;
          int mpx;
          int mpy;
          scanf("%d %d", &px, &py);
          encontrarPontoFora(Parv, px, py, 0, &mpx, &mpy); // Passar &mpx, &mpy
          encontrarPonto(Parv, mpx, mpy, 0);
        }
        else { // resposta 3: encerrar programa
        encerrarPrograma(&Parv);
        return EXIT_SUCCESS;
        }
    }while(1);
  }else if(resposta==2){
      test();
      return EXIT_SUCCESS;
  }
}