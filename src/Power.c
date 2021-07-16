#include "stdio.h"

double power(double x, unsigned y) {
    double res = x;
    unsigned i;
    for (i = 1; i<y; i++) res *= x;
    return res;
}

int main() {
    printf("%f", power(2, 3));
    return 0;
}
