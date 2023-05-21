#ifndef _EX_
#define _EX_

#include "exABB.h"
#include <assert.h>
#include <string.h>
#include <math.h>

#define TAM_LIXO 70
#define MAX_NOME_MUNICIPIO 29
#define MAX_SIGLA_UF 2
#define MAX_NOME_ESTADO 17
#define MAX_NOME_CAPITAL 8
#define MAX_NOME_REGIAO 9
#define MAX_TAM_FUSO 30
#define NUM_ESTADOS 30

typedef struct RegiaoBrasil
{
    int	CodUF;
    char SiglaUF[MAX_SIGLA_UF+1];
    char Regiao[MAX_NOME_REGIAO+1];
}RegBr;

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
  void* GerarListaMunicBr();
  void abrirListaAquiv(FILE**ListaArquivMunic);

//Operações em KD-Tree

//  Inserção
    void inserirNoArvoreBalanceada(No **Parv, void *arr,int init, int tam, char* tipoOp);
    void inserirNoArvoreUnico(No** Parv, void* dado, int ordem);
//  Busca Ponto
    No* buscarPonto(No* Parv, float px, float py, int ordem);
    int buscaBinariaElemento(int valor, int init, int fim,  RegBr* lReg);
    int encontrarPontoFora(No* Parv, int px, int py, int grau, int* menorPx, int* menorPy);
    int calcularDiferencaPontos(int p1x, int p1y, int p2x, int p2y);
    No* encontrarPontoCod(No* Parv, int cod);
    No* comparador(No* Parv, int px, int py, MunicBr* aux);
    void encontrarPonto(No* Parv, int px, int py, int grau);
//Operações com dados MunicBr
  MunicBr* criarDado(int Cod, char* NomeMuni, int	CodUF, char* SiglaUF, char*	Estado, char* Capital, float	Latitude, float Longitude, char* Região, int CodSiafi, int DDD, char* FusoHorario);
  MunicBr* coletarDado();
  void printDado(void* auxB);

#endif