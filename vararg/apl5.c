#include<stdio.h>
#include<stdarg.h>
#include<string.h>

void input(const char *fmt,...)
{
    int marker=0;
    va_list va;
    va_start(va,fmt);
    for(int i=0;i<strlen(fmt);i++)
    {
        if(fmt[i]=='%')
        {
            switch(fmt[i+1])
            {
                case 'd':
                {
                    int *n=va_arg(va,int*);
                    for(int j=marker;j<i;j++)
                    {
                        printf("%c",fmt[j]);
                    }
                    printf("%d\n",*n);
                    marker=i+2;
                    break;
                }
                case 'f':
                {
                    float *n=(float*)va_arg(va,double*);
                    for(int j=marker;j<i;j++)
                    {
                        printf("%c",fmt[j]);
                    }
                    printf("%f\n",*n);
                    marker=i+2;
                    break;
                }
                case 'c':
                {
                    char *n=(char*)va_arg(va,int*);
                    for(int j=marker;j<i;j++)
                    {
                        printf("%c",fmt[j]);
                    }
                    printf("%c\n",*n);
                    marker=i+2;
                    break;
                }
            }
        }
    }
    va_end(va);
}

int main(void)
{
    int n=0;
    char ch='a';
    float f=4.56;
    input("n=%dch=%cf=%f",&n,&ch,&f);
}