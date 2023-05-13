#ifndef _EDTRABAIO_
#define _EDTRABAIO_
#define MAXNOMEMUNICIPIO 29;
#define MAXSIGLAUF 2;
#define MAXNOMEESTADO 17;
#define MAXNOMECAPITAL 8;
#define MAXNOMEREGIAO 9;
typedef struct _node{
    void *informacao;
    struct _node *pai;
    struct _node *esq;
    struct _node *dir;
    int h;
}tnode;

typedef struct MunicipiosBrasileiros
{
    int Cod
    char[MAXNOMEMUNICIPIO+1] NomeMuni;
    int	CodUF
    char[MAXSIGLAUF+1] SiglaUF;
    char[MAXNOMEESTADO+1]	Estado;
    char[MAXNOMECAPITAL+1]	Capital;
    int	Latitude;
    int Longitude;
    char[MAXNOMEREGIAO+1] Região;
    int CodSiafi;
    int	DDD;
    int FusoHorario;
    kdT* cabeca;
    kdT* fEsq;
    kdT* fDir;
}MunicBr;



void avl_insere(tnode ** parv,titem reg);
void avl_rebalancear(tnode **parv);

#endif