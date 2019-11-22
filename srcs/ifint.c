#include "../includes/printf.h"
#include <stdarg.h>


int ft_max(int one, int two)
{
	if (one >= two)
		return (one);
	else
		return (two);
}
void left_aligned(t_parser *f, int length, char *s)
{
	int i;
	char k = ' ';

	i = 0;

	if (f->flags[FSFL] != 0)
		i = 1;
	if (f->flags[FSFL] == '-')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == '+')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (*s != '0' || (f->precision != 0 && f->precision != -1))
		f->nprinted += write(1, s, length);
	if (f->flags[ZFL] == 1)
	{
		k = '0';
		if (f->flags[FSFL] == '-')
			f->nprinted += write(1, &f->flags[FSFL], 1);
	}
	while (f->width-- - ft_max(f->precision, length) - i > 0)
		f->nprinted += write(1, &k, 1);
}


void right_aligned(t_parser *f, int length, char *s)
{
	int i;
	char k;

	k = ' ';
	i = 0;
	if (f->flags[FSFL] != 0)
		i = 1;
	if (f->flags[FSFL] == '+')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if ( f->flags[ZFL] == 1 && ((f->precision > f->width) || (f->precision == -2)) && (k = '0'))
		if (f->flags[FSFL] == '-')
			f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	while (f->width-- - ft_max(f->precision, length) - i > 0)
		f->nprinted += write(1, &k, 1);
	if (f->flags[FSFL] == '-' && k == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1); 					///// остальные сделать аналогично
	while (f->precision > length)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	if (*s != '0' || (f->precision != 0 && f->precision != -1))
		f->nprinted += write(1, s, length);
}

void ifint(t_parser *f, va_list ap)
{
	long long int number;
	char *s;

	if (f->size == 0)
		number = (int)va_arg(ap, int);
	else if (f->size == H)
		number = (short)va_arg(ap, int);
	else if (f->size == HH)
		number = (signed char)va_arg(ap, int);
	else if (f->size == L)
		number = (long int)va_arg(ap, long int);
	else if (f->size == LL)
		number = (long long int)va_arg(ap, long long int);
	if (number == LLONG_MIN)
	{
		f->nprinted += write(1, "-9223372036854775808", 20);
		return ;
	}
	if (number < 0)
	{
		number *= -1;
		f->flags[FSFL] = '-';
	}
	s = ft_itoabase(number, 10);
	if (f->flags[MFL] == 1)
	{
		f->flags[ZFL] = 0;
		left_aligned(f, ft_strlen(s), s);
	}
	else if (f->flags[MFL] == 0)
		right_aligned(f, ft_strlen(s), s);
	free(s);
}

void ifudecint(t_parser *f, va_list ap)
{
	unsigned long long int number;
	char *s;

	if (f->size == 0)
		number = va_arg(ap, unsigned int);
	else if (f->size == H)
		number = (unsigned short)va_arg(ap, unsigned int);
	else if (f->size == HH)
		number = (unsigned char)va_arg(ap, unsigned int);
	else if (f->size == L)
		number = (unsigned long int)va_arg(ap, unsigned long int);
	else if (f->size == LL)
		number = (unsigned long long int)va_arg(ap, unsigned long long int);
	s = ft_itoabase_unsigned(number, 10);
	if (f->flags[MFL] == 1)
	{
		f->flags[ZFL] = 0;
		left_aligned(f, ft_strlen(s), s);
	}
	else if (f->flags[MFL] == 0)
		right_aligned(f, ft_strlen(s), s);
	free(s); 
}
