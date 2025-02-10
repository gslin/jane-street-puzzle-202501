#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "common.h"

void dfs(const int);

char m[N][N];
int maxgcd = 1;

int main()
{
    // init
    memset(m, -1, sizeof(m));

    m[7][0] = 2;
    m[8][1] = 5;
    m[1][2] = 2;
    m[2][3] = 0;
    m[3][5] = 2;
    m[4][6] = 0;
    m[5][7] = 2;
    m[6][8] = 5;

    dfs(0);
}

void dfs(const int position)
{
    // Valid case.
    if (N * N == position) {
        int gcdv = row2num(m, 0);
        for (int i = 1; i < N; i++) {
            gcdv = gcd(gcdv, row2num(m, i));
        }

        if (gcdv > maxgcd) {
            maxgcd = gcdv;
            printf("Solution:\n");
            dump(m);
            printf("gcd = %d\n", gcdv);
        }

        return;
    }

    const int x = position % N;
    const int y = position / N;

    if (0 == x && y > 0) {
        int gcdv = row2num(m, 0);
        for (int i = 1; i < y; i++) {
            gcdv = gcd(gcdv, row2num(m, i));
        }

        if (gcdv <= maxgcd) {
            return;
        }
    }

    if (N * 3 == position) {
        printf("Not solution:\n");
        dump(m);
    }

    // Fixed value.
    if (m[x][y] >= 0) {
        dfs(position + 1);
        return;
    }

    const int block_x = x - x % 3;
    const int block_y = y - y % 3;

    for (int n = 0; n < MAXV; n++) {
        // Check whether `n` is used in x-axis and y-axis.
        bool used = false;

        for (int i = 0; i < N; i++) {
            if (n == m[x][i] || n == m[i][y]) {
                used = true;
                break;
            }
        }

        if (used) {
            continue;
        }

        used = false;

        // Check whether `n` is used in 3x3 block.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == x && j == y) {
                    continue;
                }

                if (m[block_x + i][block_y + j] == n) {
                    used = true;
                    break;
                }
            }

            if (used) {
                break;
            }
        }

        if (used) {
            continue;
        }

        m[x][y] = n;
        dfs(position + 1);
    }
    m[x][y] = -1;
}
