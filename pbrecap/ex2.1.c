#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define OUT "solutii.txt"
int v[10],n=0,a=0,b=0;

int sumacif(int n)
{
    if(n<10)
    {
        return n;
    }
    else
    {
        return n%10+sumacif(n/10);
    }
}

void afisare(FILE *fout)
{
    for(int i=0;i<n;i++)
    {
        fprintf(fout,"%d ",v[i]);
    }fprintf(fout,"\n");
}

int valid(int k)
{
    int pred=v[0];
    for(int i=1;i<=k;i++)
    {
        if(sumacif(pred)+sumacif(v[i])!=10)return 0;
        pred=v[i];
    }
    return 1;
}

int solutie(int k)
{
    return k == n-1;
}

void back(int k,FILE *fout)
{
    for(int i=a;i<b;i++)
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


int main(int argc,char **argv)
{
    clock_t start=0,end=0;
    double used=0;
    start=clock();
    FILE *fout=NULL;
    if((fout=fopen(OUT,"w"))==NULL)
    {
        printf("Eroare la deschidere fisier\n");
        perror(NULL);
        exit(-1);
    }
    sscanf(argv[1],"%d",&n);
    sscanf(argv[2],"%d",&a);
    sscanf(argv[3],"%d",&b);
    back(0,fout);
    if(fclose(fout))
    {
        printf("Eroare la inchidere fisier\n");
        perror(NULL);
        exit(-1);
    }
    end=clock();
    used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Total time:%g\n",used);
    return 0;
}