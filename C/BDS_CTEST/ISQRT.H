/* Source: https://en.wikipedia.org/wiki/Integer_square_root#Linear_search_using_addition 
Finds the floored square root of y*/
unsigned isqrt(y)
unsigned y;
{
    unsigned L;
    unsigned a;
    unsigned d;

    L = 0;
    a = 1;
    d = 3;

    while (a <= y)
    {
        a = a + d;
        d = d + 2;
        L = L + 1;
    }

    return L;
}

