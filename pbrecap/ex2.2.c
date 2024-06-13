#include<stdio.h>
#include<time.h>
#define OUT "cercuri.txt"
int v[20],nrLitere=0;

void afisare(FILE *fout)
{
    for(int i=0;i<nrLitere;i++)
    {
        fprintf(fout,"%d ",v[i]);
    }fprintf(fout,"\n");
}

int valid(int k)
{
    int suma1=v[0]+v[1];
    if(k==nrLitere-1)
    {
        int suma2=v[1]+v[2]+v[3];
        int suma3=v[3]+v[4]+v[5];
        int suma4=v[5]+v[6]+v[7];
        int suma5=v[7]+v[8];
        return suma1==suma2 && suma2==suma3 && suma3==suma4 && suma4==suma5;
    }
    return 1;
}

int solutie(int k)
{
    return k == nrLitere-1;
}

void back(int k,FILE *fout)
{
    for(int i=1;i<=9;i++)
    {
        v[k]=i;
        if(valid(k))
        {
            if(solutie(k))
            {
                afisare(fout);
            }
            else
            {
                back(k+1,fout);
            }
        }
    }
}

int main(void)
{
    clock_t start=0,end=0;
    double used=0;
    start=clock();
    FILE *fout=NULL;
    if((fout=fopen(OUT,"w"))==NULL)
    {
        printf("ERoare la deschidere\n");
        perror(NULL);
        return 0;
    }
    printf("Cate litere sunt:");
    scanf("%d",&nrLitere);
    back(0,fout);
    end=clock();
    used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total time:%g\n",used);
    return 0;
}