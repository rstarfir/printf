#include "includes/printf.h"
#include "stdio.h"
#include <limits.h>

int main(void)
{
    int i;
    i = 5;
    //printf("{%}");
    //printf("{% %}");
    printf("{% 5%}");
    //ft_printf("%p", &i);
    return (0);
}
/*
static void percentAlone(t_test *test)
{
    // test->debug = 1;
    assert_printf("{%}");
}


static void multiplePercent(t_test *test)
{
    // test->debug = 1;
    assert_printf("{% %}");
}
*/

//04_conv_p.spec.c ------------ [FAIL] FFFFF [FAIL] test_int_pointer -> printf("%p", &i)
