#include<stdio.h>
#include<stdlib.h>

typedef struct nod{
    int n;
    struct nod *pred;
    struct nod *urm;
}nod;

nod *nod_nou(int nr)
{
    nod *e=(nod*)malloc(sizeof(nod));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    e->n=nr;
    return e;
}

typedef struct{
    nod *prim;
    nod *ultim;
}lista;

void lista_init(lista *l)
{
    l->prim=l->ultim=NULL;
}

void adauga(lista *l,nod *n)
{
    n->pred=l->ultim;
    if(l->ultim)
    {
        l->ultim->urm=n;
    }
    else
    {
        l->prim=n;
    }
    l->ultim=n;
    n->urm=NULL;
}

void stergere(lista *l,nod *n)
{
    if(n->pred)
    {
        n->pred->urm=n->urm;
    }
    else
    {
        l->prim=n->urm;
    }

    if(n->urm)
    {
        n->urm->pred=n->pred;
    }
    else
    {
        l->ultim=n->pred;
    }
}

void afisare(lista l)
{
    for(nod *c=l.prim;c;c=c->urm)
    {
        printf("%d ",c->n);
    }printf("\n");
}

void mutare(lista *l)
{
    nod *n=l->ultim;
    stergere(l,n);
    n->urm=l->prim;
    n->pred=NULL;
    l->prim=n;
}

void eliberare(lista *l)
{
    nod *c=NULL,*urm=NULL;
    for(c=l->prim;c;c=urm)
    {
        urm=c->urm;
        free(c);
    }
}

int main(void)
{
    uint size=0;
    lista l;
    lista_init(&l);
    printf("Cate elemente are lista:");
    scanf("%d",&size);
    for(uint i=0;i<size;i++)
    {
        int nr=0;
        nod *n=NULL;
        scanf("%d",&nr);
        n=nod_nou(nr);
        adauga(&l,n);
    }

    afisare(l);
    mutare(&l);
    afisare(l);
    eliberare(&l);
}