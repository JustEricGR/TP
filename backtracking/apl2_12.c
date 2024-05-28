#include<stdio.h>

int v[100],n=0;

int comparare1(int *v,int start,int end)
{
    int prim=v[start];
    for(int i=start+1;i<end;i++)
    {
        if(prim<v[i])return 0;
        prim=v[i];
    }
    return 1;
}

int comparare2(int *v,int start,int end)
{
    int prim=v[start];
    for(int i=start+1;i<end;i++)
    {
        if(prim>v[i])return 0;
        prim=v[i];
    }
    return 1;
}

void afisare()
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

int valid(int k)
{
    
    for(int i=0;i<k;i++)
    {
        if(v[i]==v[k])return 0;
    }
    int mijl=k/2;
    if(!comparare1(v,0,mijl+1))return 0;
    if(!comparare2(v,mijl+1,k+1))return 0;
    return 1;
}

int solutie(int k)
{
    return k==n-1;
}

void back(int k)
{
    for(int i=1;i<=n;i++)
    {
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
    printf("Cate elemente are multimea de permutat:");
    scanf("%d",&n);
    back(0);
}