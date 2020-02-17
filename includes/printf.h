/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:57:31 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:00:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/includes/bigint.h"
# include "../libft/includes/libft.h"
# define ALL "cspdiouxXfFb%#-+ .*0123456789hLl"

# define HH			1
# define LL			2
# define L			3
# define H			4
# define UCL 		5

# define BUF_DIGITS_SIZE 10000

# define MFL    	0x1
# define PFL    	0x2
# define SFL		0x4
# define OFL		0x8
# define ZFL		0x10
# define NFL		0x20

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define RESET		"\x1b[0m"

# define RESETALL   "\033[0m"
# define BOLD       "\033[1m"
# define UNDERLINE  "\033[4m"
# define REVERSE    "\033[7m"

typedef struct		s_dbl_parts{
	t_ullint		mant : 52;
	t_ullint		exp : 11;
	t_uint			sign : 1;
}					t_dbl_parts;

typedef struct		s_ldbl_parts{
	t_ullint		mant : 63;
	t_ullint		mant_int : 1;
	t_uint			exp : 15;
	t_uint			sign : 1;
}					t_ldbl_parts;

typedef union		u_dbls{
	t_dbl			dbl;
	t_ldbl			ldbl;
	t_dbl_parts		dbl_parts;
	t_ldbl_parts	ldbl_parts;
}					t_dbls;

typedef struct		s_parser
{
	const char		*format;
	int				nprinted;
	int				i;
	unsigned int	flags;
	int				before_num;
	int				width;
	int				precision;
	int				flprecision;
	int				size;
}					t_parser;

char				*ft_itoabase_unsigned(t_ullint num, int base);
void				modifiers(t_parser *f, va_list ap);
void				ifint (t_parser *f, va_list ap);
void				ifbinary(t_parser *f, va_list ap);
void				ifchar (t_parser *f, va_list ap);
void				ifhex (t_parser *f, va_list ap, char c);
void				ifpointer(t_parser *f, va_list ap);
void				ifstring(t_parser *f, va_list ap);
void				ifoctal(t_parser *f, va_list ap);
void				ifudecint(t_parser *f, va_list ap);
void				ifpercent(t_parser *f);
void				iffloat(t_parser *format, va_list args);
char				*handle_zero(char *dff, t_parser *format);
int					is_max_exp(t_dbls *arg_val, t_parser *conv_params);
char				*format_inf_nan(t_dbls *arg_val, t_parser *conv_params);
char				*left_width_format_double(char *digits,
					t_parser *conv_params);
char				*right_width_format_double(char *digits,
					t_parser *conv_params);
void				dragon4(t_dbls *fl_number, char *digits,
					int *exponent, t_parser *conv_params);
char				*round_first_symbol(int *carry,
									char *dff, int exp, t_parser format);
void				round_other_symbols(int *carry, int exp_prec_sum,
									char **copy, char **dff);
char				*return_zero_prec_values(int exp, char *dff, int carry);
char				*return_not_zero_prec_values(char *dff, int exp,
					int carry, t_parser *format);
void				put_before_num_symb(char **digits, t_parser conv_params);
char				*right_width_format_double(char *digits,
					t_parser *conv_params);
char				*left_width_format_double(char *digits,
					t_parser *conv_params);
char				*add_point(char *digits, t_parser *conv_params);
int					ft_printf(const char *format, ...);
void				widthstar(t_parser *f, va_list ap);
int					ft_max(int one, int two);
int					ft_min(int one, int two);
char				*ft_llitoa(t_llint n);
char				*ft_toupperstring(char *c);
char				*ft_strjoinf(char *s1, char *s2,
					char *str_for_free1, char *str_for_free2);
char				*ft_strndupf(const char *s1, size_t n);
int					add_color(const char *str, t_parser *f);
int					utf8_encode(char *s, t_uint uni);

#endif
