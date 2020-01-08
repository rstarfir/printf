/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:18:38 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/25 11:02:19 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** stdarg.h: var_arg
** stdlib.h: intmax, uintmax
** sys/types.h: ssize_t
*/

# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>

/*
** Defines
*/

# define EXIT_FAIL          -1
# define EXIT_SUCCESS		0

# define BUF_SIZE			4096

# define BUF_DIGITS_SIZE    17000

# define TYPES             "dDiuUoOxXfFeEgGcspb"
# define SIGNED_TYPES      "difFeEgG"
# define FLAGS             "-+ 0#"
# define LEN_MODIFS        "hlLjz"
# define INT_TYPES         "douxXib"
# define DBL_TYPES         "fFeEgG"
# define TYPE_PREFIX       "xXb"

# define DOLLAR            '$'
# define ASTERISK          '*'
# define DOT               '.'
# define PERCENT           '%'
# define BRACE_OPEN        '{'

# define MINUS             '-'
# define PLUS              '+'
# define SPACE             ' '
# define HASH              '#'
# define ZERO              '0'

# define BIN_BASE          "01"
# define DEC_BASE          "0123456789"
# define OCT_BASE          "01234567"
# define L_HEX_BASE        "0123456789abcdef"
# define U_HEX_BASE        "0123456789ABCDEF"

# define PREF_OCT          "0"
# define PREF_L_HEX        "0x"
# define PREF_U_HEX        "0X"
# define PREF_BIN          "0b"

# define BOLD			   "\x1b[1m"
# define DIM               "\x1b[2m"
# define ITALIC            "\x1b[3m"
# define UNDERLINE		   "\x1b[4m"
# define C_BLACK		   "\x1b[30m"
# define C_RED			   "\x1b[31m"
# define C_GREEN		   "\x1b[32m"
# define C_YELLOW		   "\x1b[33m"
# define C_BLUE		       "\x1b[34m"
# define C_MAGENTA		   "\x1b[35m"
# define C_CYAN		       "\x1b[36m"
# define C_WHITE		   "\x1b[37m"
# define BG_BLACK		   "\x1b[40m"
# define BG_RED		       "\x1b[41m"
# define BG_GREEN		   "\x1b[42m"
# define BG_YELLOW		   "\x1b[43m"
# define BG_BLUE		   "\x1b[44m"
# define BG_MAGENTA	       "\x1b[45m"
# define BG_CYAN		   "\x1b[46m"
# define BG_WHITE		   "\x1b[47m"
# define RESET			   "\x1b[0m"

# define STR_BOLD		   "{bold}"
# define STR_DIM           "{dim}"
# define STR_ITALIC        "{italic}"
# define STR_UNDERLINE	   "{underline}"
# define STR_BLACK		   "{black}"
# define STR_RED		   "{red}"
# define STR_GREEN		   "{green}"
# define STR_YELLOW	       "{yellow}"
# define STR_BLUE		   "{blue}"
# define STR_MAGENTA	   "{magenta}"
# define STR_CYAN		   "{cyan}"
# define STR_WHITE		   "{white}"
# define STR_BG_BLACK	   "{black_bg}"
# define STR_BG_RED	       "{red_bg}"
# define STR_BG_GREEN	   "{green_bg}"
# define STR_BG_YELLOW	   "{yellow_bg}"
# define STR_BG_BLUE	   "{blue_bg}"
# define STR_BG_MAGENTA    "{magenta_bg}"
# define STR_BG_CYAN	   "{cyan_bg}"
# define STR_BG_WHITE	   "{white_bg}"
# define STR_RESET		   "{reset}"

/*
** Typedefs
*/

typedef char				t_char;
typedef	short				t_short;
typedef int					t_int;
typedef long int			t_lint;
typedef long long			t_llint;
typedef	unsigned char		t_uchar;
typedef unsigned short		t_ushort;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulint;
typedef unsigned long long	t_ullint;
typedef float				t_float;
typedef double				t_dbl;
typedef long double			t_ldbl;

typedef	struct				s_option_format{
	char					*name;
	char					*ansi_code;
}							t_option_format;

/*
** Union to store the different int types
*/

typedef union				u_ints{
	t_char					s_char;
	t_short					s_short;
	t_int					s_int;
	t_lint					s_lint;
	t_llint					s_llint;
	ssize_t					s_size_t;
	intmax_t				s_intmax;
	t_uchar					u_char;
	t_ushort				u_short;
	t_uint					u_int;
	t_ulint					u_lint;
	t_ullint				u_llint;
	size_t					u_size_t;
	uintmax_t				u_intmax;
}							t_ints;

/*
** Structure to store the different parts of a double. The element are in
** reverse order assuming little-endian format.
*/

typedef struct				s_dbl_parts{
    t_ullint				mantissa : 52;
    t_ullint				exponent : 11;
	t_ullint				sign : 1;
}							t_dbl_parts;

/*
** Structure to store the different parts of a long double (x86 extended
** precision format on 80 bits).
** The element are in reverse order assuming little-endian format.
*/

typedef struct				s_ldbl_parts{
	t_ullint				mantissa : 63;
	t_ullint				mantissa_int : 1;
	t_uint					exponent : 15;
	t_uint					sign : 1;
}							t_ldbl_parts;

/*
** Union to store the different double types and there constitutive parts in the
** exponent/mantissa format.
*/

typedef union				u_dbls{
	t_dbl					dbl;
	t_ldbl					ldbl;
	t_ulint					ulint;
	t_dbl_parts				dbl_parts;
	t_ldbl_parts			ldbl_parts;
}							t_dbls;

typedef enum				e_sign_type{
	UNSIGNED = 0x0,
	SIGNED = 0x1,
}							t_sign_type;

/*
 * FLAGS
 */

# define FL_MINUS 0x1
# define FL_PLUS 0x2
# define FL_SPACE 0x4
# define FL_HASH 0x8
# define FL_ZERO 0x10

enum						e_flags{
	FL_PREC = 0x20,
	FL_WIDTH = 0x40,
	FL_NULL = 0x80,
	FL_POINT = 0x100,
	FL_ERR = 0x200,
	FL_TRIM = 0x400
};

typedef enum				e_len_modifs{
	LEN_MOD_HH,
	LEN_MOD_H,
	LEN_MOD_L,
	LEN_MOD_LL,
	LEN_MOD_CAP_L,
	LEN_MOD_J,
	LEN_MOD_Z,
	LEN_MOD_NA
}							t_len_modifs;

typedef struct				s_format{
	char					type_char;
	int						is_neg;
	int						prec;
	int						width;
	t_uint					flags;
	t_len_modifs			len_mod;
	t_sign_type				is_signed;
}							t_format;

typedef struct				s_worker{
	char					*str;
	char					buf[BUF_SIZE];
	int						count;
	int						i;
}							t_worker;

int							ft_printf(const char *restrict fmt, ...);
int							ft_dprintf(int d, const char *restrict fmt, ...);
int							ft_asprintf(char **str, const char *fmt, ...);
const char                  *parse_conv_spec(const char *fmt, t_format *conv_params, va_list args);
const char                  *save_value_skip_digits(const char *fmt, t_format *conv_params);
const char                  *save_prec(const char *fmt, t_format *conv_params, va_list args);
void                        save_width(t_format *conv_params, va_list args);
char                        *reformat_digits_buf(char **digits, int *exponent, t_format *conv_params);
char                        *add_exponent_sign(char **val_str, int exponent, t_format *conv_params);
char                        *trim_zeros(char **val_str, int len);
char                        *add_dbl_prec(char **val_str, char *frac_part, t_format *conv_params);
void                        dragon4(t_dbls *arg_val, char *digits, int *exponent, t_format *conv_params);
char		                *get_formatted_str_from_dbl(t_format *conv_params, va_list args);
char		                *handle_dbl_limit_values(t_dbls *arg_val, t_format *conv_params);
char		                *handle_dbl_precision(char **digits, int exponent, t_format *conv_params);
void                        handle_g_conv_spec(int exponent, t_format *conv_params);
int                         is_limit_value(t_dbls *arg_val, t_format *conv_params);
int                         parse_fmt(t_worker *work, t_format *conv_params, const char **fmt, va_list args);
int				            add_to_buff(t_worker *work, char *val_str, int len);
int				            save_buf(t_worker *work);
int                         get_nb_zeros_prec_dbl(int nb_digits, t_format *conv_params);
char                        *prepend_prec(char **val_str, int nb_zeros_prec);
int                         has_sign(int nb_zeros_prec, t_format *conv_params);
char                        *prepend_sign(char **val_str, t_format *conv_params);
char                        *add_padding(char **val_str, int padding, t_format *conv_params);
char                        *get_formatted_str_from_char(t_format *conv_params, va_list args);
char                        *get_formatted_str_from__str(t_format *conv_params, va_list args);
char                        *get_formatted_str(t_format *conv_params, va_list args);
int                         get_nb_zeros_prec(int nb_digits, t_format *conv_params);
int                         has_prefix(t_format *conv_params);
char                        *prepend_prefix(char **val_str, t_format *conv_params);
char                        *int_arg_val_to_str(intmax_t arg_val, t_format *conv_params);
char                        *get_formatted_str_from_int(t_format *conv_params, va_list args);
int                         formatting_handler(t_worker *work, const char **fmt);

#endif
