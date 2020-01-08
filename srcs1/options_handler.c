/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:19:34 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/20 13:53:41 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int			check_formatting_option(t_worker *work, const char **fmt,
						const t_option_format *options_tbl)
{
	char			*option_val;
	size_t			i;
	int				j;

	i = 0;
	while ((*fmt)[i] && (*fmt)[i] != '}')
		++i;
	option_val = ft_strndup(*fmt, i + 1);
	j = 0;
	while (options_tbl[j].name)
	{
		if (!ft_strcmp(options_tbl[j].name, option_val))
		{
			if (add_to_buff(work, options_tbl[j].ansi_code,
						ft_strlen(options_tbl[j].ansi_code)) < 0)
				return (ft_strdel_ret(&option_val, EXIT_FAIL));
			*fmt = (*fmt + i) ? *fmt + i + 1 : *fmt + i;
			return (ft_strdel_ret(&option_val, EXIT_SUCCESS));
		}
		++j;
	}
	if (add_to_buff(work, "{", 1) < 0)
		return (ft_strdel_ret(&option_val, EXIT_FAIL));
	++(*fmt);
	return (ft_strdel_ret(&option_val, EXIT_SUCCESS));
}

int					formatting_handler(t_worker *work, const char **fmt)
{
	const t_option_format	options_tbl[] = {{STR_BOLD, BOLD}, {STR_DIM, DIM},
						{STR_ITALIC, ITALIC}, {STR_UNDERLINE, UNDERLINE},
						{STR_BLACK, C_BLACK}, {STR_RED, C_RED},
						{STR_GREEN, C_GREEN}, {STR_YELLOW, C_YELLOW},
						{STR_BLUE, C_BLUE}, {STR_MAGENTA, C_MAGENTA},
						{STR_CYAN, C_CYAN}, {STR_WHITE, C_WHITE},
						{STR_BG_BLACK, BG_BLACK}, {STR_BG_RED, BG_RED},
						{STR_BG_GREEN, BG_GREEN}, {STR_BG_YELLOW, BG_YELLOW},
						{STR_BG_BLUE, BG_BLUE}, {STR_BG_MAGENTA, BG_MAGENTA},
						{STR_BG_CYAN, BG_CYAN}, {STR_BG_WHITE, BG_WHITE},
						{STR_RESET, RESET}, {NULL, NULL}
	};

	return (check_formatting_option(work, fmt, options_tbl));
}
