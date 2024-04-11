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
    if(lista==NULL) return nou(n,NULL);

    elem *p;
    for(p=lista;p->urm!=NULL;p=p->urm)
    {}
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



elem *ordonare(elem *lista)
{
    if(lista==NULL || lista->urm==NULL)return lista;
    elem *p1=NULL,*p2=NULL;
    for(p1=lista;p1->urm!=NULL;p1=p1->urm)
    {
        elem *min=p1;
        for(p2=p1;p2!=NULL;p2=p2->urm)
        {
            if(min->n>p2->n)
            {
                min=p2;
            }
        }
        int aux=0;
        aux=p1->n;
        p1->n=min->n;
        min->n=aux;
    }
    return lista;
}


elem *concat(elem *lista1,elem *lista2)
{
    if(lista1==NULL)return lista2;
    else if(lista2==NULL)return lista1;

    elem *p1=NULL,*p2=NULL,*rez=NULL;

    for(p1=lista1;p1!=NULL;p1=p1->urm)
    {
        if(rez==NULL)
        {
            rez=nou(p1->n,NULL);
        }
        else
        {
            rez=adaugaSfarsit(rez,p1->n);
        }
    }

    for(p2=lista2;p2!=NULL;p2=p2->urm)
    {
        rez=adaugaSfarsit(rez,p2->n);
    }

    return rez;
}



void eliberare(elem *lista)
{
    elem *p;
    while(lista!=NULL)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
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
    lista1=ordonare(lista1);
    afisare(lista1);

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
    lista2=ordonare(lista2);
    afisare(lista2);
    elem *rez=NULL;
    rez=concat(lista1,lista2);
    afisare(rez);
    
    eliberare(lista1);
    eliberare(lista2);
    eliberare(rez);
}