/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_and_return_double.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:23:45 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/12 20:45:40 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*round_first_symbol(int *carry,
									char *dff, int exp, t_parser format)
{
	char		*cp;

	cp = exp + format.flprecision > 0 ? dff + exp + format.flprecision : dff;
	if (*(cp + 1) > '5' || (*(cp + 1) == '5'
							&& ft_strlen(dff) > format.flprecision + exp + 2))
	{
		if (*cp + 1 == 58)
			*carry = 1;
		*cp = (*cp - 48 + 1) % 10 + 48;
		if (dff != cp)
			--cp;
	}
	else if (dff[exp + format.flprecision + 1] == '5')
	{
		if (*cp + 1 == 58)
			*carry = 1;
		if (*cp == 49 || *cp == 51 || *cp == 53 || *cp == 55 || *cp == 57)
			*cp = (*cp - 48 + 1) % 10 + 48;
		if (dff != cp)
			--cp;
	}
	return (cp);
}

void			round_other_symbols(int *carry, int exp_prec_sum,
									char **copy, char **dff)
{
	while (*carry && (exp_prec_sum + 1 != 0) && (exp_prec_sum != 0))
	{
		if (*carry)
		{
			*carry = **copy + 1 == 58 ? 1 : 0;
			**copy = (**copy - 48 + 1) % 10 + 48;
			if (*copy == *dff)
				break ;
		}
		(*copy)--;
	}
	if (*carry)
		*dff = ft_strjoinf("1", *dff, 0, *dff);
}

char			*return_zero_prec_values(int exp, char *dff, int carry)
{
	char *temp;

	if (exp == 4932)
	{
		dff = ft_strjoinf(dff, "0", dff, 0);
		temp = ft_strndup(dff, exp + 1 + carry);
		free(dff);
		return (temp);
	}
	else if (exp > -1)
	{
		temp = ft_strndup(dff, exp + 1 + carry);
		free(dff);
		return (temp);
	}
	else
	{
		free(dff);
		return (ft_strdup("0"));
	}
}

char			*return_not_zero_prec_values(char *dff, int exp,
				int carry, t_parser *format)
{
	int		copylen;
	int		copyprec;
	int		copyexp;
	char	*fpart;
	char	*spart;

	copylen = ft_strlen(dff);
	copyprec = format->flprecision;
	copyexp = exp;
	while (copyprec-- > copylen - (exp + 1))
		dff = ft_strjoinf(dff, "0", dff, 0);
	while (++copyexp + carry < 0)
		dff = ft_strjoinf("0", dff, 0, dff);
	if (exp > -1)
	{
		spart = ft_strndup(dff + exp + 1, format->flprecision);
		fpart = ft_strndupf(dff, exp + 1 + carry);
		fpart = ft_strjoinf(fpart, ".", fpart, 0);
		return (ft_strjoinf(fpart, spart, fpart, spart));
	}
	else
	{
		spart = ft_strndupf(dff, format->flprecision);
		return (ft_strjoinf("0.", spart, 0, spart));
	}
}
