#include<stdio.h>
#include<stdlib.h>

typedef struct nod{
    int n;
    struct nod *pred;
    struct nod *urm;
}nod;

nod *nod_nou(int n)
{
    nod *e=(nod*)malloc(sizeof(nod));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    e->n=n;
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

void afisare(lista l)
{
    for(nod *c=l.prim;c;c=c->urm)
    {
        printf("%d ",c->n);
    }printf("\n");
}

void eliberare(lista *l)
{
    nod *p=NULL,*urm=NULL;
    for(p=l->prim;p;p=urm)
    {
        urm=p->urm;
        free(p);
    }
}

void modif(lista *l,nod *n)
{
    int nr=n->n;
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
    free(n);
    nod *n1=nod_nou(nr);
    n1->urm=l->ultim;
    n1->pred=l->ultim->pred;
    l->ultim->pred->urm=n1;
    l->ultim->pred=n1;
}

int main(void)
{
    uint size=0;
    int prim=0;
    lista l;
    lista_init(&l);
    printf("Cate noduri are lista:");
    scanf("%d",&size);
    for(uint i=0;i<size;i++)
    {
        nod *n=NULL;
        int nr=0;
        scanf("%d",&nr);
        if(i==0)
        {
            prim=nr;
        }
        n=nod_nou(nr);
        adauga(&l,n);
    }
    afisare(l);
    modif(&l,l.prim);
    afisare(l);
    eliberare(&l);
}