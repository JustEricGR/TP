#include<stdio.h>
#include<stdlib.h>

int cmp(const void *e1,const void *e2)
{
    int *v1=(int*)e1;
    int *v2=(int*)e2;
    return *v1-*v2;
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

void afisare(int *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

void sume(int *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        uint k=1,suma=0,flag=0;
        for(uint j=0;j<i+1;j++)
        {
            suma+=v[j];
            
            if(v[i]==suma)
            {
                printf("%d\n",k);
                flag=1;
                break;
            }
            k++;
        }
        if(!flag)printf("0\n");
    }
}

int main(void)
{
    uint size=0;
    int *v=NULL;
    scanf("%d",&size);
    v=citire(v,size);
    qsort(v,sizeof(int),size,cmp);
    //afisare(v,size);
    sume(v,size);
    free(v);
}