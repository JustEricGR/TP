#include<stdio.h>
#include<stdarg.h>

int citire(int n,...)
{
    va_list va;
    va_start(va,n);

    const int MAX_VALUE = 1000; 
    int counts[MAX_VALUE + 1] ;


    int commonElements=0;
    int* firstVec = va_arg(va, int*);
    int firstVecSize = va_arg(va, int);
    for (int i = 0; i < firstVecSize; i++) 
    {
        if (firstVec[i] >= 0 && firstVec[i] <= MAX_VALUE) 
        {
            counts[firstVec[i]] = 1;
        }
    }

    for (int v = 1; v < n; v++) 
    {
        int* vec = va_arg(va, int*);
        int vecSize = va_arg(va, int);
        int tempCounts[MAX_VALUE + 1];

        for (int i = 0; i < vecSize; i++) 
        {
            if (vec[i] >= 0 && vec[i] <= MAX_VALUE && counts[vec[i]] == v) 
            {
                tempCounts[vec[i]] = counts[vec[i]] + 1;
            }
        }

        for (int i = 0; i <= MAX_VALUE; i++)
        {
            if (tempCounts[i] > 0) 
            {
                counts[i] = tempCounts[i];
            } 
            else if (counts[i] == v) 
            {
                counts[i] = 0; 
            }
        }
    }

    va_end(va);

    for (int i = 0; i <= MAX_VALUE; i++) 
    {
        if (counts[i] == n) 
        {
            commonElements++;
        }
    }

    return commonElements;
}

int main() {
    int v1[] = {5, 8};
    int v2[] = {8, 3, 5};
    int v3[] = {5, 0, 8};

    int common = citire(3, v1, 2, v2, 3, v3, 3);
    printf("Numarul de elemente comune: %d\n", common);

    return 0;
}