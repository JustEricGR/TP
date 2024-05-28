#include<stdio.h>

int v[20],n=0,lungime=0,nrPosibilitati=0;

void afisare()
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

int valid(int k)
{
    int suma=0,prev=v[0];

    for(int i=0;i<k;i++)
    {
        if(v[i]==v[k])return 0;
    }

    for(int i=1;i<=k;i++)
    {
        if(prev>=v[i])return 0;
        prev=v[i];
    }

    for(int i=0;i<=k;i++)
    {
        suma+=v[i];
    }
    return suma <= lungime;
}

int solutie(int k)
{
    int suma=0;
    for(int i=0;i<=k;i++)
    {
        suma+=v[i];
    }
    return suma == lungime && k == n-1;
}

void back(int k)
{
    for(int i=0;i<=lungime;i++)
    {
        if(i==0 && k==0)continue;
        v[k]=i;
        if(valid(k))
        {
            if(solutie(k))
            {
                afisare(k);
                nrPosibilitati++;
            }
            else
            {
                back(k+1);
            }
        }
    }
}

int main(void)
{
    printf("Introduceti lungimea dreptei:");
    scanf("%d",&lungime);
    printf("In cate segmente sa fie impartita:");
    scanf("%d",&n);
    back(0);
    printf("Sunt %d posibilitati\n",nrPosibilitati);
}