#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
    int x,y;
}Puncte;

void eliberare(double **v,uint size)
{
    for(uint i=0;i<size;i++)free(v[i]);
    free(v);
}

void citire(Puncte *v,int size)
{
    for(uint i=0;i<size;i++)
    {
        printf("Introduceti coordonatele punctului %d:",i+1);
        scanf("%d %d",&v[i].x,&v[i].y);
    }
}

double **distanta(double **dist,Puncte *v,uint size)
{
    //double **dist=(double**)malloc(size*sizeof(double*));
    
    for(uint i=0;i<size;i++)
    {
        dist[i]=(double*)calloc(size,sizeof(double));
        if(dist[i]==NULL)
        {
            printf("Eroare la alocare in for\n");
            perror(NULL);
            exit(-1);
        }
        for(uint j=i+1;j<size;j++)
        {
            dist[i][j]=sqrt(pow(v[i].x-v[j].x,2)+pow(v[i].y-v[j].y,2));
            //dist[j][i]=dist[i][j];
        }
        
    }
    return dist;
}

void afisare(double **v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        for(uint j=0;j<size;j++)
        {
            printf("%4.4f\t",v[i][j]);
        }
        printf("\n");
    }
}




int main(void)
{
    uint size=0;
    printf("Cate puncte sa se citeasca:");
    scanf("%d",&size);
    Puncte *v=NULL;
    v=(Puncte*)malloc(size*sizeof(Puncte));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);
    double **d=NULL;
    d=(double**)malloc(size*sizeof(double*));
    if(d==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    d=distanta(d,v,size);
    afisare(d,size);
    free(v);
    eliberare(d,size);
}