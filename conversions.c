#include "printf.h"
#include <stdarg.h>


void left_aligned(t_parser *f, int length, char *s)
{
	//ft_putstr("privet");
	f->nprinted += write(1, s, length);
	while (f->width > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
	//ft_putstr(s);

}

void newfunc(int n, t_parser *f)
{
	char *s;

	s = ft_itoabase(n, 10);
	//ft_putstr(s);	
	//ft_putstr("was here");
	if(f->flags[MFL] == 1)
		left_aligned(f, ft_strlen(s), s);
	free (s);	
}

void ifint(t_parser *f, va_list ap)
{
	int n;
	//ft_putstr("debug");
	//ft_putnbr(f->size);
	if (f->size == 0)
		n = (int)va_arg(ap, int);
	//ft_putnbr(n);
	//ft_putstr("was here");
	if (n < 0)
	{
		f->flags[PFL] == '-';
		n = n * -1;
	}

	newfunc(n, f);
}

