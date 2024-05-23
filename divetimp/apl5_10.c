#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

char *ordine(int *v,int a,int b)
{
    if(a>=b)
    {
        return 0;
    }
    if((b-a)==1)
    {
        if(v[a]<v[b])return "crescator";
        else if(v[a]==v[b]) return "constant";
        else return "descrescator";
    }

    uint mid=(a+b)/2;
    char *mijloc=ordine(v,mid,mid+1);
    char *stanga=ordine(v,a,mid);
    char *dreapta=ordine(v,mid+1,b);
    if(stanga==dreapta && mijloc==dreapta)return dreapta;
    else if(!strcmp(stanga,"constant") && mijloc==dreapta)return dreapta;
    else if(!strcmp(dreapta,"constant") && mijloc==stanga)return stanga;
    
    return "neordonat";
}

int main(void)
{
    uint size=0;
    int *v=NULL;
    printf("Cate elemente are vectorul:");
    scanf("%d",&size);
    v=citire(v,size);
    afisare(v,size);
    puts(ordine(v,0,size-1));
    free(v);
}