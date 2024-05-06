#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
    struct elem *urm;
    int n;
}elem;

int cond(int n)
{
    return n%2==0;
}

elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
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

elem *adaugaSfarsit(elem *lista,int n)
{
    elem *c=NULL;
    if(lista==NULL)
    {
        return nou(n,NULL);
    }
    for(c=lista;c->urm!=NULL;c=c->urm)
    {}
    c->urm=nou(n,NULL);
    return lista;
}

void afisare(elem *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }printf("\n");
}



void inserare(elem **lista,int (*fct)(int))
{
    elem *c=NULL;
    for(c=*lista;c;c=c->urm)
    {
        if(fct(c->n))
        {
            int jum=(c->n)/2;
            elem *next=c->urm;
            c->urm=nou(jum,next);
            c=c->urm;
        }
    }
}

void eliberare(elem *lista)
{
    elem *p=NULL;
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
    printf("Cate elemente se introduc:");
    scanf("%d",&size);
    elem *lista=NULL;
    for(uint i=0;i<size;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista=adaugaSfarsit(lista,n);
    }
    afisare(lista);
    inserare(&lista,cond);
    afisare(lista);
    eliberare(lista);
}