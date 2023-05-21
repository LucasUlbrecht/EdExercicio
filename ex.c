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
void inserirNoArvoreUnico(No** Parv, void* dado, int ordem){
    if(*Parv==NULL){
        No* aux=criarNo(dado);
        *Parv=aux;
        return;
    }
    int grandezaAtual=ordem%2;
    MunicBr* aux=(MunicBr*)(*Parv)->dado;
    MunicBr* auxDado=(MunicBr*)dado;
    if(grandezaAtual==0){
        if(auxDado->Longitude > aux->Longitude){
            if((*Parv)->dir==NULL){
                No* aux=criarNo(dado);
                aux->pai=*Parv;
                (*Parv)->dir=aux;
                return;
            }
            else{
                inserirNoArvoreUnico(&((*Parv)->dir), dado, ordem+1);
            }
        }
        else{
            if((*Parv)->esq==NULL){
                No* aux=criarNo(dado);
                aux->pai=*Parv;
                (*Parv)->esq=aux;
                return;
            }
            else{
                inserirNoArvoreUnico(&((*Parv)->esq), dado, ordem+1);
            }
        }
    }//grandeza x
    else{
        if(auxDado->Latitude > aux->Latitude){
            if((*Parv)->dir==NULL){
                No* aux=criarNo(dado);
                aux->pai=(*Parv);
                (*Parv)->dir=aux;
                return;
            }
            else{
                inserirNoArvoreUnico(&((*Parv)->dir), dado, ordem+1);
            }
        }
        else{
            if((*Parv)->esq==NULL){
                No* aux=criarNo(dado);
                aux->pai=(*Parv);
                (*Parv)->esq=aux;
                return;
            }
            inserirNoArvoreUnico(&((*Parv)->esq), dado, ordem+1);
        }
    }//grandeza y
    return;
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
  removerPonto(*Parv);
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




















//Funções antigas KDTree balanceada;
int interfaceInserirLista() {
  int resposta;

  printf("\nBem vindo ao programa do exercicio (Parte 1) de Estrutura de Dados,\n");
  printf("digite algum dos valores listados abaixo para continuar.\n");
  do {
    printf("0 - Carregar lista de municipios/estados\n");
    printf("1 - Buscar ponto na arvore\n");
    printf("2 - Buscar ponto proximo na arvore\n");
    printf("3 - Encerrar Programa\n");
    scanf("%d", &resposta);
    if (resposta < 0 || resposta > 3) {
      printf("Escreva um digito valido, conforme os valores mostrados\n");
    }

  } while (resposta < 0 || resposta > 3);

  return resposta;
}
void* GerarListaMunicBr() {
  FILE* municipios;
  FILE* municipiosTam;
  FILE* estados;
  void* listaReg;
  void* listaMun;
  char lixo[TAM_LIXO];
  int cont=0;
  int tamMuni=0;
  
  listaReg=(RegBr*)calloc(NUM_ESTADOS, sizeof(RegBr));
  RegBr* lReg=listaReg;
  estados=fopen("estados.txt","r");
  if(estados==NULL || listaReg==NULL){
    printf("Não foi possível abrir arquivo estados\n");
    return NULL;
  }
  for(cont=0;fscanf(estados,"%d,%[^,],%[^,],%[^,],%[^,],%[^,]\n",&lReg[cont].CodUF, lReg[cont].SiglaUF,lixo,lixo,lixo,lReg[cont].Regiao)==1;cont++){};
  fclose(estados);
  municipiosTam=fopen("municipios.txt","r");
  if(municipiosTam==NULL){
    printf("Não foi possível abrir arquivo tamanho municipios\n");
    return NULL;
  }
  for(cont=0;fscanf(municipiosTam, "%[^\n]\n",lixo)==1;cont++){tamMuni++;};
  fclose(municipiosTam);
  municipios=fopen("municipios.txt","r");
  if(municipios==NULL){
    printf("Não foi possível abrir arquivo municipios\n");
    return NULL;
  }
  listaMun=(MunicBr*)calloc(tamMuni,sizeof(MunicBr));
  if(listaMun==NULL){
    printf("Não foi possível criar lista municipios\n");
    return NULL;
  }
  MunicBr* lMun;
  lMun=listaMun;
  //5200050,Abadia de Goiás,-16.7573,-49.4412,0,52,1050,62,America/Sao_Paulo
  for(int index=0, cont=0;fscanf(municipios,"%d,%[^,],%f,%f,%[^,],%d,%d,%d,%[^,\n]\n",&lMun[cont].Cod,lMun[cont].NomeMuni,&lMun[cont].Longitude,&lMun[cont].Latitude,lMun[cont].Capital, &lMun[cont].CodUF, &lMun[cont].CodSiafi,&lMun[cont].DDD,lMun[cont].FusoHorario)==1 && cont<tamMuni;cont++){
    index = buscaBinariaElemento(lMun[cont].CodUF, 0, NUM_ESTADOS, lReg);
    strcpy(lMun[cont].Regiao,lReg[index].Regiao);
    strcpy(lMun[cont].SiglaUF, lReg[index].Regiao);
  };
  
  return listaMun;
  
}
int buscaBinariaElemento(int valor, int init, int fim, RegBr *lReg) {
  int meio;
  while (init <= fim) {
    meio = (init + fim) / 2;
    if (lReg[meio].CodUF == valor) {
      return meio;
    }
    if (lReg[meio].CodUF < valor) {
      init = meio + 1;
    } else {
      fim = meio - 1;
    }
  }
}
void mudarTipoOp(char* tipoOp){
  if(*tipoOp=='x'){
    *tipoOp='y';
  }
  else{
    *tipoOp='x';
  }
  return;
}
void swapMunicBr(MunicBr *munic1, MunicBr *munic2) {
    MunicBr temp;

    temp = *munic1;
    *munic1 = *munic2;
    *munic2 = temp;
}
int partition(MunicBr** arr, int low, int high, char tipoOp) {
  if(tipoOp == 'x'){
    int pivot = arr[high]->Longitude; // escolhe o último elemento como pivô
    int i = (low - 1);     // índice do menor elemento
  
    for (int j = low; j <= high - 1; j++) {
      // Se o elemento atual é menor ou igual ao pivô
      if (arr[j]->Longitude <= pivot) {
        i++; 
        swapMunicBr(arr[i], arr[j]);
      }
    }
    swapMunicBr(arr[i + 1], arr[high]);
    return (i + 1);
  }
  else if(tipoOp == 'y'){
    int pivot = arr[high]->Latitude; // escolhe o último elemento como pivô
    int i = (low - 1);     // índice do menor elemento
  
    for (int j = low; j <= high - 1; j++) {
      // Se o elemento atual é menor ou igual ao pivô
      if (arr[j]->Longitude <= pivot) {
        i++; // incrementa o índice do menor elemento
        swapMunicBr(arr[i], arr[j]);
      }
    }
    swapMunicBr(arr[i + 1], arr[high]);
    return (i + 1);
  }
}
void quickSort(MunicBr** arr, int low, int high, char tipoOp) {
  if (low < high) {
    // Encontra o pivô, coloca-o no lugar correto e divide o array em duas
    // partes
    int pi = partition(arr, low, high, tipoOp);

    // Ordena separadamente os elementos antes e depois do pivô
    quickSort(arr, low, pi - 1, tipoOp);
    quickSort(arr, pi + 1, high, tipoOp);
  }
}



No* criarNo(void *dado) {
  No *NovoNo = (No *)calloc(1, sizeof(No));
  NovoNo->dado = dado;
  return NovoNo;
}
int encontrarLongitudeCentro(MunicBr munic[], int tamanho){
    if (tamanho == 0) {
        // Lista vazia, retornar algum valor padrão
        return 0;
    }
    int index = tamanho / 2;
    return munic[index].Longitude;
}
void inserirNoArvoreBalanceada(No **Parv, void *arr,int init, int tam, char* tipoOp) {
  if(init<tam){
    mudarTipoOp(tipoOp);
    MunicBr* lista = (MunicBr*)arr;
    quickSort(arr, init, tam, *tipoOp);
    int indexCentro=encontrarLongitudeCentro(arr, tam);
    if(Parv==NULL){
      *Parv=criarNo(&arr[indexCentro]);
    }
    else{
      MunicBr* tmpNoAtual=(MunicBr*)(*Parv)->dado;
      No* aux=criarNo(&arr[indexCentro]);
      MunicBr* tmpNoNovo=(MunicBr*)(*Parv)->dado;
      if(*tipoOp=='x'){
        if(tmpNoAtual->Longitude>=tmpNoNovo->Longitude){
          (*Parv)->esq=aux;
          aux->pai=*Parv;
        }
        else{
          (*Parv)->dir=aux;
          aux->pai=*Parv;
        }
      }
      else if(*tipoOp=='y'){
        if(tmpNoAtual->Latitude>=tmpNoNovo->Latitude){
          (*Parv)->esq=aux;
          aux->pai=*Parv;
        }
        else{
          (*Parv)->dir=aux;
          aux->pai=*Parv;
        }
      }
    }
    inserirNoArvoreBalanceada(Parv, arr, init, indexCentro, tipoOp);
    inserirNoArvoreBalanceada(Parv, arr, indexCentro+1, tam, tipoOp);
  }
}
void encontrarPonto(No* Parv, int px, int py, int grau){
  if(Parv==NULL){
    return;
  }
  MunicBr* aux=(MunicBr*) Parv->dado;
  if(aux->Longitude==px && aux->Latitude==py){
    printf("Código IBGE:%d,	Nome do Município:%s,	Código UF:%d,	UF	Estado:%s,	Capital%s,	Latitude:%d,	Longitude:%d,	Região:%s,	Código Siafi:%d,	DDD:%d,	Fuso Horário:%s", aux->Cod,aux->NomeMuni,aux->CodUF,aux->SiglaUF, aux->Capital, aux->Latitude, aux->Longitude, aux->Regiao, aux->CodSiafi, aux->DDD, aux->FusoHorario);
  }
  int Ordem=grau%2;
  if(Ordem==0){
    if(aux->Longitude>px){
      encontrarPonto(Parv->esq, px, py, grau+1);
    }
    else{
      encontrarPonto(Parv->dir, px, py, grau+1);
    }
  }
  else{
    if(aux->Latitude>py){
      encontrarPonto(Parv->esq, px, py, grau+1);
    }
    else{
      encontrarPonto(Parv->dir, px, py, grau+1);
    }
  }
}
int encontrarPontoFora(No* Parv, int px, int py, int grau, int* menorPx, int* menorPy){
  if(Parv==NULL){
    return 4328000;
  }
  int diferencaMenorEsq=encontrarPontoFora(Parv->esq, px, py, grau+1, NULL, NULL);
  int diferencaMenorDir=encontrarPontoFora(Parv->dir, px, py, grau+1, NULL, NULL);
  MunicBr* aux= (MunicBr*) Parv->dado;
  int diferencaAtual=calcularDiferencaPontos(aux->Longitude, aux->Latitude, px, py);
  if(diferencaMenorDir<=diferencaMenorEsq){
    if(diferencaMenorDir<=diferencaAtual){
      return diferencaMenorDir;
    }
    py=aux->Latitude;
    px=aux->Longitude;
    return diferencaAtual;
  }
  else{
    if(diferencaMenorEsq<=diferencaAtual){
      return diferencaMenorEsq;
    }
    py=aux->Latitude;
    px=aux->Longitude;
    return diferencaAtual;
  }
}
int calcularDiferencaPontos(int p1x, int p1y, int p2x, int p2y){
  float auxP1x=(double)p1x;
  float auxP2x=(double)p2x;
  float auxP1y=(double)p1y;
  float auxP2y=(double)p2y;
  double CA=fabs(auxP1x-auxP2x);
  double CO=fabs(auxP1y-auxP2y);
  double hipotenusa=sqrt((CA*CA)+(CO*CO));
  return (int)hipotenusa;
}