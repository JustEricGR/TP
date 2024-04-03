#include<stdio.h>
#include<stdarg.h>
#include<math.h>
#include<stdlib.h>

float *absolut(int n,...)
{
    float *rez=(float*)malloc(n*sizeof(float));
    va_list va;
    va_start(va,n);
    for(int i=0;i<n;i++)
    {
        rez[i]=fabs(va_arg(va,double));
    }
    va_end(va);
    return rez;
}

void afisare(float *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("%g ",v[i]);
    }printf("\n");
}

int main(void)
{
    uint size=0;
    float *v=NULL;
    printf("Cate elemente sa se citeasca:");
    scanf("%d",&size);
    v=(float*)malloc(size*sizeof(float));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    for(uint i=0;i<size;i++)
    {
        scanf("%f",&v[i]);

    }

    float *rez=NULL;
    
    
    rez=absolut(size,v[0],v[1],v[2],v[3],v[4]);
    
    afisare(rez,size);
    free(rez);
    free(v);
}