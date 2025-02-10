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

    m[0][7] = 2;
    m[1][8] = 5;
    m[2][1] = 2;
    m[3][2] = 0;
    m[5][3] = 2;
    m[6][4] = 0;
    m[7][5] = 2;
    m[8][6] = 5;

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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", m[i][j]);
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
