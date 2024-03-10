#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nume[20];
    int cod;
}oras;

void eliberare(int **v,int size)
{
    for(int i=0;i<size;i++)free(v[i]);
    free(v);
}

int minim(int *v,int size)
{
    int min=0;
    if(v[0]!=0)min=v[0];
    else min=v[1];
    for(int i=0;i<size;i++)
    {
        if(v[i]==0)continue;
        if(v[i]<min)min=v[i];
    }
    return min;
}

int **citire(int size)
{
    int **rez=NULL;

    oras *v=NULL;
    v=(oras*)malloc(size*sizeof(oras));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    rez=(int**)malloc(size*sizeof(int*));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    //int i=0,j=0;
    for(int i=0;i<size;i++)
    {
        printf("Numele orasului %d:",i+1);
        scanf("%19s",v[i].nume);
        v[i].cod=i;
    }

    for(int i=0;i<size;i++)
    {
        rez[i]=(int*)malloc(size*sizeof(int));
        if(rez[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            eliberare(rez,size);
            exit(-1);
        }
        
        for(int j=0;j<=i;j++)
        {
            if(i==j)
            {
                rez[i][j]=0;
            }
            else
            {
                printf("Introduceti distanta dintre orasele %s si %s: ", v[i].nume, v[j].nume);
                scanf("%d", &rez[i][j]);
                rez[j][i] = rez[i][j];
            }
                
        }
        
        
    }

    for(int i=0;i<size;i++)
    {
        printf("Distanta cea mai mica fata de %s este %d\n",v[i].nume,minim(rez[i],size));
    }

    free(v);
    return rez;
    
}

void afisare(int **v,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }printf("\n");
}


int main(void)
{
    int size=0;
    //oras *city;
    printf("Introduceti maxim 10 orase\n");
    scanf("%d",&size);
    int **v=NULL;
    v=citire(size);
    afisare(v,size);
    eliberare(v,size);
}