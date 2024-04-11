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

elem *adaugaInceput(elem *lista,int n)
{
    return nou(n,lista);
}

elem *adaugaSfarsit(elem *lista,int n)
{
    if(lista==NULL)return nou(n,NULL);
    elem *p=lista,*urm;
    for(urm=p->urm;urm;p=urm,urm=p->urm){}
        p->urm=nou(n,NULL);
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

int comp(elem *lista1,elem *lista2)
{
    for(;lista1 && lista2;lista1=lista1->urm , lista2=lista2->urm)
    {
        if(lista1->n != lista2->n)return 0;
        if(lista1==NULL && lista2==NULL)
        {
            return 1;
        }
        else
            return 0;
    }
    return -1;
}

int main(void)
{
    elem *lista1=NULL;
    uint size1=0;
    printf("Cate elemente se citesc in prima lista:");
    scanf("%d",&size1);
    for(int i=0;i<size1;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista1=adaugaSfarsit(lista1,n);
    }

    elem *lista2=NULL;
    uint size2=0;
    printf("Cate elemente se citesc in a doua lista:");
    scanf("%d",&size2);
    for(int i=0;i<size2;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista2=adaugaSfarsit(lista2,n);
    }
    int flag=comp(lista1,lista2);
    if(flag)printf("Sunt egale\n");
    else
        printf("Sunt diferite\n");
    eliberare(lista1);
    eliberare(lista2);
}