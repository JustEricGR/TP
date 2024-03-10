#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NR_CUV 100
#define CUV_SIZE 50

char cuvinte[NR_CUV][CUV_SIZE];
int top=0;
void initializare(char v[][CUV_SIZE])
{
    for(int i=0;i<NR_CUV;i++)
    {
        memset(v[i],0,sizeof(char));
    }
}

void push(char *s)
{
    if(top>=NR_CUV)
    {
        printf("Stiva este plina\n");
        exit(-1);
    }
    strcpy(cuvinte[top++],s);

}

void display()
{
    if(top==0)
    {
        printf("Stiva este goala\n");
        exit(-1);
    }
    for(int i=0;i<top;i++)
    {
        puts(cuvinte[i]);
    }
}

void pop()
{
    if(top==0)
    {
        printf("Stiva este goala, nu avem ce extrage\n");
        exit(-1);
    }
    cuvinte[--top];
}

int main(void)
{
    int size=0,size1=0,opt=0;
    printf("Cate cuvinte sa fie citite:");
    scanf("%d",&size);
    char v[NR_CUV][CUV_SIZE];
    char v1[NR_CUV][CUV_SIZE];
    initializare(v);
    initializare(v1);
    for(int i=0;i<size;i++)
    {
        scanf("%49s",v[i]);
        push(v[i]);
    }
    printf("Cate cuvinte sa fie citite in continuare:");
    scanf("%d",&size1);
    printf("Introduceti un nou text\n");
    for(int i=0;i<size1;i++)
    {
        scanf("%49s",v1[i]);
        push(v1[i]);   
    }
        
            

    
    printf("Noua stiva este:\n");
    display();
    printf("De cate ori sa se apese undo?");
    scanf("%d",&opt);
    for(int i=0;i<opt;i++)
    {
        pop();
    }
    printf("Elementele obtinute dupa eliminare sunt:\n");
    display();
}