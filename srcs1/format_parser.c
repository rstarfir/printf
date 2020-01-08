/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:27:15 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/20 15:32:37 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		build_final_str(t_worker *work, char *append, int len)
{
	char		*tmp;

	if (!work->str)
	{
		if (!(tmp = (char *)ft_memjoin("", 0, append, len)))
			return (EXIT_FAIL);
	}
	else
	{
		if (!(tmp = (char	*)ft_memjoin(work->str, work->count, append, len)))
			return (EXIT_FAIL);
	}
	ft_strdel(&work->str);
	work->str = tmp;
	work->count += len;
	return (EXIT_SUCCESS);
}

int				save_buf(t_worker *work)
{
	if (build_final_str(work, work->buf, work->i) < 0)
		return (EXIT_FAIL);
	work->i = 0;
	return (EXIT_SUCCESS);
}

int				add_to_buff(t_worker *work, char *val_str, int len)
{
	int			i;

	if (!val_str)
		return (EXIT_FAIL);
	if (len > BUF_SIZE || (work->i + len > BUF_SIZE))
		if (save_buf(work) < 0)
			return (EXIT_FAIL);
	if (len > BUF_SIZE)
	{
		if (build_final_str(work, val_str, len) < 0)
			return (EXIT_FAIL);
	}
	else
	{
		i = 0;
		while (len--)
			work->buf[(work->i)++] = val_str[i++];
	}
	return (EXIT_SUCCESS);
}

static int		conv_handler(t_worker *work, const char **fmt, va_list args,
								t_format *conv_params)
{
	char		*formatted_str;
	char		*tmp;
	int			len;

	*conv_params = (t_format){0, 0, 0, 0, 0u, LEN_MOD_NA, UNSIGNED};
	*fmt = parse_conv_spec(*fmt + 1, conv_params, args);
	if (!(formatted_str = get_formatted_str(conv_params, args)))
		return (EXIT_FAIL);
	if ((conv_params->type_char == 'c') && (conv_params->flags & FL_NULL)
			&& (conv_params->flags & FL_MINUS))
	{
		if (!(tmp = ft_strnew(1)))
			return (ft_strdel_ret(&formatted_str, EXIT_FAIL));
		if (add_to_buff(work, tmp, 1) < 0)
			return (ft_strdel_ret(&formatted_str, EXIT_FAIL));
	}
	len = ft_strlen(formatted_str);
	if ((conv_params->type_char == 'c') && (conv_params->flags & FL_NULL)
			&& !(conv_params->flags & FL_MINUS))
		len++;
	if (add_to_buff(work, formatted_str, len) < 0)
		return (ft_strdel_ret(&formatted_str, EXIT_FAIL));
	return (ft_strdel_ret(&formatted_str, EXIT_SUCCESS));
}

int				parse_fmt(t_worker *work, t_format *conv_params,
										const char **fmt, va_list args)
{
	if (work->i > BUF_SIZE - 1)
		if (save_buf(work) < 0)
			return (ft_strdel_ret(&work->str, EXIT_FAIL));
	if (**fmt == PERCENT)
	{
		if (conv_handler(work, fmt, args, conv_params) < 0)
			return (ft_strdel_ret(&work->str, EXIT_FAIL));
	}
	else if (**fmt == BRACE_OPEN)
	{
		if (formatting_handler(work, fmt) < 0)
			return (ft_strdel_ret(&work->str, EXIT_FAIL));
	}
	else
	{
		work->buf[work->i++] = **fmt;
		(*fmt)++;
	}
	return (EXIT_SUCCESS);
}
