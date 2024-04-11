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
        int aux=0;
        elem *min=p1;
        for(p2=p1;p2!=NULL;p2=p2->urm)
        {
            if (p2->n < min->n) 
            {
                min = p2;
            }
        }
        aux=p1->n;
        p1->n=min->n;
        min->n=aux;

    }
    return lista;
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
    afisare(lista1);
    lista1=ordonare(lista1);
    afisare(lista1);
    
    
    eliberare(lista1);
}