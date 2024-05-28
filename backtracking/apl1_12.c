#include<stdio.h>

int v[10],n=0,x=0;

void afisare()
{
    for(int i=0;i<n;i++)
    {
        printf("%d",v[i]);
    }printf("\n");
}

int valid(int k)
{
    int counter=0;
    for(int i=0;i<=k;i++)
    {
        if(v[i] == 1)counter+=1;
    }
    return counter <= x;
}

int solutie(int k)
{
    int counter=0;
    
    for(int i=0;i<=k;i++)
    {
        if(v[i] == 1)counter++;
    }
    return counter == x && k == n-1;
    
    
   return 0;
}

void back(int k)
{
    if (k >= n) return;
    for(int i=0;i<=9;i++)
    {
        if(k == 0 && i == 0)continue;
        v[k]=i;
        if(valid(k))
        {
            if(solutie(k))
            {
                afisare();
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
    printf("De cate cifre sa fie numerele:");
    scanf("%d",&n);
    printf("Cate cifre de 1 sa fie in nr:");
    scanf("%d",&x);
    back(0);
}