#include"ex.h"
int interface() {
  int resposta;

  printf("\nBem vindo ao programa do exercicio (Parte 1) de Estrutura de Dados,\n");
  printf("digite algum dos valores listados abaixo para continuar.\n");
  do {
    printf("0 - Receber uma lista com os estados\n");
    printf("1 - Print in ordem arvore\n");
    printf("2 - Encerrar Programa\n");
    scanf("%d", &resposta);
    if (resposta < 0 || resposta > 3) {
      printf("Escreva um digito valido, conforme os valores mostrados\n");
    }

  } while (resposta < 0 || resposta > 3);

  return resposta;
}
MunicBr* criarDado(int Cod, char* NomeMuni, int	CodUF, char* SiglaUF, char*	Estado, char* Capital, int	Latitude, int Longitude, char* Região, int CodSiafi, int DDD, int FusoHorario){
    MunicBr* aux=(MunicBr*)calloc(1,sizeof(MunicBr));
    aux->Cod=Cod;
    strcpy(aux->NomeMuni, NomeMuni);
    aux->CodUF=CodUF;
    strcpy(aux->SiglaUF, SiglaUF);
    strcpy(aux->Estado, Estado);
    strcpy(aux->Capital, Capital);
    aux->Latitude=Latitude;
    aux->Longitude=Longitude;
    strcpy(aux->Regiao, Região);
    aux->CodSiafi=CodSiafi;
    aux->DDD=DDD;
    aux->FusoHorario=FusoHorario;
    return aux;
}
no* criarNo(void* dado){
    no* NovoNo=(no*)calloc(1,sizeof(no));
    NovoNo->dado=dado;
    return NovoNo;
}
void inserirNoArvore(no** Parv, void* dado, int ordem){
    if(Parv==NULL){
        no* aux=criarNo(dado);
        *Parv=aux;
    }
    int grandezaAtual=ordem%2;
    if(grandezaAtual==0){
        if(dado->Longitude > Parv->dado->Longitude){
            inserirNoArvore(&(Parv->dir), dado, ordem+1);
        }
        else{
            inserirNoArvore(&(Parv->esq), dado, ordem+1);
        }
    }//grandeza x
    else{
        if(dado->Latitude > Parv->dado->Latitude){
            inserirNoArvore(&(Parv->dir), dado, ordem+1);
        }
        else{
            inserirNoArvore(&(Parv->esq), dado, ordem+1);
        }
    }//grandeza y
    regularGrandeza();
}
int calcularDistancia(int p1x, int p1y, int p2x, int p2y){
    
}