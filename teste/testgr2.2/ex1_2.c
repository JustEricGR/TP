#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

int prim(uint n)
{
    for(uint i=2;i<=n/2;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

uint *filtrare(uint *n,...)
{
    uint *rez=(uint*)malloc(*n*sizeof(uint));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    va_list va;
    uint adder=0;
    va_start(va,*n);
    for(int i=0;i<*n;i++)
    {
        uint nr=va_arg(va,int);
        if(prim(nr))rez[adder++]=nr;
        else
            continue;
        printf("%d\n",adder);
    }
    va_end(va);
    rez=(uint*)realloc(rez,adder*sizeof(uint));
    *n=adder;
    return rez;
}

void afisare(uint *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

int main(void)
{
    uint *v=NULL;
    uint size=5;

    v=filtrare(&size,44,17,9,5,11);
    afisare(v,size);
    free(v);
}