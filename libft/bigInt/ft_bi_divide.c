/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_divide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:39:58 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:00:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int				ft_bigint_divide(t_bigint *dividend, t_bigint *divisor)
{
	int			k;
	int			comp;
	t_bigint	result;

	k = 0;
	while (k < 10)
	{
		result = *divisor;
		ft_bi_uint_mult(&result, k);
		comp = ft_bigint_comp(dividend, &result);
		if (comp == 0)
			return (k);
		else if (comp < 0)
			return (k - 1);
		++k;
	}
	return (9);
}
