#include"test.h"
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
  inserirNoArvoreUnico(no, dado, 0);
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
}
void testDelete(No** no){
  encerrarPrograma(no);
}
void test(){
  No* no=NULL;
  testInclude(&no);
  testDelete(&no);
  return;
}