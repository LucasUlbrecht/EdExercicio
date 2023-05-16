#ifndef _EX_
#define _EX_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_MUNICIPIO 29
#define MAX_SIGLA_UF 2
#define MAX_NOME_ESTADO 17
#define MAX_NOME_CAPITAL 8
#define MAX_NOME_REGIAO 9

typedef struct EstruturaNo{
    void *dado;
    struct no *pai;
    struct no *esq;
    struct no *dir;
}no;

typedef struct MunicipiosBrasileiros
{
    int Cod;
    char NomeMuni[MAX_NOME_MUNICIPIO+1];
    int	CodUF;
    char SiglaUF[MAX_SIGLA_UF+1];
    char Estado[MAX_NOME_ESTADO+1];
    char Capital[MAX_NOME_CAPITAL+1];
    int	Latitude;
    int Longitude;
    char Regiao[MAX_NOME_REGIAO+1];
    int CodSiafi;
    int	DDD;
    int FusoHorario;
}MunicBr;


MunicBr* criarDado(int Cod, char* NomeMuni, int	CodUF, char* SiglaUF, char*	Estado, char* Capital, int	Latitude, int Longitude, char* Região, int CodSiafi, int DDD, int FusoHorario);
no* criarNo(void* dado);
void inserirNoArvore(no** Parv, void* dado);
void inserir(no** Parv, void* dado);

#endif