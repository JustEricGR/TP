#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
    int n;
    struct elem *urm;
}elem;

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
    if(lista==NULL)return nou(n,NULL);
    elem *p=lista,*urm;
    for(urm=p->urm;urm;p=urm,urm=p->urm){}
    p->urm=nou(n,NULL);
    return lista;
}

elem *inversare(elem *lista)
{
    elem *prev=NULL;
    elem *curent=lista;
    elem *next=NULL;
    while(curent)
    {
        
        next=curent->urm;
        curent->urm=prev;
        prev=curent;
        curent=next;

    }
    return prev;
}

void afisare(elem *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }printf("\n");
}

void eliberare(elem *lista)
{
    elem *p;
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
    printf("Cate elemente sa aiba lista:");
    scanf("%d",&size);
    elem *lista=NULL;
    for(uint i=0;i<size;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista=adaugaSfarsit(lista,n);
    }
    afisare(lista);
    lista=inversare(lista);
    afisare(lista);
    eliberare(lista);
}