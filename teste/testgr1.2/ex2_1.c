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

void afisare(nod *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }printf("\n");
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

nod *inserare(nod *lista)
{
    for(nod *c=lista;c;c=c->urm)
    {
        if(c->n < 0)
        {
            nod *aux=nou(- c->n,NULL);
            aux->urm=c->urm;
            c->urm=aux;
            c=c->urm;
        }
    }
    return lista;
}

int main(void)
{
    uint size=0;
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
    lista=inserare(lista);
    afisare(lista);
    eliberare(lista);
}