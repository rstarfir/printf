/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_prec_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:38:43 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/20 13:42:59 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*add_exponent_sign(char **val_str, int exponent,
														t_format *conv_params)
{
	char	*append;
	char	*nb_append;
	long	u_exponent;

	if (!(append = (exponent < 0) ? ft_strdup("e-") : ft_strdup("e+")))
		return (NULL);
	if (conv_params->type_char == 'E')
		ft_strupper(append);
	if (exponent > -10 && exponent < 10)
		if (!ft_strappend(&append, "0"))
			return (NULL);
	u_exponent = ft_abs(exponent);
	if (!(nb_append = ft_uimaxtoa_base(u_exponent, DEC_BASE)))
		return (ft_strdel_ret_null(&append));
	ft_strappend(&append, nb_append);
	ft_strdel(&nb_append);
	ft_strappend(val_str, append);
	ft_strdel(&append);
	return (*val_str);
}

char		*trim_zeros(char **val_str, int len)
{
	int		i;

	i = len;
	while (i && (*val_str)[i] == '0')
		--i;
	if ((*val_str)[i] == '.')
		--i;
	if (!ft_strcut(val_str, i + 1))
		return (NULL);
	return (*val_str);
}

char		*add_dbl_prec(char **val_str, char *frac_part,
													t_format *conv_params)
{
	char	*fraction;

	if (!(fraction = ft_strndup(frac_part, conv_params->prec)))
		return (NULL);
	ft_strappend(val_str, fraction);
	ft_strdel(&fraction);
	return (*val_str);
}
