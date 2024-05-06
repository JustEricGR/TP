#include<stdio.h>
#include<stdlib.h>

int cond(int n)
{
    return n%2==0;
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

void afisare(nod *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }printf("\n");
}

void despartire(nod *lista,nod **lista1,nod **lista2,int (*fct)(int))
{
    for(nod *c=lista;c;c=c->urm)
    {
        if(fct(c->n))
        {
            *lista1=adaugaSfarsit(*lista1,c->n);
        }
        else
        {
            *lista2=adaugaSfarsit(*lista2,c->n);
        }
    }
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
    nod *lista1=NULL,*lista2=NULL;
    printf("Cate elemente are lista:");
    scanf("%d",&size);
    for(uint i=0;i<size;i++)
    {
        int nr=0;
        scanf("%d",&nr);
        lista=adaugaSfarsit(lista,nr);
    }

    afisare(lista);
    despartire(lista,&lista1,&lista2,cond);
    afisare(lista1);
    afisare(lista2);
    eliberare(lista);
    eliberare(lista1);
    eliberare(lista2);
}