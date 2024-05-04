//program care elimina toate nodurile care indeplinesc o conditie

#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
    int n;
    struct elem *urm;
}elem;

int cond(int n)
{
    return n%2==0;
}

elem *nou(int n,elem *urm)
{
    elem *e=malloc(sizeof(elem));
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
    if(lista==NULL)
        return nou(n,lista);
    elem *p1;
    for(p1=lista;p1->urm!=NULL;p1=p1->urm)
    {}
    p1->urm=nou(n,NULL);
    return lista;
}

elem *stergere(elem *lista,int n)
{
    elem *pred=NULL,*crt=NULL;
    for(pred=NULL,crt=lista;crt;pred=crt,crt=crt->urm)
    {
        if(crt->n==n)
        {
            if(pred==NULL)
            {
                lista=lista->urm;
            }
            else
            {
                pred->urm=crt->urm;
            }
        }
    }
    free(crt);
    return lista;
}

void modif(elem **lista,int (*fct)(int))
{
    for(elem *c=*lista;c;c=c->urm)
    {
        if(!fct(c->n))
        {
            *lista=stergere(*lista,c->n);
        }
    }
}

// elem *stergere(elem *lista,int (*fct)(int))
// {
//     if(lista==NULL)return NULL;
//     elem *pred=NULL;
    
//     if(!fct(lista->n) || lista==NULL)
//     {
//         elem *new=lista->urm;
//         lista->urm=pred;
//         //new->urm=NULL;
//         free(lista);
//         lista=new;
//     }
//     elem *p1=lista;

//     for(p1=lista;p1!=NULL;p1=p1->urm)
//     {
//         elem *next=p1->urm->urm;
//         if(!fct(p1->urm->n))
//         {
//             free(p1->urm);
//             p1->urm=next;
//         }
//     }
    
//     //p1=lista;
    
    
    
//     return lista;
// }

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
    printf("Cate elemente se citesc in lista:");
    scanf("%d",&size1);
    for(int i=0;i<size1;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista1=adaugaSfarsit(lista1,n);
    }
    afisare(lista1);
    modif(&lista1,cond);
    afisare(lista1);
    eliberare(lista1);
}