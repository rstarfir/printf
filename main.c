#include "includes/printf.h"
#include "stdio.h"
#include <limits.h>

int main(void)
{
    printf("%lu, %lu", 0ul, ULONG_MAX);


//INT_MAX;
//LONG_MAX;
    //printf("%d\n", printf("%"));
    //printf("%d\n", printf("%"));
    //printf("%d", ft_printf("%"));
    //printf("%d", printf("%"));
    //ft_printf("%p", &i);
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