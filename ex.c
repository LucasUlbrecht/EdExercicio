#include "ex.h"

int interface() {
  int resposta;

  printf("\nBem vindo ao programa do exercicio (Parte 1) de Estrutura de "
         "Dados,\n");
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
MunicBr *criarDado(int Cod, char *NomeMuni, int CodUF, char *SiglaUF,
                   char *Estado, char *Capital, int Latitude, int Longitude,
                   char *Região, int CodSiafi, int DDD, int FusoHorario) {
  MunicBr *aux = (MunicBr *)calloc(1, sizeof(MunicBr));
  aux->Cod = Cod;
  strcpy(aux->NomeMuni, NomeMuni);
  aux->CodUF = CodUF;
  strcpy(aux->SiglaUF, SiglaUF);
  strcpy(aux->Estado, Estado);
  strcpy(aux->Capital, Capital);
  aux->Latitude = Latitude;
  aux->Longitude = Longitude;
  strcpy(aux->Regiao, Região);
  aux->CodSiafi = CodSiafi;
  aux->DDD = DDD;
  aux->FusoHorario = FusoHorario;
  return aux;
}
void GerarListaMunicBr(MunicBr **listaMunicBr) {
  int index;
  char lixo[TAM_LIXO];
  FILE *ListaArquivoEst;
  RegBr *lReg;
  FILE *ListatamArquivoMunic;
  FILE *ListaArquivMunic;
  int tamArquivMunic = 0;
  char caractere;
  ListaArquivoEst = fopen("estados.txt", "r");
  if (ListaArquivoEst != NULL) {
    lReg = (RegBr *)calloc(NUM_ESTADOS, sizeof(RegBr));
    for (int cont = 0; cont < NUM_ESTADOS && feof(ListaArquivoEst) == 0;
         cont++) {
      fscanf(ListaArquivoEst, "%d ", &lReg[cont].CodUF);
      fscanf(ListaArquivoEst, "%[^/,]", lReg[cont].SiglaUF);
      fscanf(ListaArquivoEst, "%[^/,]", lReg[cont].Regiao);
      fscanf(ListaArquivoEst, "%s", lixo);
    }
  }
  // Abrir o arquivo em modo de leitura
  ListatamArquivoMunic = fopen("municipios.txt", "r");

  // Verificar se o arquivo foi aberto corretamente
  if (ListatamArquivoMunic == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  // Contar as linhas do arquivo
  while ((caractere = fgetc(ListatamArquivoMunic)) != EOF) {
    if (caractere == '\n') {
      tamArquivMunic++;
    }
  }
  // Fechar o arquivo
  fclose(ListatamArquivoMunic);
  ListaArquivMunic = fopen("municipios.txt", "r");
  if (ListaArquivMunic == NULL) {
    return;
  }
  (*listaMunicBr) = (MunicBr *)calloc(tamArquivMunic, sizeof(MunicBr));
  for (int cont = 0, cod = 0;
       cont < tamArquivMunic && feof(ListaArquivMunic) == 0; cont++) {
    fscanf(ListaArquivMunic, "%d", &(*listaMunicBr)->Cod);
    // nome,latitude,longitude,capital,codigo_uf,siafi_id,ddd,fuso_horario
    fscanf(ListaArquivMunic, "%[^/,] %d %d %[^/,] %d %d %d %d",
           (*listaMunicBr[cont]).NomeMuni, &(*listaMunicBr[cont]).Latitude,
           &(*listaMunicBr[cont]).Longitude, (*listaMunicBr[cont]).Capital,
           &(*listaMunicBr[cont]).CodUF, &(*listaMunicBr[cont]).CodSiafi,
           &(*listaMunicBr[cont]).DDD, &(*listaMunicBr[cont]).FusoHorario);
    index =
        buscaBinariaElemento((*listaMunicBr[cont]).CodUF, 0, NUM_ESTADOS, lReg);
    strcpy((*listaMunicBr[cont]).SiglaUF, lReg[index].SiglaUF);
    strcpy((*listaMunicBr[cont]).Regiao, lReg[index].Regiao);
  };
  fclose(ListaArquivMunic);
  free(lReg);
  return;
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

  return -1;
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
        i++; // incrementa o índice do menor elemento
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
  NovoNo->dado = (MunicBr*) dado;
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
void inserirNoArvore(No **Parv, void *arr,int init, int tam, char* tipoOp) {
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
    inserirNoArvore(Parv, arr, init, indexCentro, tipoOp);
    inserirNoArvore(Parv, arr, indexCentro+1, tam, tipoOp);
  }
}
