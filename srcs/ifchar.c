#include "../includes/printf.h"


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

void left_alignedchar(t_parser *f, char c)
{
	int i;
	int b;

	i = 0;
	f->precision -= 1;
	b = f->precision;
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, &c, 1);
	while (f->width - b - 1 - i > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
}

void right_alignedchar(t_parser *f, char c)
{
	int i;

	i = 0;
	while (f->width - ft_max(f->precision, 1) - i > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
	f->precision -= 1;
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, &c, 1);
}

void    ifpercent(t_parser *f)
{
    char c;

    c = '%';
    if (f->flags[MFL] == 1)
		left_alignedchar(f, c);
	else if (f->flags[MFL] == 0)
		right_alignedchar(f, c);
}

void	ifchar (t_parser *f, va_list ap)
{
    char c;
    c = va_arg(ap, int);
    if (f->flags[MFL] == 1)
		left_alignedchar(f, c);
	else if (f->flags[MFL] == 0)
		right_alignedchar(f, c);
}