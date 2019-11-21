#include "includes/printf.h"
#include "stdio.h"
#include <limits.h>

int main(void)
{
    //printf("{%3c}\n", 0);
    //ft_printf("{%3c}", 0);
    //printf("%.d, %.0d\n", 0, 0);
    ft_printf("%.d, %.0d\n", 0, 0);
    printf("%.d, %.0d\n", 0, 0);
    ft_printf("{%+03d}\n", 0);
    printf("{%+03d}", 0);
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