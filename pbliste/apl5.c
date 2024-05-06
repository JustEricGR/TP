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

nod *cautare(lista l,int nr)
{
    nod *c=NULL;
    for(c=l.prim;c;c=c->urm)
    {
        if(c->n == nr)
        {
            return c;
        }
    } 
    return NULL;
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
    free(n);
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
    printf("Cate elemente se citesc:");
    scanf("%d",&size);
    for(uint i=0;i<size;i++)
    {
        int nr=0;
        scanf("%d",&nr);
        nod *n=nod_nou(nr);
        adauga(&l,n);
    }
    afisare(l);
    stergere(&l,l.prim);
    stergere(&l,l.ultim);
    afisare(l);
    eliberare(&l);
}