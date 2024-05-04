#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Masina{
    uint cod;
    uint locuri;
    uint putere;
    char marca[16]; 
    char culoare[20];
    uint an;
    struct Masina *pred; 
    struct Masina *urm; 
 }Masina;

Masina *Masina_nou(uint cod,uint locuri,uint putere,const char *marca,const char *culoare,uint an)
{
    Masina *c=(Masina*)malloc(sizeof(Masina));
    if(!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    c->cod=cod;
    c->locuri=locuri;
    c->putere=putere;
    strcpy(c->marca,marca);
    strcpy(c->culoare,culoare);
    c->an=an;
    return c;
}


typedef struct{
    Masina *prim; 
    Masina *ultim; 
}Masini;

void Masini_init(Masini *p)
{
    p->prim=p->ultim=NULL;
}

void Masina_adauga(Masini *p,Masina *c)
{
    c->urm=p->prim; 
    /*if(p->ultim)
    { 
        p->ultim->urm=c; 
    }
    else
    { 
        p->prim=c; 
    }*/
    p->prim=c; 
    c->pred=NULL; 
}

Masina *Masina_cauta1(Masini *p,uint cod)
{
    Masina *c;
    for(c=p->prim;c;c=c->urm)
    {
        if(c->cod==cod)return c;
    }
    return NULL;
}


void Masina_sterge(Masini *p,Masina *c)
{
    if(c->pred)
    { 
        c->pred->urm=c->urm; 
    }
    else
    { 
        p->prim=c->urm; 
    }
    if(c->urm)
    { 
        c->urm->pred=c->pred; 
    }
    else
    { 
        p->ultim=c->pred; 
    }
    free(c);
}



void Masina_elibereaza(Masini *p)
{
    Masina *c,*urm;
    for(c=p->prim;c;c=urm)
    {
        urm=c->urm;
        free(c);
    }
    Masini_init(p);
}

void citire(Masini *p,uint size)
{
    srand(time(NULL));
    for(uint i=0;i<size;i++)
    {
        Masina *m=NULL;
        uint cod=0,locuri=0,putere=0,an=0;
        char marca[16]="",culoare[20]="";
        cod=(rand()%(9000-1))+1;
        locuri=(rand()%8)+1;
        putere=(rand()%(500-1))+1;
        printf("Introduceti marca masinii:");
        scanf("%15s",marca);
        printf("Introduceti culoarea masinii:");
        scanf("%19s",culoare);
        an=(rand()%(2017-1800))+1800;
        m=Masina_nou(cod,locuri,putere,marca,culoare,an);
        Masina_adauga(p,m);
    }
}

void change(Masina *c1,Masina *c2)
{
    c1->cod=c2->cod;
    c1->locuri=c2->locuri;
    c1->putere=c2->putere;
    strcpy(c1->marca,c2->marca);
    strcpy(c1->culoare,c2->culoare);
    c1->an=c2->an;
}

void ordonare(Masini *p)
{
    Masina *temp=NULL;
    for(Masina *c=p->prim;c;c=c->urm)
    {
        for(Masina *c1=c->urm;c1;c1=c1->urm)
        {
            if(c->an > c1->an)
            {
                //temp=c1;
                //c1=c;
                //c=temp;
                temp = (Masina*)malloc(sizeof(Masina)); // Allocate memory for temp
                if (!temp)
                {
                    printf("memorie insuficienta");
                    exit(EXIT_FAILURE);
                }

                change(temp,c1);
                change(c1,c);
                change(c,temp);
                free(temp);
                
                
                
            }
            
        }
    }
}


void afisare(Masini p)
{
    Masina *c=NULL;
    for(c=p.prim;c;c=c->urm)
    {
        printf("%d - %d - %d - %s - %s - %d\n",c->cod,c->locuri,c->putere,c->marca,c->culoare,c->an);
    }
}



int main()
{
    Masini p;
    int op; 
    
    Masini_init(&p);
    do
    {
        printf("1 - Introduceti o masina\n");
        printf("2 - Stergeti o masina cu un anumit cod\n");
        printf("3 - Afisarea listei\n");
        printf("4 - Afisarea masinilor cu un anumit nr de locuri\n");
        printf("5 - Ordonarea dupa anul de fabricatie\n");
        printf("6 - Iesire\n");
        printf("optiune: ");scanf("%d",&op);
        switch(op)
        {
            case 1:
            {
                uint size=0;
                printf("Cate masini sa se introduca:");
                scanf("%d",&size);
                citire(&p,size);
                break;
            }
            case 2:
            {
                uint n=0;
                printf("Scrieti codul masinii care sa fie stearsa:");
                scanf("%d",&n);
                Masina *m=NULL;
                m=Masina_cauta1(&p,n);
                if(m!=NULL)
                {
                    Masina_sterge(&p,m);
                }
                else
                {
                    printf("Nu s-a gasit codul\n");
                }
                break;
            }
            case 3:
            {
                afisare(p);
                break;
            }
            case 4:
            {
                uint n=0,flag=0;
                printf("Cate usi sa aibe masinile de afisat:");
                scanf("%d",&n);
                Masina *m=NULL;
                for(m=p.prim;m;m=m->urm)
                {
                    if(n==m->locuri)
                    {
                        flag++;
                        printf("%d - %d - %d - %s - %s - %d\n",m->cod,m->locuri,m->putere,m->marca,m->culoare,m->an);   
                    }
                }
                if(!flag)printf("Nicio masina nu are atatea usi\n");
                break;
            }
            case 5:
            {
                ordonare(&p);
                break;
            }

        
            case 6:
            {
                Masina_elibereaza(&p);
                return 0;
            }
        }
    }
    while(op!=4);
    Masina_elibereaza(&p);
    return 0;
}
