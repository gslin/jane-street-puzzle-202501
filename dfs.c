#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXV 10
#define N 9

void dfs(const int);
void dump();
int gcd(int, int);
int row2num(const int);

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
        int gcdv = row2num(0);
        for (int i = 1; i < N; i++) {
            gcdv = gcd(gcdv, row2num(i));
        }

        if (gcdv > maxgcd) {
            maxgcd = gcdv;
            printf("Solution:\n");
            dump();
            printf("gcd = %d\n", gcdv);
        }

        return;
    }

    const int x = position % N;
    const int y = position / N;

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

void dump()
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

int row2num(const int row)
{
    int base = 1;
    int num = 0;

    for (int i = N - 1; i >= 0; i--) {
        num += m[row][i] * base;
        base *= 10;
    }

    return num;
}
