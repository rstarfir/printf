#include "includes/printf.h"
#include "stdio.h"
#include <limits.h>

#include <float.h>

int main(void)
{
    //printf("%.1f\n", 1.55);
    ft_printf("%f", 2.5);
    return (0);	
}

/*
    limits.h synopsis

Macros:

    CHAR_BIT
    SCHAR_MIN
    SCHAR_MAX
    UCHAR_MAX
    CHAR_MIN
    CHAR_MAX
    MB_LEN_MAX
    SHRT_MIN
    SHRT_MAX
    USHRT_MAX
    INT_MIN
    INT_MAX
    UINT_MAX
    LONG_MIN
    LONG_MAX
    ULONG_MAX
    LLONG_MIN   // C99
    LLONG_MAX   // C99
    ULLONG_MAX  // C99

*/