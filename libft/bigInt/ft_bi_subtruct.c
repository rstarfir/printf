/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_subtruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:43:13 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:00:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

t_bigint		*ft_bigint_subt(t_bigint *num1, t_bigint *num2, t_bigint *num3)
{
	size_t		i;
	t_ulint		b;
	t_ulint		temp;
	t_bigint	*b_num;
	t_bigint	*l_num;

	b = 0UL;
	i = -1;
	ft_bigint_order(num1, num2, &l_num, &b_num);
	while (++i < b_num->length)
		if (((t_ulint)b_num->blocks[i] == 0UL && b == 1)
		|| (l_num->blocks[i] > b_num->blocks[i] - b))
		{
			temp = (t_ulint)b_num->blocks[i] + (1UL << 32) - b;
			b = 1UL;
			num3->blocks[i] = (t_uint)(temp - (t_ulint)l_num->blocks[i]);
		}
		else
		{
			num3->blocks[i] = (t_uint)(b_num->blocks[i] - b - l_num->blocks[i]);
			b = 0UL;
		}
	num3->length = ft_bigint_size(num3);
	return (num3);
}
