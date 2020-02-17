/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_multiply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:40:28 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:00:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

t_bigint		ft_bigint_multiply(t_bigint *bi1, t_bigint *bi2, t_ulint temp)
{
	int			i;
	int			j;
	t_bigint	result;

	j = -1;
	result = (t_bigint){0, {0}};
	while (++j < (int)bi2->length)
	{
		i = -1;
		while (++i < (int)bi1->length)
		{
			temp = (t_ulint)bi1->blocks[i] * (t_ulint)bi2->blocks[j] + temp;
			temp += result.blocks[i + j];
			result.blocks[i + j] = temp & 0xFFFFFFFF;
			temp >>= 32;
		}
		if (temp != 0)
		{
			result.blocks[i + j] += (t_uint)temp;
			temp = 0;
		}
	}
	result.length = ft_bigint_size(&result);
	return (result);
}
