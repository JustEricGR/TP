#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef enum{
    INTRODUCERE,
    STERGERE,
    AFISARE,
    AFISARE_COND,
    ORDONARE,
    IESIRE
}opt;

typedef struct{
    unsigned int cod:13;
    unsigned int nr_locuri:4;
    unsigned int putere:9;
    unsigned int an:11;
    char marca[30];
    char culoare[30];
}Masina;

void citire(Masina *v,uint size)
{
    srand(time(NULL));
    for(uint i=0;i<size;i++)
    {
        uint cod=0,nr_locuri=0,putere=0,an=0;
        //printf("Introduceti codul masinii %d:",i);
        //scanf("%d",&cod);
        cod=(rand()%9000)+9000;
        //printf("Introduceti nr de locuri al masinii %d:",i);
        //scanf("%d",&nr_locuri);
        nr_locuri=rand()%9+1;
        //printf("Introduceti puterea masinii %d:",i);
        //scanf("%d",&putere);
        putere=(rand()%500)+500;
        //printf("Introduceti anul fabricarii masinii %d:",i);
        //scanf("%d",&an);
        an=rand()%218+1800;
        printf("Introduceti marca masinii %d:",i);
        scanf("%s",v[i].marca);
        printf("Introduceti culoarea masinii %d:",i);
        scanf("%s",v[i].culoare);
        v[i].cod=cod;
        v[i].nr_locuri=nr_locuri;
        v[i].putere=putere;
        v[i].an=an;
    }
}

void afisare(Masina *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("%s - %s - %d - %d - %dcp - %d\n",v[i].marca,v[i].culoare,v[i].an,v[i].nr_locuri,v[i].putere,v[i].cod);
    }

}

void inserare(Masina *v,Masina *aux,uint size,uint size1)
{
    uint lungime=size+size1;
    uint j=0;
    
    for(uint i=size;i<lungime;i++)
    {
        v[i]=aux[j++];
    }
}

void stergere(Masina *v,char *s,uint *size)
{
    for(uint i=0;i<*size;i++)
    {
        if(!strcasecmp(v[i].marca,s))
        {
            for(uint j=i+1;j<*size;j++)
            {
                v[j-1]=v[j];
            }
            (*size)--;
            i--;
        }
    }
    //v=(Masina*)realloc(v,(*size)*sizeof(Masina));
}

void afisare_speciala(Masina *v,uint locuri,uint size)
{
    //declaram un pointer de rezultate pornind de la premisa ca toate au nr de locuri cerut
    Masina *rez=NULL;
    uint j=0,signal=0;
    rez=(Masina*)calloc(size,sizeof(Masina));
    if(rez==NULL)
    {
        printf("Nu s a putut aloca un vector pt rezultate\n");
        perror(NULL);
        exit(-1);
    }
    for(uint i=0;i<size;i++)
    {
        if(v[i].nr_locuri==locuri)
        {
            rez[j++]=v[i];
            signal++;
        }
    }
    rez=(Masina*)realloc(rez,signal*sizeof(Masina));
    if(signal)
    {
        afisare(rez,signal);
    }
    else
    {
        printf("Nu s au gasit rezultate\n");
    }
    free(rez);
}

int ordonare(const void *e1,const void *e2)
{
    Masina *v1=(Masina*)e1;
    Masina *v2=(Masina*)e2;
    if(v1->an<v2->an)return -1;
    else if(v1->an>v2->an)return 1;
    else return (v1->putere-v2->putere);
}

int main(void)
{
    uint size=0;
    printf("Cate masini sa fie introduse initial:");
    scanf("%d",&size);
    Masina *v=NULL;
    v=(Masina*)malloc(size*sizeof(Masina));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);
    while(1)
    {
        opt optiune;
        uint o=0,size1=0;
        printf("Introduceti 0 pt a adauga o noua masina, 1 pt stergerea unei marci de automobile, 2 pt afisarea intregii liste, 3 pt afisarea masinilor care au un anumit nr de locuri, 4 pt ordonare si 5 pt iesire:");
        scanf("%d",&o);
        optiune=o;
        Masina *aux=NULL;
        char marca_aux[30]="";
        int numar_locuri=0;
        switch(optiune)
        {
            case INTRODUCERE:
            {
                printf("Cate elemente sa fie introduse:");
                scanf("%d",&size1);
                aux=(Masina*)malloc(size1*sizeof(Masina));
                if(aux==NULL)
                {
                    printf("Nu se pot aduga masini in variabila auxiliara\n");
                    perror(NULL);
                    exit(-1);
                }
                citire(aux,size1);
                Masina *temp=(Masina*)realloc(v,(size+size1)*sizeof(Masina));
                if(temp==NULL)
                {
                    printf("Eroare la alocarea memoriei pt introducere\n");
                    perror(NULL);
                    exit(-1);
                }
                v=temp;
                inserare(v,aux,size,size1);
                size+=size1;
                free(aux);
                break;
            }
            case STERGERE:
            {
                printf("Ce marca de masina sa se stearga:");
                scanf("%49s",marca_aux);
                stergere(v,marca_aux,&size);
                Masina *temp=(Masina*)realloc(v,size*sizeof(Masina));
                if(temp==NULL)
                {
                    printf("Eroare la alocarea memoriei pt introducere\n");
                    perror(NULL);
                    exit(-1);
                }
                v=temp;
                if(aux!=NULL)free(aux);
                break;
            }
            case AFISARE:
            {
                afisare(v,size);
                break;
            }
            case AFISARE_COND:
            {
                printf("Masinile cu cate locuri sa fie afisate:");
                scanf("%d",&numar_locuri);
                afisare_speciala(v,numar_locuri,size);
                break;
            }
            case ORDONARE:
            {
                qsort(v,size,sizeof(Masina),ordonare);
                break;
            }
            case IESIRE:
                free(v);
                return 0;
        }
    }
}