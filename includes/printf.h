/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:57:31 by hthunder          #+#    #+#             */
/*   Updated: 2019/12/08 21:46:16 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# define ALL "cspdiouxXfyb%#-+ .*0123456789hLljz"

/*
 * length field
 */

# define HH 1
# define LL 2
# define L 3
# define H 4
# define J 5
# define Z 6
# define UCL 7
# define CAP_L 8

/*
 * flags
 * unsigned int 32 bits
 * 000001 MFL
 * 000010 PFL
 * 000100 SFL
 * 001000 OFL
 * 010000 ZFL
 * 100000 NFL // NULL flag for floats
 */

# define MFL    0x1
# define PFL    0x2
# define SFL    0x4
# define OFL    0x8
# define ZFL    0x10
# define NFL    0x20

/*
 *
 */

typedef struct      s_dbl_parts{
    t_ullint        mantissa : 52;
    t_ullint		exponent : 11;
    t_uint			sign : 1;
}					t_dbl_parts;

typedef struct		s_ldbl_parts{
	t_ullint		mantissa : 63;
	t_ullint
};

typedef union       u_dbls{
    t_dbl           dbl;
    t_ldbl          ldbl;
    t_dbl_parts     dbl_parts;
    t_ldbl_parts    ldbl_parts;
}                   t_dbls;

/*
 * typedefs for classical types
 */

typedef short int               t_sint;
typedef unsigned short int      t_usint;
typedef unsigned int            t_uint;
typedef long int                t_lint;
typedef unsigned long int       t_ulint;
typedef long long int           t_llint;
typedef unsigned long long int  t_ullint;
typedef double					t_dbl;
typedef long double				t_ldbl;

typedef struct	s_parser
{
	const char	    *format;
	int			    nprinted;
	int			    i;
	//int			flags[4];
	unsigned int    flags;
	int             beforeNum;
	int			    width;
	int			    precision;
	int             flprecision;
	int			    size;
}				    t_parser;

char			*ft_itoabase_unsigned(t_llint num, int base);
void			modifiers(t_parser *f, va_list ap);
void			ifint (t_parser *f, va_list ap);
void			ifchar (t_parser *f, va_list ap);
void			ifhex (t_parser *f, va_list ap, char c);
void			ifpointer(t_parser *f, va_list ap);
void			ifstring(t_parser *f, va_list ap);
void			ifoctal(t_parser *f, va_list ap);
void			ifudecint(t_parser *f, va_list ap);
void			ifpercent(t_parser *f);
int				ft_printf(const char *format, ...);
t_llint         acc_round(double dou_n, t_llint number);
void			widthstar(t_parser *f, va_list ap);
int				ft_max(int one, int two);
int				ft_min(int one, int two);
char			*ft_llitoa(t_llint n);
char			*ft_toupperstring(char *c);

#endif
