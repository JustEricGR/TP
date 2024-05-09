#include<stdio.h>
#include<stdlib.h>

typedef struct nod{
    int n;
    struct nod *urm;
}nod;

nod *nou(int n,nod *urm)
{
    nod *e=(nod*)malloc(sizeof(nod));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    e->n=n;
    e->urm=urm;
    return e;
}

nod *adaugaSfarsit(nod *lista,int n)
{
    if(lista==NULL)
    {
        return nou(n,NULL);
    }

    nod *c=NULL;
    for(c=lista;c->urm!=NULL;c=c->urm)
    {}
    c->urm=nou(n,NULL);
    return lista;
}

nod *adaugaInceput(nod *lista,int n)
{
    return nou(n,lista);
}

void afisare(nod *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }printf("\n");
}

nod *stergere(nod *lista,int *n)
{
    nod *crt=NULL,*next=NULL;
    for(crt=lista;crt->urm->urm!=NULL;crt=crt->urm,next=crt->urm)
    {}
    crt->urm=NULL;
    *n=next->n;
    free(next);
    return lista;
}

nod *permutare(nod *lista,int n)
{
    for(uint i=0;i<n;i++)
    {
        int n=0;
        lista=stergere(lista,&n);
        afisare(lista);
        lista=adaugaInceput(lista,n);

    }
    return lista;
}


void eliberare(nod *lista)
{
    nod *p=NULL;
    while(lista)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
}

int main(void)
{
    uint size=0,poz=0;
    nod *lista=NULL;
    printf("Cate elemente are lista:");
    scanf("%d",&size);
    for(uint i=0;i<size;i++)
    {
        int nr=0;
        scanf("%d",&nr);
        lista=adaugaSfarsit(lista,nr);
    }
    afisare(lista);
    printf("De la ce indice sa inceapa permutarea:");
    scanf("%d",&poz);
    lista=permutare(lista,size-poz);
    afisare(lista);
    eliberare(lista);
}