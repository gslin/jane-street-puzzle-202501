#include <stdio.h>

#include "common.h"

void dump(char m[N][N])
{
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            printf("%2d ", m[x][y]);
        }
        printf("\n");
    }
}

int gcd(int a, int b)
{
    if (1 == a || 1 == b) {
        return 1;
    }

    while (0 != b) {
        a %= b;

        // swap
        int t = a;
        a = b;
        b = t;
    }

    return a;
}

int row2num(char m[N][N], const int row)
{
    int base = 1;
    int num = 0;

    for (int i = N - 1; i >= 0; i--) {
        num += m[row][i] * base;
        base *= 10;
    }

    return num;
}
