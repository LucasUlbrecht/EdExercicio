#include "ex.h"

int main(void) {
  char *tipoOp;
  int resposta;
  No *Ttree = NULL;
  void *listaMunicBr;
  printf("Escolha entre teste (tecle '1' para teste) ou interface (tecle '2' "
         "para interface):");
  scanf("%d", &resposta);
  if (resposta == 1) {
    resposta = interface();
    if (resposta == 0) { //: 0 - Receber uma lista com os estados
      GerarListaMunicBr(listaMunicBr);
      int tam = 0;
      while (listaMunicBr != NULL) {
        tam++;
      }
      inserirNoArvore(&Ttree, listaMunicBr, 0, tam-1, tipoOp);
    } else if (resposta == 1) { //: 1 - Print in ordem arvore
    } else {                    // resposta==2: 2 - Encerrar Programa
    }
  } else {
  }
}