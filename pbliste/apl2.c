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

void swap(elem *lista)
{
    for(elem *p1=lista;p1!=NULL;p1=p1->urm)
    {
        for(elem *p2=p1->urm;p2!=NULL;p2=p2->urm)
        {
            if(p1->n > p2->n)
            {
                int aux=p2->n;
                p2->n=p1->n;
                p1->n=aux;
            }
        }
    }
}

void despartire(elem *lista,elem **lista1,elem **lista2)
{
    
    for(elem *p=lista;p!=NULL;p=p->urm)
    {
        if(p->n % 2 != 0)
        {
            if(*lista1==NULL)
            {
                *lista1=nou(p->n,NULL);
            }
            else
            {
                
                adaugaSfarsit(*lista1,p->n);
            }
        }



        else
        {
            if(*lista2==NULL)
            {
                *lista2=nou(p->n,NULL);
            }
            else
            {
                adaugaSfarsit(*lista2,p->n);
            }
        }        
    }

    swap(*lista1);
    swap(*lista2);

    
}



int main(int argc,char **argv)
{
    FILE *fin=NULL;
    if((fin=fopen(argv[1],"r"))==NULL)
    {
        printf("Eroare la deschidere\n");
        perror(NULL);
        exit(-1);
    }
    elem *lista=NULL,*lista1=NULL,*lista2=NULL;
    int n=0;
    while(fscanf(fin,"%d",&n)==1)
    {
        lista=adaugaSfarsit(lista,n);
    }

    despartire(lista,&lista1,&lista2);
    afisare(lista);
    afisare(lista1);
    afisare(lista2);

    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }
    
    eliberare(lista);
    
    
    eliberare(lista1);
    eliberare(lista2);
}