/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:18:13 by jkettani          #+#    #+#             */
/*   Updated: 2019/12/09 21:30:00 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <stdarg.h>: variable argument lists
** <unistd.h>: standard file descriptor macros, write syscall
** "libft.h": ft_strdel
** "format_parser.h": parse_fmt
*/

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static int		ft_vasprintf(char **str, const char *fmt, va_list args)
{
	t_format	conv_params;
	t_worker	work;

	work = (t_worker){NULL, {0}, 0, 0};
	while (*fmt)
		if (parse_fmt(&work, &conv_params, &fmt, args) < 0)
			return (ft_strdel_ret(&work.str, EXIT_FAIL));
	if (save_buf(&work) < 0)
		return (ft_strdel_ret(&work.str, EXIT_FAIL));
	*str = work.str;
	return (work.count);
}

static int		ft_vdprintf(int fd, const char *restrict fmt, va_list args)
{
	char		*str;
	int			count;
	int			ret;

	str = NULL;
	if ((count = ft_vasprintf(&str, fmt, args)) < 0)
		return (EXIT_FAIL);
	ret = write(fd, str, count);
	ft_strdel(&str);
	return (ret);
}

int				ft_printf(const char *restrict fmt, ...)
{
	va_list		args;
	int			count;

	va_start(args, fmt);
	count = ft_vdprintf(STDOUT_FILENO, fmt, args);
	va_end(args);
	return (count);
}

int				ft_dprintf(int fd, const char *restrict fmt, ...)
{
	va_list		args;
	int			count;

	va_start(args, fmt);
	count = ft_vdprintf(fd, fmt, args);
	va_end(args);
	return (count);
}

int				ft_asprintf(char **str, const char *fmt, ...)
{
	va_list		args;
	int			count;

	va_start(args, fmt);
	count = ft_vasprintf(str, fmt, args);
	va_end(args);
	return (count);
}
