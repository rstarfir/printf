#include "../includes/printf.h"

int ft_min(int one, int two)
{
	if (one < two)
	{
		if (one < 0)
			return (two);
		else
			return (one);
	}
	else
		return (two);
}

void left_aligned_str(t_parser *f, int length, char *s)
{
	int i;
	char k = ' ';
	int copy;
	int copy1;

	i = 0;
	copy = length;
	copy1 = f->precision;
	if (f->flags[FSFL] != 0)
		i = 1;
	if (f->flags[FSFL] == '-' && k == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	while (length-- > 0)
	{
		if (f->precision < 0)
			f->nprinted += write(1, s, 1);
		else if (f->precision > 0)
		{
			f->nprinted += write(1, s, 1);
			f->precision--;
		}
		s++;	
	}
	if ( f->flags[ZFL] == 1 && ((f->precision > f->width) || (f->precision == 1)) && (k = '0'))
		if (f->flags[FSFL] == '-')
			f->nprinted += write(1, &f->flags[FSFL], 1);
	while (f->width-- - ft_min(copy1, copy) - i > 0)
			f->nprinted += write(1, &k, 1);
}

void right_aligned_str(t_parser *f, int length, char *s)
{
	int i;
	char k;

	k = ' ';
	i = 0;
	if (f->flags[FSFL] != 0)
		i = 1;
	if ( f->flags[ZFL] == 1 && ((f->precision > f->width) || (f->precision == 1)) && (k = '0'))
		if (f->flags[FSFL] == '-')
			f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	while (f->width-- - ft_min(f->precision, length) - i > 0)
			f->nprinted += write(1, &k, 1);
	if (f->flags[FSFL] == '-' && k == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1); 					///// остальные сделать аналогично
	while (length-- > 0)
	{
		if (f->precision < 0)
			f->nprinted += write(1, s, 1);
		else if (f->precision > 0)
		{
			f->nprinted += write(1, s, 1);
			f->precision--;
		}
		s++;	
	}
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
	{
		if (f->flags[MFL] == 1)
		{
			f->flags[ZFL] = 0;
			left_aligned_str(f, ft_strlen(s), s);
		}
		else if (f->flags[MFL] == 0)
			right_aligned_str(f, ft_strlen(s), s);
	}
}

void left_alignedchar(t_parser *f, char c)
{
	int i;

	i = 0;
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, &c, 1);
	while(f->width - 1 - i > 0)
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