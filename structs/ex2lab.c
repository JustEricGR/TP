#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    IESIRE,
    INTRODUCERE,
    AFISARE,
    CAUTARE
}opt;

typedef struct{
    char nume[51];
    float pret;
}Produs;

void citire(Produs *v, uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("Introduceti numele produsului %d si pretul acestuia:",i+1);
        scanf("%50s %g",v[i].nume,&v[i].pret);
    }
}

void afisare(Produs *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("%s - %g\n",v[i].nume,v[i].pret);
    }
}

void inserare(Produs *v,Produs *aux,uint size,uint size1)
{
    uint lungime=size+size1;
    uint j=0;
    for(uint i=size;i<lungime;i++)
    {
        v[i]=aux[j++];
    }
}

void getter(char *s,Produs *v,uint size)
{
    Produs *rez=NULL;
    uint new=0;
    rez=(Produs*)malloc(size*sizeof(Produs));
    if(rez==NULL)
    {
        printf("Eroare la alocarea rezultatelor\n");
        perror(NULL);
        exit(-1);
    }
    for(uint i=0;i<size;i++)
    {
        if(!strcasecmp(v[i].nume,s))
        {
            rez[new++]=v[i];
        }
    }
    rez=(Produs*)realloc(rez,new*sizeof(Produs));
    afisare(rez,new);
    free(rez);

}

int main(void)
{
    uint size=0;
    opt optiune;
    printf("Cate elemente sa fie introduse initial:");
    scanf("%d",&size);
    Produs *v=NULL;
    v=(Produs*)malloc(size*sizeof(Produs));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);
    while(1)
    {
        uint o=0;
        Produs *aux=NULL;
        char prod[51]="";
        printf("Introduceti 0 pt iesire, 1 pt introducerea elementului, 2 pt afisare si 3 pt afisarea unui anumit element:");
        scanf("%d",&o);
        optiune=o;
        switch(optiune)
        {
            case IESIRE:
            {
                free(v);
                return 0;
            }
            case INTRODUCERE:
            {
                int size1=0;
                printf("Cate elemente sa fie introduse:");
                scanf("%d",&size1);
                aux=(Produs*)malloc(size1*sizeof(Produs));
                if(aux==NULL)
                {
                    printf("Eroare la alocarea variabilei auxiliare de inserare\n");
                    perror(NULL);
                    exit(-1);
                }
                citire(aux,size1);
                v=(Produs*)realloc(v,(size1+size)*sizeof(Produs));
                inserare(v,aux,size,size1);
                size+=size1;
                free(aux);
                break;
            }
            case AFISARE:
            {
                afisare(v,size);
                break;
            }
            case CAUTARE:
            {
                printf("Intoduceti produsul care sa fie cautat:");
                scanf("%50s",prod);
                getter(prod,v,size);
                break;
            }
        }
    }
    

}