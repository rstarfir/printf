#include "printf.h"
#include <stdarg.h>


void left_aligned(t_parser *f, int length, char *s)
{
	f->nprinted += write(1, s, length);
	while (f->width > 0)
	{
		f->nprinted += write(1, " ", 1);
		f->width--;
	}
}

void ifint(t_parser *f, va_list ap)
{
	int number;
	char *s;

	if (f->size == 0)
		number = (int)va_arg(ap, int);
	if (number < 0)
	{
		f->flags[PFL] = '-';
		number = number * -1;
	}
	s = ft_itoabase(number, 10);
	if (f->flags[PFL] == '-')
		ft_putchar('-');	
	if (f->flags[MFL] == 1)
		left_aligned(f, ft_strlen(s), s);
	free(s);
}

