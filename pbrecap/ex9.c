#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define CHUNK 10

typedef struct{
    char cuv[15];
    char expl[50];
}Cuvant;

typedef enum{
    AFISARE,
    INTRODUCERE,
    CAUTARE,
    STERGERE,
    IESIRE
}Optiuni;

Cuvant *citire(Cuvant *v,uint *size,const char *f)
{
    clock_t start,end;
    double used=0;
    start=clock();
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la deschidere1\n");
        perror(NULL);
        exit(-1);
    }
    v=(Cuvant*)malloc(CHUNK*sizeof(Cuvant));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int current_size=CHUNK,index=0;
    char aux[100]="";
    while(fgets(aux,100,fin))
    {
        if(sscanf(aux,"%14s %49[^\n]",v[index].cuv,v[index].expl)==2)
        {
            index++;
            if(index>=current_size)
            {
                current_size+=CHUNK;
                v=(Cuvant*)realloc(v,current_size*sizeof(Cuvant));
            }
        }
       
    }
    if(fclose(fin))
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        free(v);
        exit(-1);
    }
    *size=index;
    end=clock();
    used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Citirea a durat %g\n",used);
    return v;
}

void afisare(Cuvant *v,uint size)
{
    for(int i=0;i<size;i++)
    {
        printf("%s = %s\n",v[i].cuv,v[i].expl);
    }
}

Cuvant *inserare(Cuvant *v,uint *size,Cuvant *v1,uint size1)
{
    uint pornire=*size,adder=0;
    *size+=size1;
    v=(Cuvant*)realloc(v,*size*sizeof(Cuvant));
    for(uint i=pornire;i<*size;i++,adder++)
    {
        strcpy(v[i].cuv,v1[adder].cuv);
        strcpy(v[i].expl,v1[adder].expl);
    }
    return v;
}

Cuvant *stergere(Cuvant *v,uint *size,char aux[14])
{
    for(uint i=0;i<*size;i++)
    {
        if(!strcasecmp(v[i].cuv,aux))
        {
            *size-=1;
            for(uint j=i;j<*size;j++)
            {
                v[j]=v[j+1];
            }
            i--;
        }
    }
    return v;
}

int main(int argc,char **argv)
{
    uint size=0;
    Cuvant *v=NULL;
    v=citire(v,&size,argv[1]);
    Optiuni opt;
    
    while(1)
    {
        printf("Scrieti 0 pt afisare, 1 pt introducere de cuvant, 2 pt cautarea si afisarea unui cuvant, 3 pt stergerea unui cuvant si 4 pt iesire:");
        scanf("%u",&opt);
        switch(opt)
        {
            case AFISARE:
            {
                afisare(v,size);
                break;
            }
            case INTRODUCERE:
            {
                uint nr=0;
                printf("Cate elemente sa se adauge:");
                scanf("%d",&nr);
                Cuvant *aux=NULL;
                aux=(Cuvant*)malloc(nr*sizeof(Cuvant));
                if(aux==NULL)
                {
                    printf("Eroare la alocare\n");
                    perror(NULL);
                    free(v);
                    exit(-1);
                }
                for(uint i=0;i<nr;i++)
                {
                    scanf("%14s",aux[i].cuv);
                    fgets(aux[i].expl,50,stdin);
                }
                v=inserare(v,&size,aux,nr);
                free(aux);
                break;
            }
            case CAUTARE:
            {
                char aux[15]="";
                uint flag=0;
                printf("Ce cuvant sa fie cautat:");
                scanf("%14s",aux);
                for(uint i=0;i<size;i++)
                {
                    if(!strcasecmp(v[i].cuv,aux))
                    {
                        flag++;
                        printf("%s = %s\n",v[i].cuv,v[i].expl);
                        break;
                    }
                }
                if(!flag)printf("Nu s-a gasit cuvantul\n");
                break;
            }
            case STERGERE:
            {
                char aux[15]="";
                printf("Ce cuvant sa se stearga:");
                scanf("%14s",aux);
                v=stergere(v,&size,aux);
                break;
            }

            case IESIRE:
            {
                free(v);
                return 0;
            }
        }
    }
    
}