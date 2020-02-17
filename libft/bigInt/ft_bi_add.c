/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:38:57 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 19:26:34 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "libft.h"

t_bigint		ft_bigint_add(t_bigint f_num, t_bigint s_num)
{
	t_bigint	result;
	t_ulint		carry;
	t_ulint		sum;
	size_t		i;
	size_t		max_len;

	carry = 0;
	i = 0;
	result = (t_bigint){0, {0}};
	max_len = (size_t)ft_max(f_num.length, s_num.length);
	while (i < max_len)
	{
		sum = carry + f_num.blocks[i] + s_num.blocks[i];
		result.blocks[i] = sum & 0xFFFFFFFF;
		carry = sum >> 32;
		++i;
	}
	if (carry && (i < BIG_INT_SIZE))
		result.blocks[i] = carry & 0xFFFFFFFF;
	if (carry)
		result.length = max_len + 1;
	else
		result.length = max_len;
	return (result);
}
