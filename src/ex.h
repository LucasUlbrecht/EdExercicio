#ifndef _EX_
#define _EX_
#include"exABB.h"
#define TAM_LIXO 70
#define MAX_NOME_MUNICIPIO 29
#define MAX_SIGLA_UF 2
#define MAX_NOME_ESTADO 17
#define MAX_NOME_CAPITAL 8
#define MAX_NOME_REGIAO 9
#define MAX_TAM_FUSO 30
#define NUM_ESTADOS 30
#define MAX_TAMADRRESS 50
#define MAX_TAMCITY 30
#define MAX_TAMCOUNTRY 2
#define MAX_TAMWEB 100


typedef struct FastFood
{
    int cod;
    char address[MAX_TAMADRRESS+1];
    char city[MAX_TAMCITY+1];
    char country[MAX_TAMCOUNTRY+1];
    float Latitude;
    float Longitude;
    char nome[MAX_NOME_MUNICIPIO+1];
    int postalCode;
    char province[MAX_TAMCOUNTRY+1];
    char website[MAX_TAMWEB+1];
}FastF;

typedef struct MunicipiosBrasileiros
{
    int Cod;
    char NomeMuni[MAX_NOME_MUNICIPIO+1];
    char Estado[MAX_NOME_ESTADO+1];
    char Capital[MAX_NOME_CAPITAL+1];
    float	Latitude;
    float Longitude;
    int CodSiafi;
    int	DDD;
    char FusoHorario[MAX_TAM_FUSO+1];
    int	CodUF;
    char SiglaUF[MAX_SIGLA_UF+1];
    char Regiao[MAX_NOME_REGIAO+1];
}MunicBr;

typedef struct ListaMunicBr{
  MunicBr** dado;
  int tamanho;
}lMunicBr;

//Interface
  int interfaceInserirLista();
  int interfaceInserirSimples();

//Manipulação Listas
  void acharKVisinhosProx(No* Parv, float p[], int k, No* vizinhos, int ordem);
  void lerListaMunic(No** listaMunic);
  void lerListaFast(No** Parv);
//  Busca Ponto
    No* buscarPonto(No* Parv, float px, float py, int ordem);
    No* encontrarPontoCod(No* Parv, int cod);
    No* comparador(No* Parv, int px, int py, MunicBr* aux);
//Operações com dados MunicBr
  MunicBr* criarDado(int Cod, char* NomeMuni, int	CodUF, char* SiglaUF, char*	Estado, char* Capital, float	Latitude, float Longitude, char* Região, int CodSiafi, int DDD, char* FusoHorario);
  MunicBr* coletarDado();
  No* buscarFast(No* Parv, void* aux, int ordem);
  int compara(const void *a, const void *b, const int h);
  float calcularDiferencaPontos(float px, float py, float px1, float py1);
  int comparaFast(const void* a, const void* b, int h);
  void print(void* no);
  void trocarNos(No* no1, No* no2);
  void compararListaNo(No* lista, int tamanho, No* no, float* p);
#endif