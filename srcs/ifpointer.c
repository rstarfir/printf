#include "../includes/printf.h"
#include <stdio.h>


void left_aligned_pointer(t_parser *f, int length, char *s)
{
	int i;
	int b;

	i = 2;
	b = 0;
	if (f->flags[FSFL] != 0)
		i ++;
    f->precision -= length;
	if (f->precision < 0)
        f->precision = 0;
	b = f->precision;
	if (f->flags[OFL] == 1)
		f->nprinted += write(1, "0x", 2);
	if (f->flags[FSFL] == '+')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	else if (f->flags[FSFL] == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
		while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, s, length);
	while (f->width - b - length - i > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
}

void right_aligned_pointer(t_parser *f, int length, char *s)
{
	int i;

	i = 2;
	if (f->flags[FSFL] != 0)
		i++;
	f->precision -= length;
	if (f->precision < 0)
        f->precision = 0;
    while (f->width - f->precision - length - i > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
	if (f->flags[OFL] == 1)
		f->nprinted += write(1, "0x", 2);
	if (f->flags[FSFL] == '+')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	else if (f->flags[FSFL] == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, s, length);
}

void    ifpointer(t_parser *f, va_list ap)
{
    char *s;
    unsigned long long int number;
    f->flags[OFL] = 1;
    //s = ft_itoabase((long long int)va_arg(ap, void *), 16);
    //if (s)
    //{
    //   f->nprinted += write(1, "0x", 2);
    //    f->nprinted += write(1, s, ft_strlen(s));
    //}
    number = (unsigned long long int)va_arg(ap, void *);
	s = ft_itoabase_unsigned(number, 16);
	if (f->flags[MFL] == 1)
		left_aligned_pointer(f, ft_strlen(s), s);
	else if (f->flags[MFL] == 0)
		right_aligned_pointer(f, ft_strlen(s), s);
}