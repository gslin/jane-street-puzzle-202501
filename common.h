#ifndef _COMMON_H
#define _COMMON_H

#define N 9
#define MAXV 10

void dump(const char [N][N]);
int gcd(int, int);
void init(char [N][N]);
int row2gcd(const char [N][N], const int);
int row2num(const char [N][N], const int);

#endif
