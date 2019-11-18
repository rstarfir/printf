#include "printf.h"
#include <stdarg.h>


void left_aligned(t_parser *f, int length, char *s)
{
	int i;
	int b;

	i = 0;
	b = 0;
	if (f->flags[FSFL] != 0)
		i = 1;
	f->precision -= length;
	b = f->precision;
	if (f->flags[FSFL] == '-')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	else if (f->flags[FSFL] == '+')
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

void right_aligned(t_parser *f, int length, char *s)
{
	int i;

	i = 0;
	if (f->flags[FSFL] != 0)
		i = 1;
	f->precision -= length;
	while (f->width - f->precision - length - i > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
	if (f->flags[FSFL] == '-')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	else if (f->flags[FSFL] == '+')
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

void ifint(t_parser *f, va_list ap)
{
	int number;
	char *s;

	if (f->size == 0)
		number = (int)va_arg(ap, int);
	else if (f->size == H)
		number = (short)va_arg(ap, int);
	else if (f->size == HH)
		number = (signed char)va_arg(ap, int);
	else if (f->size == L)
		number = (long)va_arg(ap, int);
	else if (f->size == LL)
		number = (long long)va_arg(ap, int);
	if (number < 0)
	{
		f->flags[FSFL] = '-';
		number = number * -1;
	}
	s = ft_itoabase(number, 10);
	if (f->flags[MFL] == 1)
		left_aligned(f, ft_strlen(s), s);
	else if (f->flags[MFL] == 0)
		right_aligned(f, ft_strlen(s), s);
	free(s);
}

