#ifndef _EX_
#define _EX_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LIXO 70
#define MAX_NOME_MUNICIPIO 29
#define MAX_SIGLA_UF 2
#define MAX_NOME_ESTADO 17
#define MAX_NOME_CAPITAL 8
#define MAX_NOME_REGIAO 9
#define NUM_ESTADOS 28

typedef struct EstruturaNo{
    void *dado;
    EstruturaNo *pai;
    EstruturaNo *esq;
    EstruturaNo *dir;
}No;



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
    int	Latitude;
    int Longitude;
    int CodSiafi;
    int	DDD;
    int FusoHorario;
    int	CodUF;
    char SiglaUF[MAX_SIGLA_UF+1];
    char Regiao[MAX_NOME_REGIAO+1];
}MunicBr;
int interface();
int buscaBinariaElemento(int valor, int init, int fim,  RegBr* lReg);
void GerarListaMunicBr(MunicBr** listaMunicBr);
MunicBr* criarDado(int Cod, char* NomeMuni, int	CodUF, char* SiglaUF, char*	Estado, char* Capital, int	Latitude, int Longitude, char* Região, int CodSiafi, int DDD, int FusoHorario);
No* criarNo(void* dado);
void inserirNoArvore(No **Parv, void *arr,int init, int tam, char* tipoOp);

#endif