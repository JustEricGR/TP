#include<stdio.h>
#include<stdlib.h>

int cmp(const void *e1,const void *e2)
{
    int *v1=(int*)e1;
    int *v2=(int*)e2;
    // if(v1<v2)return 1;
    // else if(v1>v2)return -1;
    // else return 0;
    return v1-v2;
}

int *citire(int *v,uint size)
{
    v=(int*)malloc(size*sizeof(int));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    for(uint i=0;i<size;i++)
    {
        scanf("%d",&v[i]);
    }
    return v;
}

void sortare(int *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        for(uint j=i+1;j<size;j++)
        {
            if(v[i]>v[j])
            {
                int aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
            
        }
    }
}

void afisare(int *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

int *binsearch(int *v,uint *size,int n)
{
    int *v1=(int*)malloc((*size/2+1)*sizeof(int));
    if(*size==1)
    {
        if(v[*size-1]==n)
        {
            return v;
        }
        else
            return NULL;
    }
    else
    {
        if(v[*size/2]>n)
        {
            for(uint i=0;i<*size/2;i++)
            {
                v1[i]=v[i];
            } 
            *size=*size/2;
            return binsearch(v1,size,n);
        }
        else
        {
            uint adder=0;
            for(uint i=*size/2;i<*size;i++)
            {
                v1[adder++]=v[i];
            }
            *size=*size/2;
            return binsearch(v1,size,n);
        }
    }
    
    
}

int main(void)
{
    uint size=0;
    int *v=NULL;
    printf("Cate elemente are vectorul:");
    scanf("%d",&size);
    v=citire(v,size);
    afisare(v,size);
    //qsort(v,size,sizeof(int),cmp);
    sortare(v,size);
    afisare(v,size);
    int nr=0;
    printf("Introduceti un nr de cautat:");
    scanf("%d",&nr);
    if(binsearch(v,&size,nr))
    {
        printf("S-a gasit\n");
    }
    else
    {
        printf("Nu s-a gasit\n");
    }
    free(v);
}