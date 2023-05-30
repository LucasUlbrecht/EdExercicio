#include "ex.h"
int interfaceInserirSimples() {
  int resposta;

  printf("\nBem vindo ao programa do exercicio (Pa8rte 1) de Estrutura de Dados,\n");
  printf("digite algum dos valores listados abaixo para continuar.\n");
  do {
    printf("0 - Inserir valor na arvore\n");
    printf("1 - Buscar ponto proximo da arvore\n");
    printf("2 - Buscar municipio por codigo\n");
    printf("3 - Encerrar Programa\n");
    scanf("%d", &resposta);
    if (resposta < 0 || resposta > 3) {
      printf("Escreva um digito valido, conforme os valores mostrados\n");
    }

  } while (resposta < 0 || resposta > 3);

  return resposta;
}
MunicBr* coletarDado(){
  int Cod;
            char NomeMuni[MAX_NOME_MUNICIPIO+1];
            int	CodUF;
            char SiglaUF[MAX_SIGLA_UF+1];
            char	Estado[MAX_NOME_ESTADO+1];
            char Capital[MAX_NOME_CAPITAL+1];
            float	Latitude;
            float Longitude;
            char Regiao[MAX_NOME_REGIAO+1];
            int CodSiafi;
            int DDD;
            char FusoHorario[MAX_NOME_MUNICIPIO+1];
            void* dado;
            printf("Informe seu dado\n");
            printf("Codigo:");
            scanf("%d",&Cod);
            printf("Nome Municipio:");
            scanf("\n%[^\n]", NomeMuni);
            printf("Codigo UF:");
            scanf("%d", &CodUF);
            printf("Sigla UF:");
            scanf("\n%[^\n]", SiglaUF);
            printf("Estado:");
            scanf("\n%[^\n]", Capital);
            printf("Longitude:");
            scanf("%f", &Longitude);
            printf("Latitude:");
            scanf("%f", &Latitude);
            printf("Região:");
            scanf("\n%[^\n]", Regiao);
            printf("Codigo Siafi:");
            scanf("%d", &CodSiafi);
            printf("DDD:");
            scanf("%d", &DDD);
            printf("Fuso Horario:");
            scanf("\n%[^\n]", FusoHorario);
            return criarDado(Cod, NomeMuni, CodUF, SiglaUF, Estado, Capital, Latitude, Longitude, Regiao, CodSiafi, DDD, FusoHorario);
            
}
MunicBr* criarDado(int Cod, char* NomeMuni, int	CodUF, char* SiglaUF, char*	Estado, char* Capital, float	Latitude, float Longitude, char* Região, int CodSiafi, int DDD, char* FusoHorario){
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
    strcpy(aux->FusoHorario, FusoHorario);
    return aux;
}
void printDado(void* auxB){
  MunicBr* aux=auxB;
                  printf("\n\nCodigo: %d\n Nome Municipio:%s\n SiglaUf: %s\n Estado: %s\n Capital: %s\n Longitude: %2.f\n Latitude: %.2f\n Região: %s\n CodSiafi: %d\n DDD: %d\n FusoHorario: %s\n\n"
                ,aux->Cod, aux->NomeMuni, aux->SiglaUF, aux->Estado, aux->Capital, aux->Longitude, aux->Latitude, aux->Regiao, aux->CodSiafi, aux->DDD, aux->FusoHorario);
}

No* buscarPonto(No* Parv, float px, float py, int ordem){
  if(Parv==NULL){
    return NULL;
  }
  else{
      MunicBr* aux=(MunicBr*)Parv->dado;
      if(px==aux->Longitude && py==aux->Latitude){
        printf("ponto encontrado\n");
          return Parv;
      }
      int grandeza=ordem%2;
      if(grandeza==0){
          if(px>aux->Longitude){
              if(Parv->dir==NULL){
                 return comparador(Parv, px, py, aux);
              }
              return buscarPonto(Parv->dir, px, py, ordem+1);
          }
            if(Parv->esq==NULL){
                 return comparador(Parv, px, py, aux);
              }
          else{
              return buscarPonto(Parv->esq, px, py, ordem+1);
          }
      }
      else{
          if(py>aux->Latitude){
             if(Parv->dir==NULL){
                 return comparador(Parv, px, py, aux);
              }
              return buscarPonto(Parv->dir, px, py, ordem+1);
          }
          else{
              if(Parv->esq==NULL){
                 return comparador(Parv, px, py, aux);
              }
              return buscarPonto(Parv->esq, px, py, ordem+1);
          }
      }
  }
}
No* comparador(No* Parv, int px, int py, MunicBr* aux){
              No* tmp=Parv;
              int menorHip=calcularDiferencaPontos(px, py, aux->Longitude, aux->Latitude);
              if(Parv->pai!=NULL){
                MunicBr*auxPai=Parv->pai->dado;
                if(calcularDiferencaPontos(px, py, auxPai->Longitude, auxPai->Latitude)>menorHip){}
                else{menorHip=calcularDiferencaPontos(px, py, auxPai->Longitude, auxPai->Latitude); No* tmp=Parv->pai;}
                if(Parv->pai->esq!=NULL){
                  MunicBr*auxEsqPai=Parv->pai->esq->dado;
                  if(calcularDiferencaPontos(px, py, auxEsqPai->Longitude, auxEsqPai->Latitude)>menorHip){}
                  else{menorHip=calcularDiferencaPontos(px, py, auxEsqPai->Longitude, auxEsqPai->Latitude); No* tmp=Parv->pai->esq;}
                }
                if(Parv->pai->dir!=NULL){
                  MunicBr*auxDirPai=Parv->pai->dir->dado;
                  if(calcularDiferencaPontos(px, py, auxDirPai->Longitude, auxDirPai->Latitude)>menorHip){}
                  else{menorHip=calcularDiferencaPontos(px, py, auxDirPai->Longitude, auxDirPai->Latitude); No* tmp=Parv->pai->dir;}
                }
              }
              if(Parv->esq!=NULL){
                MunicBr*auxEsq=Parv->esq->dado;
                if(calcularDiferencaPontos(px, py, auxEsq->Longitude, auxEsq->Latitude)>menorHip){}
                else{menorHip=calcularDiferencaPontos(px, py, auxEsq->Longitude, auxEsq->Latitude); No* tmp=Parv->esq;}
              }
              if(Parv->dir!=NULL){
                MunicBr*auxDir=Parv->dir->dado;
                if(calcularDiferencaPontos(px, py, auxDir->Longitude, auxDir->Latitude)>menorHip){}
                else{menorHip=calcularDiferencaPontos(px, py, auxDir->Longitude, auxDir->Latitude); No* tmp=Parv->dir;}
              }
              return tmp;
            
}
void encerrarPrograma(No** Parv){
  if(*Parv==NULL){
    return;
  }
  encerrarPrograma(&(*Parv)->esq);
  encerrarPrograma(&(*Parv)->dir);
  removerPonto(Parv);
  return;
}


No* encontrarPontoCod(No* Parv, int cod){
  No* auxReturn=NULL;
  if(Parv==NULL){
    return NULL;
  }
  MunicBr* aux= (MunicBr*) Parv->dado;
  if(aux->Cod==cod){
    return Parv;
  }
  auxReturn=encontrarPontoCod(Parv->esq, cod);
  if(auxReturn!=NULL){
    return auxReturn;
  }
  auxReturn=encontrarPontoCod(Parv->dir, cod);
  return auxReturn;
}
int compara_peso(const void *a, const void *b){
  No* auxA=a;
  No* auxB=b;
  MunicBr* auxa=auxA->dado;
  MunicBr* auxb=auxB->dado;
  int grandeza= auxA->h%2;
  if(grandeza==0){
    if(auxa->Longitude>=auxb->Longitude){
      return 0;
    }
    else{
      return 1;
    }
  }else{
    if(auxa->Latitude>=auxb->Latitude){
      return 0;
    }else{
      return 1;
    }

  }
}



