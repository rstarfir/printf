#include "includes/printf.h"
#include "stdio.h"
#include <limits.h>

#include <float.h>

int main(void)
{
	t_double d;

	d.x = -123.3;
	printf("%llx\n", d.s_field.m);
	printf("%d\n", d.s_field.e);
	printf("%x\n", d.s_field.s);
	printf("%.1000f\n", DBL_MIN);
    int i;
    i = 5;
    //printf("{%}");
    //printf("{% %}");
   // printf("%.10000000000000000000000f", 6.9999556);
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
