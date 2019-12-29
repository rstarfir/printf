/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:57:31 by hthunder          #+#    #+#             */
/*   Updated: 2019/12/29 22:11:57 by rstarfir         ###   ########.fr       */
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

typedef struct		s_parser
{
	const char		*format;
	int				nprinted;
	int				i;
	int				flags[4]; //minus flag, first symbol flag(includes space flag), # flag, 0 flag;
	int				width; //минимальная ширина
	int				precision;
	long long		double_prec;
	int				size;
	long long int		int_part;
	char			*nonfr;
	char			*frac;
}					t_parser;

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
void	iffloat(t_parser *f, va_list ap);
long long int	acc_round(long double dou_n, long long int nbr);
void	outputthis(t_parser *f);
int 	ft_printf(const char *format, ...);
void	zerostruct(t_parser *f);
int 	ft_max(int one, int two);


#endif
