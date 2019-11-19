#include "../includes/printf.h"
#include <stdarg.h>
#include <limits.h>


void left_aligned_hex(t_parser *f, int length, char *s, char flag)
{
	int i;
	int b;

	i = 0;
	b = 0;
	if (f->flags[FSFL] != 0)
		i = 1;
	f->precision -= length;
	b = f->precision;
	if (f->flags[OFL] == 1 && flag == 'o')
		f->nprinted += write(1, "0", 1);
	else if (f->flags[OFL] == 1 && flag == 'x')
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

void right_aligned_hex(t_parser *f, int length, char *s, char flag)
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
	if (f->flags[OFL] == 1 && flag == 'o')
		f->nprinted += write(1, "0", 1);
	else if (f->flags[OFL] == 1 && flag == 'x')
		f->nprinted += write(1, "0x", 2);
	if (f->flags[OFL] == '#')
		f->nprinted += write(1, &f->flags[OFL], 1);
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

char    *ft_toupperstring(char *c)
{
    char *temp;

    temp = c;
    if (c)
    {
        while(*c)
        {
            if (*c > 96 && *c < 123)
		    *c = *c - 32;
            c++;
        }
	    return (temp);   
    }
    else 
        return (NULL);
	
}

void ifhex(t_parser *f, va_list ap, char c)
{
	unsigned int number;
	char *s;
	char flag;

	flag = 'x';
	if (f->size == 0)
		number = va_arg(ap, unsigned int);
	else if (f->size == H)
		number = (unsigned short)va_arg(ap, unsigned int);
	else if (f->size == HH)
		number = (unsigned char)va_arg(ap, unsigned int);
	else if (f->size == L)
		number = (unsigned long)va_arg(ap, unsigned int);
	else if (f->size == LL)
		number = (unsigned long long)va_arg(ap, unsigned int);
	//if (number < 0)
	//{
	//	f->flags[FSFL] = '-';
	//	number = number * -1;
	//}
    if (c == 'x')
	    s = ft_itoabase(number, 16);
    else if (c == 'X')
        s = ft_toupperstring(ft_itoabase(number, 16));
	if (f->flags[MFL] == 1)
		left_aligned_hex(f, ft_strlen(s), s, flag);
	else if (f->flags[MFL] == 0)
		right_aligned_hex(f, ft_strlen(s), s, flag);
	free(s);
}

void ifoctal(t_parser *f, va_list ap)
{
	unsigned int number;
	char *s;
	char flag;

	flag = 'o';
	if (f->size == 0)
		number = va_arg(ap, unsigned int);
	else if (f->size == H)
		number = (unsigned short)va_arg(ap, unsigned int);
	else if (f->size == HH)
		number = (unsigned char)va_arg(ap, unsigned int);
	else if (f->size == L)
		number = (unsigned long)va_arg(ap, unsigned int);
	else if (f->size == LL)
		number = (unsigned long long)va_arg(ap, unsigned int);
	//if (number < 0)
	//{
	//	f->flags[FSFL] = '-';
	//	number = number * -1;
	//}
	s = ft_itoabase(number, 8);
	if (f->flags[MFL] == 1)
		left_aligned_hex(f, ft_strlen(s), s, flag);
	else if (f->flags[MFL] == 0)
		right_aligned_hex(f, ft_strlen(s), s, flag);
	free(s);
}