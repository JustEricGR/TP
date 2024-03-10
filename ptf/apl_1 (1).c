#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nume[20];
    int nota;
}Date;

/*int ordNume(const void *elem1, const void *elem2)
{
    const Date *v1=(const Date*)elem1;
    const Date *v2=(const Date*)elem2;
    if(v1->nume[0]>v2->nume[0])return 1;
    if(v1->nume[0]>v2->nume[0])return -1;
    return 0;
}*/

int ordNote(const void *elem1, const void *elem2)
{
    Date *v1=(Date*)elem1;
     Date *v2=(Date*)elem2;
    //Date *aux=NULL;
    if(v1->nota>v2->nota)return -1;
    else if(v1->nota<v2->nota)return 1;
    
    return strcmp(v1->nume,v2->nume);
}

void citire(Date *v,int size)
{
    for(int i=0;i<size;i++)
    {
        scanf("%19s",v[i].nume);
        scanf("%d",&v[i].nota);
    }
}

void afisare(Date *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%s - %d\n",v[i].nume,v[i].nota);
    }
}

int main(void)
{
    int size=0;
    scanf("%d",&size);
    Date *v=NULL;
    v=(Date*)malloc(size*sizeof(Date));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    citire(v,size);
    printf("Ordonarea dupa note este:\n");
    qsort(v,size,sizeof(Date),ordNote);

    afisare(v,size);
    //qsort(v,size,sizeof(Date),ordNume);
    //afisare(v,size);
    free(v);
}