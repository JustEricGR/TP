#include<stdio.h>

int v[10],n=3,m=6;

void afisare()
{
    for(int i=0;i<m;i++)
    {
        printf("%d ",v[i]);
    }printf("\n");
}

int valid(int k)
{
    for(int i=0;i<k;i++)
    {
        if(!v[i])continue;
        if(v[i]==v[k])return 0;
    }
    int flag=0;
    int prev=v[0];
    for(int i=1;i<=k;i++)
    {
        if(prev && v[i])return 0;
        
        if(i!=k)
            prev=v[i];
    }
    
    int pred=0;
    for(int i=0;i<=k;i++)
    {
        if(v[i] && !pred)
        {
            pred=v[i];
            continue;
        }
        if(v[i] && pred)
        {
            if(v[i]>pred)
            {
                pred=v[i];
                continue;
            }
            else return 0;
        }
    }

    for(int i=0;i<=k;i++)
    {
        if(v[i])flag++;
    }
    if(k==m-1)return flag==n;
    else return flag <= n;
}

int solutie(int k)
{
    
    return k == m-1;
}

void back(int k)
{
    for(int i=0;i<=n;i++)
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
    back(0);
}
