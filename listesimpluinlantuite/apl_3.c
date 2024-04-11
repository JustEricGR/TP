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
    if (lista == NULL) 
    {
        return nou(n, NULL); 
    }
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

elem *concat(elem *lista1,elem *lista2)
{
    elem *rez=NULL;
    
    for(elem *p=lista1;p!=NULL;p=p->urm)
    {
        if(rez==NULL)
        {
            rez=nou(p->n,NULL);
        }
        else
        {
            adaugaSfarsit(rez,p->n);
        }
        
    }

    for(elem *p=lista2;p!=NULL;p=p->urm)
    {
        uint flag=0;
        for(elem *p1=rez;p1!=NULL;p1=p1->urm)
        {
            if(p->n==p1->n)
            {
                flag++;
                break;
            }
        }
        if(!flag) adaugaSfarsit(rez,p->n);
        else continue;
    }
    return rez;
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

    elem *rez=concat(lista1,lista2);
    afisare(rez);
    eliberare(rez);
    
    
    eliberare(lista1);
    eliberare(lista2);
}