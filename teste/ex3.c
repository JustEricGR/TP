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
    e->pred=e->urm=NULL;
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
}

void afisare(lista l)
{
    for(nod *c=l.prim;c;c=c->urm)
    {
        printf("%d ",c->n);
    }printf("\n");
}

nod *stergere(lista *l,nod *n)
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
    
    return n;
}

void oglindire(lista *l,uint size)
{
    nod *crt=l->prim,*prev=NULL;
    for(uint i=0;i<size-1;i++)
    {
        if(i==0)
        {
            prev=stergere(l,l->ultim);
            l->prim=prev;
            prev->urm=crt;
        }
        else
        {
            nod *n=stergere(l,l->ultim);
            n->pred=prev;
            n->urm=crt;
            prev->urm=n;
            crt->pred=n;
            prev=n;
        }
    }
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
        scanf("%d",&nr);
        nod *n=nod_nou(nr);
        adauga(&l,n);
    }
    afisare(l);
    oglindire(&l,size);
    afisare(l);
    eliberare(&l);
}