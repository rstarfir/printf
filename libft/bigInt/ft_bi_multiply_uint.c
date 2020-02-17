/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_multiply_uint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:41:07 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:00:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

t_bigint		*ft_bi_uint_mult(t_bigint *bi, t_uint nb)
{
	int			i;
	t_ulint		temp;
	t_bigint	result;

	result = (t_bigint){0, {0}};
	i = 0;
	while (i < (int)bi->length)
	{
		temp = (t_ulint)bi->blocks[i] * (t_ulint)nb;
		temp += result.blocks[i];
		result.blocks[i] = temp & 0xFFFFFFFF;
		temp >>= 32;
		if (temp != 0)
			result.blocks[i + 1] += (t_uint)temp;
		++i;
	}
	*bi = result;
	bi->length = ft_bigint_size(&result);
	return (bi);
}
