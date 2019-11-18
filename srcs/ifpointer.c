#include "../includes/printf.h"
#include <stdio.h>

void    ifpointer(t_parser *f, va_list ap)
{
    char *s;

    s = ft_itoabase((long long int)va_arg(ap, void *), 16);
    if (s)
    {
        f->nprinted += write(1, "0x", 2);
        f->nprinted += write(1, s, ft_strlen(s));
    }
}