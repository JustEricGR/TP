#include <stdio.h>
#include <stdlib.h>


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

elem *stergere(elem *lista)
{
    if(lista==NULL || lista->urm==NULL)
        return NULL;
    elem *p;
    for(p=lista;p->urm->urm!=NULL;p=p->urm)
    {}
    free(p->urm);
    p->urm=NULL;
    return lista;
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
    elem *lista=NULL;
    uint size=0;
    printf("Cate elemente se citesc in prima lista:");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista=adaugaSfarsit(lista,n);
    }
    afisare(lista);
    stergere(lista);
    afisare(lista);
    
    
    eliberare(lista);
}