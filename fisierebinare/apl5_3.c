#include<stdio.h>
#include<stdlib.h>

void eliberare(uint **v,uint m)
{
    for(uint i=0;i<m;i++)free(v[i]);
    free(v);
}

void citire(uint **v,uint m,uint n)
{
    for(uint i=0;i<m;i++)
    {
        v[i]=(uint*)malloc(n*sizeof(uint));
        for(uint j=0;j<n;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }

}

void afisare(uint **v,uint m,uint n)
{
    for(uint i=0;i<m;i++)
    {
        for(uint j=0;j<n;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }printf("\n");
}

int main(int argc,char **argv)
{
    FILE *fisier=NULL;
    if((fisier=fopen(argv[1],"wb+"))==NULL)
    {
        printf("Eroare la deschidere fisier\n");
        perror(NULL);
        exit(-1);
    }
    uint m=0,n=0;
    printf("Cate linii sa aiba matricea:");
    scanf("%d",&m);
    printf("Cate coloane sa aiba matricea:");
    scanf("%d",&n);
    uint **v=NULL;
    fwrite(&m,sizeof(uint),1,fisier);
    //fseek(fisier,1,SEEK_SET);
    fwrite(&n,sizeof(uint),1,fisier);
    //fseek(fisier,1,SEEK_SET);
    v=(uint**)malloc(m*sizeof(uint*));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,m,n);
    for(uint i=0;i<m;i++)
    {
        fwrite(v[i],sizeof(uint),n,fisier);
    }
    afisare(v,m,n);
    fseek(fisier,0,SEEK_SET);
    uint *rez=(uint*)malloc((m*n+3)*sizeof(uint));
    fread(rez,sizeof(uint),m*n+2,fisier);
    for(uint i=0;i<m*n+2;i++)
    {
        printf("%d ",rez[i]);
    }printf("\n");
    free(rez);
    if(fclose(fisier)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        eliberare(v,m);
        exit(-1);
    }
    eliberare(v,m);
}