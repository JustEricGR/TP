#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int impar(int n)
{
    return n%2!=0;
}

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

nod *inserare(nod *lista,int (*fct)(int))
{
    nod *crt=NULL;
    for(crt=lista;crt;crt=crt->urm)
    {
        if(fct(crt->n))
        {
            nod *aux=nou(pow(crt->n,2),NULL);
            aux->urm=crt->urm;
            crt->urm=aux;
            crt=crt->urm;
        }
    }
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
    lista=inserare(lista,impar);
    afisare(lista);
    eliberare(lista);
}