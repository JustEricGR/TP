#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nume[20];
    int t1;
    int t2;
    int t3;
    int t4;
}prod;

void afisare(prod *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Vanzarile de %s sunt:%d,%d,%d,%d\n",v[i].nume,v[i].t1,v[i].t2,v[i].t3,v[i].t4);
    }
}

prod *conditie(prod *v,int *size)
{
    int size1=0;
    prod *rez=NULL;
    rez=(prod*)malloc((*size)*sizeof(prod));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<*size;i++)
    {
        if(v[i].t1<v[i].t2<v[i].t3<v[i].t4)
        {
            rez[size1++]=v[i];
        }
    }

    *size=size1;
    rez=(prod*)realloc(rez,(*size)*sizeof(prod));
    return rez;
}

void citire(prod *v,int size)
{
    prod *rez=NULL;

    for(int i=0;i<size;i++)
    {
        printf("Introduceti numele produsului %d :",i+1);
        scanf("%49s",v[i].nume);
        printf("Introduceti 4 vanzari: ");
        scanf("%d %d %d %d",&v[i].t1,&v[i].t2,&v[i].t3,&v[i].t4);
    }

    rez=conditie(v,&size);
    afisare(rez,size);
    free(rez);
}



int main(void)
{
    int size=0;
    printf("Cate produse sa se citeasca?");
    scanf("%d",&size);
    prod *v=NULL;
    v=(prod*)malloc(size*sizeof(prod));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);
    free(v);
}