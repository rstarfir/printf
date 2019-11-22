/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:57:31 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/22 13:37:55 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# define ALLSYMBOLS "cspdiouxXfyb%#-+ .*0123456789hLljz"
# define MFL 0
# define FSFL 1 // first symbol flag '+', ' ' or nothing before number;
# define OFL 2
# define ZFL 3

# define HH 1
# define LL 2
# define L 3
# define H 4
# define J 5
# define Z 6
# define UCL 7

typedef struct  s_parser
{
	const char  *format;
	int			nprinted;
	int			i;
	int			flags[4]; //minus flag, first symbol flag(includes space flag), # flag, 0 flag;
	int			width; //минимальная ширина
	int			precision;
	int			size;
}               t_parser;

/*
** union struct for double: mantissa(52bit), exponent(11bit), sign(1bit) 
*/
#include <stdint.h>

typedef union	u_double
{
	double		x;
	struct
	{
		long long	m : 52;
		unsigned	e : 11;
		int			s : 1;
	}			s_field;
}				t_double;

char	*ft_itoabase(long long int num, int base);
char	*ft_itoabase_unsigned(long long int num, int base);
void	modifiers(t_parser *f, va_list ap);
void	conversions(char c, va_list ap, t_parser *f);
void	ifint (t_parser *f, va_list ap);
void	ifchar (t_parser *f, va_list ap);
void	ifhex (t_parser *f, va_list ap, char c);
void    ifpointer(t_parser *f, va_list ap);
void	ifstring(t_parser *f, va_list ap);
void 	ifoctal(t_parser *f, va_list ap);
void 	ifudecint(t_parser *f, va_list ap);
void	ifpercent(t_parser *f);
void	iffloat (t_parser *f, va_list ap);
int 	ft_printf(const char *format, ...);
void	zerostruct(t_parser *f);
int 	ft_max(int one, int two);


#endif
