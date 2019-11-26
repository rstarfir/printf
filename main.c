#include "includes/printf.h"
#include "stdio.h"
#include <limits.h>

int main(void)
{
    printf("@moulitest: %05.x %05.0x\n", 0, 0);
    ft_printf("@moulitest: %05.x %05.0x", 0, 0);
    //printf("@moulitest: %5x %5x\n", 0, 0);
    //ft_printf("@moulitest: %5x %5x", 0, 0);
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