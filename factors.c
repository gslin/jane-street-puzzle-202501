#include "common.h"

char m[N][N];

int main(int argc, char **argv)
{
    init(m);

    /**
     * We want to use a simple property for the 9x9 puzzle:
     *
     * Due to all digits will appear only once, the sum of all rows is a
     * fixed number when skip number is fixed.
     *
     * For example, when skip 0 (i.e. standard sudoku), we have an example:
     *
     * 10^8 10^7 10^6 10^5 10^4 10^3 10^2 10^1 10^0
     *
     *    1    2    3    4    5    6    7    8    9 = 123456789 = a1*gcd
     *    2    3    4    5    6    7    8    9    1 = 234567891 = a2*gcd
     *    3    4    5    6    7    8    9    1    2 = 345678912 = a3*gcd
     *    4    5    6    7    8    9    1    2    3 = 456789123 = a4*gcd
     *    5    6    7    8    9    1    2    3    4 = 567891234 = a5*gcd
     *    6    7    8    9    1    2    3    4    5 = 678912345 = a6*gcd
     *    7    8    9    1    2    3    4    5    6 = 789123456 = a7*gcd
     *    8    9    1    2    3    4    5    6    7 = 891234567 = a8*gcd
     *    9    1    2    3    4    5    6    7    8 = 912345678 = a9*gcd
     *
     * Since 1+2+3+4+5+6+7+8+9=45, the sum will always be 45*111111111.
     *
     * If skip is 1, then the sum will always be (45-1)*111111111.
     * If skip is 2, then the sum will always be (45-2)*111111111.
     *                          :
     * If skip is 9, then the sum will always be (45-9)*111111111.
     *
     * Apparent GCD is always the factor of (45-n)*111111111.
     *
     * And 111,111,111 this number is quite interesting, its prime factors
     * are: 3^2 * 37 * 333679.
     *
     * So actually the possibility of GCD is quite limited, we can list
     * all and enumerate them desending, and the first one is the answer.
     */

    /**
     * Another property in 9x9 puzzle is:
     *
     * All GCD are odd, because if any GCD is even, it means the last
     * digit for each row is even, but we have only 5 even digits and we
     * have 9 slots.
     *
     * For the same reason, the last digit of GCD cannot be 0 and 5:
     * is' trival if the last digit of GCD is 0, then the last digit of
     * each rows is 0.  And if the last digit of GCD is 5, then the last
     * digit of all rows are either 5 or 0.  Both cannot form a valid
     * puzzie.
     */
}
