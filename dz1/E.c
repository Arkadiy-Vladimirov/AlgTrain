#include <stdio.h>

/*
    problem:
    P - perimeter.
    find side length of triangle with perimeter P, which has
        - the minimum area
        - the maximum area.
    all quantities are integer.

    idea:
        the "smallest" triangle is the most narrow one
        the "largest" is the widest one.

    realization:
        to obtain the smallest area one side has to be very short.
        That means one side = 1 (if P = 1 (mod 2)) or 2 (otherwise). The others are equal.

        to obtain the largest area the sides have to be close to equal.
        That means each side = P div 3 (mb + 1)

    NOTE!:
        triangle with integer sides does not exist when
        P = 4 or P < 3.

*/

int main(int argc, char** argv) {

    int P;
    scanf("%d",&P);

    if ((P == 4) || (P < 3)) {
        printf("%d\n", -1);
        return 0;
    }

    //the largest one
    switch (P % 3) {

    case 0:
        printf("%d %d %d\n", P/3, P/3, P/3);
        break;
    case 1:
        printf("%d %d %d\n", P/3, P/3, P/3 + 1);
        break;
    case 2:
        printf("%d %d %d\n", P/3, P/3 + 1, P/3 + 1);
        break;
    default:
        break;
    }

    //the smallest
    switch (P%2) {

    case 0:
        printf("%d %d %d\n", 2, (P-2)/2, (P-2)/2);
        break;
    case 1:
        printf("%d %d %d\n", 1, (P-1)/2, (P-1)/2);
        break;
    default:
        break;
    }

    return 0;
}