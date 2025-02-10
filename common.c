#include <stdio.h>
#include <string.h>

#include "common.h"

void dump(const char m[N][N])
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

void init(char m[N][N])
{
    // init
    memset(m, -1, sizeof(m[0][0]) * N * N);

    m[7][0] = 2;
    m[8][1] = 5;
    m[1][2] = 2;
    m[2][3] = 0;
    m[3][5] = 2;
    m[4][6] = 0;
    m[5][7] = 2;
    m[6][8] = 5;
}

int row2num(const char m[N][N], const int row)
{
    int base = 1;
    int num = 0;

    for (int i = N - 1; i >= 0; i--) {
        num += m[row][i] * base;
        base *= 10;
    }

    return num;
}

int rows2gcd(const char m[N][N], const int row)
{
    int gcdv = row2num(m, 0);
    for (int i = 1; i < row; i++) {
        gcdv = gcd(gcdv, row2num(m, i));
    }

    return gcdv;
}
