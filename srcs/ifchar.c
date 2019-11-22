#include "../includes/printf.h"

int ft_min(int one, int two)
{
	if (one <= two)
	{
		if (one < 0)
			return (one * 0);
		else
			return (one);
	}
	else
	{
		if (two < 0)
			return (two * 0);
		else
			return (two);
	}
}

void left_aligned_str(t_parser *f, int length, char *s)
{
	int i;
	//int b;
	char k = ' ';

	i = 0;
	//b = 0;

	if (f->flags[FSFL] != 0)
		i = 1;
	f->precision -= length;
	//if (f->precision < 0)
    //    f->precision = 0;
	//b = f->precision;
	if (f->flags[FSFL] == '-')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == '+')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
		while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	//printf("i'm here");
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
	if (f->precision == -2)
		while (f->width-- - length - i > 0)
			f->nprinted += write(1, &k, 1);
	else
		while (f->width-- - ft_min(f->precision, length) - i > 0)
			f->nprinted += write(1, &k, 1);
	if (f->flags[FSFL] == '-' && k == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1); 					///// остальные сделать аналогично
	while (length-- > 0)
	{
		//if (f->precision == -1)
		//	f->nprinted += write(1, s, 1);
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
        //f->nprinted += write(1, s, ft_strlen(s));
}

void left_alignedchar(t_parser *f, char c)
{
	int i;
	//int b;

	i = 0;
	//f->precision -= 1;
	//b = f->precision;
	while (f->precision > 0)
	{
		f->nprinted += write(1, "0", 1);
		f->precision--;
	}
	f->nprinted += write(1, &c, 1);
	//printf("%d %d", f->width, i);
	//while (f->width - b - 1 - i > 0)
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