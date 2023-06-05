#include "ex.h"
#include "exABB.h"
#include <math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
int interfaceInserirSimples() {
  int resposta;

  printf("\nBem vindo ao programa do exercicio (Parte 1) de Estrutura de Dados,\n");
  printf("digite algum dos valores listados abaixo para continuar.\n");
  do {
    printf("0 - Carregar arquivo(.txt)\n");
    printf("1 - Buscar ponto proximo da arvore\n");
    printf("2 - Buscar elemento por codigo\n");
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
/*void printDado(void* auxB){
  MunicBr* aux=(MunicBr*)auxB;
                  printf("\n\nCodigo: %d\n Nome Municipio:%s\n SiglaUf: %s\n Estado: %s\n Capital: %s\n Longitude: %2.f\n Latitude: %.2f\n Região: %s\n CodSiafi: %d\n DDD: %d\n FusoHorario: %s\n\n"
                ,aux->Cod, aux->NomeMuni, aux->SiglaUF, aux->Estado, aux->Capital, aux->Longitude, aux->Latitude, aux->Regiao, aux->CodSiafi, aux->DDD, aux->FusoHorario);
}*/

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
float calcularDiferencaPontos(float px, float py, float px1, float py1){
    float diferencaX = px - px1;
    float diferencaY = py - py1;
    float hipotenusa = sqrt((diferencaX * diferencaX) + (diferencaY * diferencaY));
    return hipotenusa;
}
No* comparador(No* Parv, int px, int py, MunicBr* aux){
              No* tmp=Parv;
              float menorHip=calcularDiferencaPontos(px, py, aux->Longitude, aux->Latitude);
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
int compara(const void *a, const void *b, const int h){
  No* auxA=(No*)a;
  No* auxB=(No*)b;
  MunicBr* auxa=auxA->dado;
  MunicBr* auxb=auxB->dado;
  if(h==0){
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
void lerListaMunic(No** listaMunic){
  MunicBr aux;
  FILE* munic;
  MunicBr** dado;
  char lixo[TAM_LIXO];
  munic=fopen("../municipios.txt","r");
  if(munic==NULL){
    munic=fopen("/municipios.txt","r");
    if(munic==NULL){
      printf("erro abrir arquivo 'municipio.txt'\n");
      return;
    }
  }
  while(fscanf(munic, "%d, %[^,], %f, %f, %[^,], %d, %d, %d, %[^\n]\n", &aux.Cod, aux.NomeMuni, aux.Longitude, aux.Latitude, aux.Capital, aux.CodUF, aux.CodSiafi, aux.DDD, aux.FusoHorario)==1){
    (*dado)=(MunicBr*)calloc(1, sizeof(MunicBr));
    if(dado==NULL){
      printf("Erro ao gerar dado\n");
      return;
    }
    (*dado)->Cod=aux.Cod;
    strcpy((*dado)->Capital,aux.Capital);
    (*dado)->CodSiafi=aux.CodSiafi;
    (*dado)->CodUF=aux.CodUF;
    (*dado)->DDD=aux.DDD;
    strcpy((*dado)->FusoHorario,aux.FusoHorario);
    (*dado)->Latitude=aux.Latitude;
    (*dado)->Longitude=aux.Longitude;
    strcpy((*dado)->NomeMuni,aux.NomeMuni);
    printf("criando no");
    No** tmp = (No**)malloc(sizeof(No*));
    *tmp = criarNo((void**)&(*dado), compara);
    (*tmp)->printDado((*tmp)->dado);
    printf("inserindo");
    inserirNoArvoreUnico(listaMunic, (void**)tmp, 0);
  }

}
void procurarKproximos(No* Parv, int k){
  if(Parv==NULL){
    return;
  }
  
}
int comparaFast(const void* a, const void* b, int h){
  printf("comparando");
  No* no=(No*)a;
  No* no1=(No*)b;
  FastF* f=(FastF*)no->dado;
  FastF* f1=(FastF*)no1->dado;
  int grandeza=h%2;
  if(grandeza==0){
    //x
    if(f1->Longitude>f->Longitude){
      return 0;
    }else{
      return 1;
    }
  }else{
    //y
    if(f1->Latitude>f->Latitude){
      return 0;
    }else{
      return 1;
    }
  }
}
No* buscarFast(No* Parv, void* aux, int ordem){
  if(Parv==NULL){
    return NULL;
  }
  else{
      No* no=(No*)aux;
      FastF *tmp=no->dado;
      FastF *tmp1=Parv->dado;
      if(tmp1->Longitude==tmp->Longitude && tmp1->Latitude==tmp->Latitude){
        printf("ponto encontrado\n");
          return Parv;
      }
      int grandeza=ordem%2;
      if(grandeza==0){
          if(Parv->compara(Parv, aux, ordem)==0){
              if(Parv->dir==NULL){
                 //return comparador(Parv, px, py, aux);
              }
              return buscarFast(Parv->dir, aux, ordem+1);
          }
            if(Parv->esq==NULL){
                 //return comparador(Parv, px, py, aux);
              }
          else{
              return buscarFast(Parv->esq, aux, ordem+1);
          }
      }
      else{
          if(Parv->compara(Parv, aux, ordem)==1){
             if(Parv->dir==NULL){
                 //return comparador(Parv, px, py, aux);
              }
              return buscarFast(Parv->dir, aux, ordem+1);
          }
          else{
              if(Parv->esq==NULL){
                 //return comparador(Parv, px, py, aux);
              }
              return buscarFast(Parv->esq, aux, ordem+1);
          }
      }
  }
}
void lerListaFast(No** Parv) {
  No* p=NULL;
    FILE* arq = fopen("../fastFood.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    int x = 0;
    while (1) {
      *Parv=p;
        FastF* FastFood = (FastF*) malloc(sizeof(FastF));
        if (fscanf(arq, "%d,%[^,],%[^,],%[^,],%f,%f,%[^,],%d,%[^,],%[^\n]\n)",
                   &FastFood->cod, FastFood->address, FastFood->city, FastFood->country,
                   &FastFood->Latitude, &FastFood->Longitude, FastFood->nome,
                   &FastFood->postalCode, FastFood->province, FastFood->website) == EOF) {
            free(FastFood);
            break;
        }

        No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o nó\n");
        return NULL;
    }
    void* aux=(void*)FastFood;
    novoNo->dado = aux;
    novoNo->pai = NULL;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->compara = compara;
    novoNo->printDado = NULL;
        printf("dado gerado\n");
        printf("inserindo no\n");
        inserirNoArvoreUnico(&p, novoNo, 0);
        printf("termo %d gerado\n", x);
      print(p);
        x++;
    }

    fclose(arq);
}

void print(void* no){
  No* nu=no;
  FastF* dado=nu->dado;
  printf("\n-----------------------------------\n");
  printf("nome:%s\n",dado->nome);
  printf("%f\n",dado->Latitude);
  printf("%f\n",dado->Longitude);
  printf("-----------------------------------\n");
}
double distancia(float p1[], float p2[]) {
    double dx = p1[0] - p2[0];
    double dy = p1[1] - p2[1];
    return sqrt(dx * dx + dy * dy);
}

int comparePoints(float p1[], float p2[], int dim) {
    if (p1[dim] < p2[dim])
        return -1;
    else if (p1[dim] > p2[dim])
        return 1;
    else
        return 0;
}

void acharKVisinhosProx(No* Parv, float p[], int k, No* vizinhos, int ordem) {
  FastF* tmpf;
  tmpf->Latitude=p[1];
  tmpf->Longitude=p[0];
  if (Parv == NULL) {
      return;
  }
  FastF*aux=Parv->dado;
  if(aux->Latitude==tmpf->Latitude && aux->Longitude==tmpf->Longitude){
          int tam=k;
          encontraKSucessores(Parv, &k, vizinhos);
          encontraPredecessor(Parv, &k,p, tam, tam, vizinhos);
          return;
  }
  int grandezaAtual = ordem % 2;
  if (Parv->compara(Parv->dado, tmpf, grandezaAtual) == 1) {
    printf("comparação feita");
      if (Parv->dir == NULL) {
        int tam=k;
          encontraKSucessores(Parv, &k, vizinhos);
          encontraPredecessor(Parv, &k, p, tam, tam, vizinhos);
          return;
      } else {
          acharKVisinhosProx(Parv->dir, p,k,vizinhos, ordem + 1);
      }
  } else {
    printf("comparação feita");
      if (Parv->esq == NULL) {
        int tam=k;
        encontraKSucessores(Parv, &k, vizinhos);
        encontraPredecessor(Parv, &k,p, tam, tam, vizinhos);  
      return;
      } else {
          acharKVisinhosProx(Parv->esq, p,k,vizinhos, ordem + 1);
      }
  }
}
void encontraKSucessores(No* Parv,int* k, No* lista){
  if(Parv==NULL || k==0)
    return;
  if(Parv->dir!=NULL){
    No* p=Parv->dir;
    while(p->esq!=NULL){
      p=p->esq;
    }
    lista[(*k)-1]=*p;
    encontraKSucessores(Parv,k-1, lista);
  }else{
    No*p=Parv->pai;
    No*ant=Parv;
    while(p->pai!=NULL && p->dir==ant){
      p=p->pai;
      ant=ant->pai;
    }
    lista[*k-1]=*p;
    encontraKSucessores(Parv,k-1, lista);
  }
}
void encontraPredecessor(No* Parv, int* tamSbr,float p[], int tamAnt, int k, No* lista){
if(Parv==NULL || k==0)
    return;
  if(Parv->esq!=NULL){
    No* no=Parv->esq;
    while(no->dir!=NULL){
      no=no->dir;
    }
    compararListaNo(lista, tamAnt, no, p);
    encontraPredecessor(no, tamSbr, p, tamAnt, k-1, lista);
  }else{
    No*no=Parv->pai;
    No*ant=Parv;
    while(no->pai!=NULL && no->esq==ant){
      no=no->pai;
      ant=ant->pai;
    }
    compararListaNo(lista, tamAnt, no, p);
    encontraPredecessor(no, tamSbr, p, tamAnt, k-1, lista);
  }
}

void compararListaNo(No* lista, int tamanho, No* no, float* p) {
    float distanciaLista, distanciaNo;
    int i, indiceMaiorDistancia = 0;
  FastF* dadoLista = (FastF*)lista[0].dado;
    float maiorDistancia = calcularDiferencaPontos(p[0], p[1], dadoLista->Latitude, dadoLista->Longitude);

    for (i = 0; i < tamanho; i++) {
        dadoLista = (FastF*)lista[i].dado;
        distanciaLista = calcularDiferencaPontos(p[0], p[1], dadoLista->Latitude, dadoLista->Longitude);
        if (distanciaLista > maiorDistancia) {
            maiorDistancia = distanciaLista;
            indiceMaiorDistancia = i;
        }
    }

    FastF* dadoNo = (FastF*)no->dado;
    distanciaNo = calcularDiferencaPontos(p[0], p[1], dadoNo->Latitude, dadoNo->Longitude);

    if (distanciaNo < maiorDistancia) {
        trocarNos(&lista[indiceMaiorDistancia], no);
    }
}

void trocarNos(No* no1, No* no2) {
    No temp = *no1;
    *no1 = *no2;
    *no2 = temp;
}