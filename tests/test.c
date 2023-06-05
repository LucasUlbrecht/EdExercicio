#include"../src/ex.h"
#include"../src/exABB.h"
#include<assert.h>
#define LIST_SIZE 9
void testInclude(No** no){
  float listaLatitude[9]={0,2,1,3,9,7,10,7,11};
  float listaLongitude[9]={5,3,2,1,6,6,10,8,11};
  char* listanomes[9]={"São Paulo","Rio de Janeiro","Salvador","Belo Horizonte","Fortaleza","Manaus","Curitiba","Recife","Porto Alegre"};
  char* listaSiglas[9]={"SP","RJ","BA","MG","CE","AM","PR","PE","RS"};
  char* listaRegiao[9]={"Sudeste","Sudeste","Nordeste","Sudeste","Nordeste","Norte","Sul","Nordeste","Sul"};
  int listaCodSiafi[9]={1004,1008,1051,1016,1110,1001,1043,1099};
  int listaDDD[9]={11,21,71,31,85,92,41,81,51};
  char* listaFusohorario[9]={"UTF-3","UTF-3","UTF-3","UTF-3","UTF-3","UTF-4","UTF-3","UTF-3","UTF-3"};
  /*
  , SP, , 1004, 11, UTC-3
  , RJ, , 1008, 21, UTC-3
  , BA, , 1051, 71, UTC-3
  , MG, , 1016, 31, UTC-3
  , CE, Nordeste, 1052, 85, UTC-3
  , AM, , 1110, 92, UTC-4
  , PR, , 1001, 41, UTC-3
  , PE, Nordeste, 1043, 81, UTC-3
  , RS, Sul, 1099, 51, UTC-3
  */
for(int cont=0;cont<9;cont++){
  void* dado=criarDado(cont, listanomes[cont], cont, listaSiglas[cont], "0", "0",	listaLatitude[cont], listaLongitude[cont], listaRegiao[cont], listaCodSiafi[cont], listaDDD[cont], listaFusohorario[cont]);
  No* novoNo=criarNo((&(dado)),compara);
  inserirNoArvoreUnico(no, &(*novoNo), 0);
}
printf("inseridos");

  No* aux=*no;
  MunicBr* checkDado=aux->dado;
  assert(checkDado->Latitude==0);
  assert(checkDado->Longitude==5);
  aux=aux->esq;
  checkDado=aux->dado;
  assert(checkDado->Latitude==2);
  assert(checkDado->Longitude==3);
  aux=aux->esq;
  checkDado=aux->dado;
  assert(checkDado->Latitude==1);
  assert(checkDado->Longitude==2);
  aux=aux->pai;
  aux=aux->dir;
  checkDado=aux->dado;
  assert(checkDado->Latitude==3);
  assert(checkDado->Longitude==1);
  aux=aux->pai;
  aux=aux->pai;
  aux=aux->dir;
  checkDado=aux->dado;
  assert(checkDado->Latitude==9);
  assert(checkDado->Longitude==6);
  aux=aux->esq;
  checkDado=aux->dado;
  assert(checkDado->Latitude==7);
  assert(checkDado->Longitude==6);
  aux=aux->dir;
  checkDado=aux->dado;
  assert(checkDado->Latitude==7);
  assert(checkDado->Longitude==8);
  aux=aux->pai;
  aux=aux->pai;
  aux=aux->dir;
  checkDado=aux->dado;
  assert(checkDado->Latitude==10);
  assert(checkDado->Longitude==10);
  aux=aux->dir;
  checkDado=aux->dado;
  assert(checkDado->Latitude==11);
  assert(checkDado->Longitude==11);
  encerrarPrograma(no);
  int cod[LIST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char address[LIST_SIZE][MAX_TAMADRRESS+1] = {
        "Address1",
        "Address2",
        "Address3",
        "Address4",
        "Address5",
        "Address6",
        "Address7",
        "Address8",
        "Address9"
    };
    char city[LIST_SIZE][MAX_TAMCITY+1] = {
        "City1",
        "City2",
        "City3",
        "City4",
        "City5",
        "City6",
        "City7",
        "City8",
        "City9"
    };
    char country[LIST_SIZE][MAX_TAMCOUNTRY+1] = {
        "Country1",
        "Country2",
        "Country3",
        "Country4",
        "Country5",
        "Country6",
        "Country7",
        "Country8",
        "Country9"
    };
    float Latitude[LIST_SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    float Longitude[LIST_SIZE] = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0};
    char nome[LIST_SIZE][MAX_NOME_MUNICIPIO+1] = {
        "Nome1",
        "Nome2",
        "Nome3",
        "Nome4",
        "Nome5",
        "Nome6",
        "Nome7",
        "Nome8",
        "Nome9"
    };
    int postalCode[LIST_SIZE] = {11111, 22222, 33333, 44444, 55555, 66666, 77777, 88888, 99999};
    char province[LIST_SIZE][MAX_TAMCOUNTRY+1] = {
        "Province1",
        "Province2",
        "Province3",
        "Province4",
        "Province5",
        "Province6",
        "Province7",
        "Province8",
        "Province9"
    };
    char website[LIST_SIZE][MAX_TAMWEB+1] = {
        "Website1",
        "Website2",
        "Website3",
        "Website4",
        "Website5",
        "Website6",
        "Website7",
        "Website8",
        "Website9"
    };
    No* novoNo;
    FastF* listaFast=(FastF*)calloc(9,sizeof(FastF));
    for(int i=0;i<9;i++){
      listaFast[i].cod = cod[i];
      strcpy(listaFast[i].address, address[i]);
      strcpy(listaFast[i].city, city[i]);
      strcpy(listaFast[i].country, country[i]);
      listaFast[i].Latitude = Latitude[i];
      listaFast[i].Longitude = Longitude[i];
      strcpy(listaFast[i].nome, nome[i]);
      listaFast[i].postalCode = postalCode[i];
      strcpy(listaFast[i].province, province[i]);
      strcpy(listaFast[i].website, website[i]);
      novoNo=criarNo((void**)&listaFast[i],comparaFast);
      inserirNoArvoreUnico(no,novoNo,0);
      int k=4;
      float p[2];
      p[0]=5;
      p[1]=10;
      No resp[k];
      acharKVisinhosProx(no,p,k,resp,0);
    };
}
void main(){
  No* no=NULL;
  testInclude(&no);
  return;
}