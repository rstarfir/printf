#include "../includes/printf.h"

void	ifchar (t_parser *f, va_list ap)
{
    char c;
    c = va_arg(ap, int);
    f->nprinted += write(1, &c, 1);
}

void    ifstring(t_parser *f, va_list ap)
{
    char *s;
    s = (char *)va_arg(ap, char *);
    if (!s || s == 0)
    {
        f->nprinted += 6;
        write(1, "(null)", 6);
    }
    else
        f->nprinted += write(1, s, ft_strlen(s));
}

void    ifpercent(t_parser *f)
{
    f->nprinted++;
    ft_putchar('%');
}