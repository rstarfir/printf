#include "../includes/printf.h"

void left_aligned_str(t_parser *f, int length, char *s)
{
	char k = ' ';
	int copylen;
	int copyprec;

	copylen = length;
	copyprec = f->precision;
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
	if ( f->flags[ZFL] == 1 && ((f->precision > f->width) || (f->precision == -1)) && (k = '0'))
		if (f->flags[FSFL] == '-')
			f->nprinted += write(1, &f->flags[FSFL], 1);
	while (f->width-- - ft_min(copyprec, copylen) > 0)
			f->nprinted += write(1, &k, 1);
}

void right_aligned_str(t_parser *f, int length, char *s)
{
	char k;

	k = ' ';
	if ( f->flags[ZFL] == 1 && ((f->precision > f->width) || (f->precision == -1)) && (k = '0'))
		if (f->flags[FSFL] == '-')
			f->nprinted += write(1, &f->flags[FSFL], 1);
	if (f->flags[FSFL] == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1);
	while (f->width-- - ft_min(f->precision, length) > 0)
			f->nprinted += write(1, &k, 1);
	if (f->flags[FSFL] == '-' && k == ' ')
		f->nprinted += write(1, &f->flags[FSFL], 1); 					///// остальные сделать аналогично
	while (length-- > 0)
	{
		if (f->precision < 0)
		{
			f->nprinted += write(1, s, 1);
			s++;
		}
		else if (f->precision > 0)
		{
			f->nprinted += write(1, s, 1);
			f->precision--;
			s++;	
		}
	}
}

void    ifstring(t_parser *f, va_list ap)
{
    char *s;
	int flag = 0;
    s = (char *)va_arg(ap, char *);
    if(!s)
	{
        s = ft_strdup("(null)");
		flag = 1;
	}
	//if (f->flags[FSFL] == '+')
	//	f->flags[ZFL] = 0; // flag ' ' is ignored when flag '+' is present [-Wformat]
	if (f->flags[MFL] == 1)
	{
		f->flags[ZFL] = 0; //flag '0' is ignored when flag '-' is present [-Wformat]
		left_aligned_str(f, ft_strlen(s), s);
	}
	else if (f->flags[MFL] == 0)
		right_aligned_str(f, ft_strlen(s), s);
	if (flag == 1)
		free(s);
}