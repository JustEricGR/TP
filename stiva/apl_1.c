#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int top=0;
int stack[MAX];

void push(int n)
{
    if(top>=MAX)
    {
        printf("Stiva este plina\n");
        exit(-1);
    }
    stack[top++]=n;
}

void display()
{
    if(top==0)
    {
        printf("Stiva este goala\n");
        exit(-1);
    }
    printf("Elementele din stiva sunt\n");
    for(int i=top-1;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }printf("\n");
}

int pop()
{
    if(top==0)
    {
        printf("Stiva este goala, nu avem ce extrage\n");
        return -1;
    }
    return stack[--top];
}

int main(void)
{
    int size=0;
    printf("Cate nr sa fie introduse?");
    scanf("%d",&size);
    printf("Introduceti numere\n");
    int v[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&v[i]);
        push(v[i]);
    }
    display();

    printf("%d\n",pop());
    printf("%d\n",pop());

}