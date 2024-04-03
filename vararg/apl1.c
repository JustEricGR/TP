#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void err(int flag, const char *fmt, ...) {
    va_list va; 
    va_start(va, fmt);
    if(!flag) {
        fprintf(stderr, "Eroare: ");
        vfprintf(stderr, fmt, va); 
        va_end(va); 
        fputc('\n', stderr);
        exit(EXIT_FAILURE);
    }
}

int main() {
    int i = 0, n = 0;
    float x = 0, y = 0, e = 0, min = 0, max = 0;
    
    printf("Introdu n: "); 
    scanf("%d", &n);

    printf("Introdu x: "); 
    scanf("%f", &x);
    
    printf("Introdu y: "); 
    scanf("%f", &y);

    
    err(x < y, "%g nu este mai mic decat %g\n", x, y);
    max = x;
    min = y;

    for(i = 0; i < n; i++) {
        printf("Introdu e: ");
        scanf("%f", &e);

        err(!(e < x || e > y), "Elementul %g este invalid. Intervalul corect este (%g, %g)\n", e, x, y);
        
        if(e < min) min = e;
        if(e > max) max = e;
    }

    printf("Minim: %g, Maxim: %g\n", min, max);
    return 0;
}
