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

int comp(elem *lista1,elem *lista2)
{
    if(lista1==NULL && lista2==NULL)
        return 0;
    int ok=0,size1=0;
    elem *p1=NULL,*p2=NULL;
    for(p1=lista1;p1->urm!=NULL;p1=p1->urm)
    {
        size1++;
        for(p2=lista2;p2->urm!=NULL;p2=p2->urm)
        {
            if(p1->n==p2->n)
            {
                ok++;
                break;
            }
        }
    }
    return size1==ok;
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
    //afisare(lista1);

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
    //afisare(lista2);
    int flag=comp(lista1,lista2);
    if(flag)printf("Sunt egale\n");
    else
        printf("Sunt diferite\n");
    
    
    eliberare(lista1);
    eliberare(lista2);
}