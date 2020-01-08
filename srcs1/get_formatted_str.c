/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formatted_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:23:24 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/20 16:46:13 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char			*get_formatted_str_from_char(t_format *conv_params,
																va_list args)
{
	t_uchar		arg_val;
	char		*val_str;

	if (conv_params->flags & FL_ERR)
		arg_val = conv_params->type_char;
	else
		arg_val = (t_uchar)va_arg(args, int);
	if (!arg_val)
		conv_params->flags |= FL_NULL;
	if (!(val_str = ft_strcnew(1, arg_val)))
		return (NULL);
	if (conv_params->width > 1)
		if (!add_padding(&val_str, conv_params->width - 1, conv_params))
			return (ft_strdel_ret_null(&val_str));
	return (val_str);
}

char			*get_formatted_str_from_str(t_format *conv_params, va_list args)
{
	char		*val_str;
	int			padding;

	if (!(val_str = (char *)va_arg(args, char *)))
		val_str = ft_strdup("(null)");
	else
		val_str = ft_strdup(val_str);
	if (conv_params->flags & FL_PREC)
		if (!ft_strcut(&val_str, conv_params->prec))
			return (ft_strdel_ret_null(&val_str));
	if ((padding = conv_params->width - ft_strlen(val_str)) > 0)
		if (!add_padding(&val_str, padding, conv_params))
			return (ft_strdel_ret_null(&val_str));
	return (val_str);
}

char			*get_formatted_str(t_format *conv_params, va_list args)
{
	char		*val_str;

	val_str = NULL;
	if (ft_instr(conv_params->type_char, INT_TYPES))
		val_str = get_formatted_str_from_int(conv_params, args);
	else if (ft_instr(conv_params->type_char, DBL_TYPES))
		val_str = get_formatted_str_from_dbl(conv_params, args);
	else if (conv_params->type_char == 'c' || conv_params->flags & FL_ERR)
		val_str = get_formatted_str_from_char(conv_params, args);
	else if (conv_params->type_char == 's')
		val_str = get_formatted_str_from_str(conv_params, args);
	else if (!conv_params->type_char)
		val_str = ft_strnew(0);
	return (val_str);
}
