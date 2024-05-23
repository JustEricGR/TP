#include<stdio.h>
#include<stdlib.h>

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

void afisare(int *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

int numarare(int *v,uint size,uint *indice,uint *valoare)
{
    if(*indice==size-1)
    {
        if(v[*indice]%2!=0)
        {
            return 1+*valoare;
        }
        else
            return *valoare;
    }
    if(v[*indice]%2!=0)
    {
        *valoare+=1;
        
    }
    *indice+=1;

    return numarare(v,size,indice,valoare);
}

int main(void)
{
    uint size=0,indice=0,valoare=0;
    int *v=NULL;
    printf("Cate elemente are vectorul:");
    scanf("%d",&size);
    v=citire(v,size);
    afisare(v,size);
    printf("Sunt %d nr impare\n",numarare(v,size,&indice,&valoare));
    free(v);
}