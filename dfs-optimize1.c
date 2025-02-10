#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "common.h"

void dfs(const int);

int depth = 1;
int depth_position = 1 * N;
char m[N][N];
int maxgcd = 3;
int skip;
bool verbose = false;

int main(int argc, char **argv)
{
    int c;
    while ((c = getopt(argc, argv, "d:v")) != -1) {
        switch (c) {
        case 'd':
            depth = atoi(optarg);
            depth_position = depth * N;
            break;
        case 'v':
            verbose = true;
            break;
        }
    }

    init(m);

    skip = 1;
    printf("Skip %d:\n", skip);
    dfs(0);

    skip = 3;
    printf("Skip %d:\n", skip);
    dfs(0);

    skip = 4;
    printf("Skip %d:\n", skip);
    dfs(0);

    skip = 6;
    printf("Skip %d:\n", skip);
    dfs(0);

    skip = 7;
    printf("Skip %d:\n", skip);
    dfs(0);

    skip = 8;
    printf("Skip %d:\n", skip);
    dfs(0);

    skip = 9;
    printf("Skip %d:\n", skip);
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

    if (verbose && depth_position == position) {
        printf("Not solution: (current maxgcd = %d)\n", maxgcd);
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
        if (n == skip) {
            continue;
        }

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
