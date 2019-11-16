/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:57:31 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/15 21:28:09 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/includes/libft.h"
# define ALLSYMBOLS "cspdiouxXfy%#-+.*0123456789hLljz"
# define MFL 0
# define PFL 1
# define OFL 2
# define ZFL 3

# define HH 1
# define LL 2
# define L 3
# define H 4
# define J 5
# define Z 6

typedef struct  s_parser
{
	const char  *format;
	int			nprinted;
	int			i;
	int			flags[4]; //minus flag, plus flag(includes space flag):'+', '-', ' ' or 0, # flag, 0 flag;
	int			width; //минимальная ширина
	int			precision;
	int			size;//а здесь ничего не указывать?
}               t_parser;

char	*ft_itoabase(long int num, int base);
void	modifiers(t_parser *f, va_list ap);
void	conversions(char c, va_list ap, t_parser *f);
void	ifint (t_parser *f, va_list ap);

#endif
