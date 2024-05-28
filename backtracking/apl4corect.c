#include<stdio.h>
#include<string.h>

char culori[6][10]={"alb","galben","rosu","verde","albastru","negru"},v[6][10];

void afisare()
{
    for(int i=0;i<6;i++)
    {
        printf("%s ",v[i]);
    }printf("\n");
}

// int valid(int k)
// {
//     for(int i=0;i<k;i++)
//     {
//         if((strcmp(v[1],"verde") || strcmp(v[1],"galben")) && strcmp(v[i],v[k]))return 0;
//     }
//     return 1;
// }

int valid(int k) {
    if (k == 1) 
    {
        if ((strcmp(v[1], "verde") == 0 || strcmp(v[1], "galben") == 0)) {
            return 1;
        } else {
            return 0;
        }
    }
    for (int i = 0; i < k; i++) {
        if (strcmp(v[i], v[k]) == 0) {
            return 0;
        }
    }
    return 1;
}

int solutie(int k)
{
    return k==2;
}

void back(int k)
{
    //puts(culori[0]);
    for(int i=0;i<=5;i++)
    {

        //puts(culori[i]);
        strcpy(v[k],culori[i]);
        //puts(v[k]);
        if(valid(k))
        {
            //puts(culori[i]);
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