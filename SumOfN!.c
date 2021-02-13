#include <stdio.h>
#include <math.h>

int main() {
    const unsigned long n = 123;
    double digits = 0;
    unsigned i;
    for (i=1; i<=n; i++) {
        digits += log10(i);
    }
    printf("%lu", (unsigned long)digits+1);
}