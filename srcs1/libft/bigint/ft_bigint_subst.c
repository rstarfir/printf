/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_subst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:36:48 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 12:25:42 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Substract the smallest number from `bigint1' and `bigint2' to the biggest
** from `bigint1` and `bigint2' and store the difference in `result'.
** Return a pointer to `result'.
*/

t_bigint		*ft_bigint_subst(const t_bigint *bigint1,
									const t_bigint *bigint2, t_bigint *result)
{
	const t_bigint	*large_nb;
	const t_bigint	*small_nb;
	t_ulint			carry;
	t_ulint			tmp;
	size_t			i;

	carry = 0UL;
	i = 0;
	ft_bigint_order(bigint1, bigint2, &small_nb, &large_nb);
	while (i < large_nb->length)
	{
		tmp = (t_ulint)large_nb->blocks[i] - carry;
		carry = (((large_nb->blocks[i] > 0) || (!large_nb->blocks[i] && !carry))
					&& (tmp >= (t_ulint)small_nb->blocks[i])) ? 0UL : 1UL;
		result->blocks[i] = (t_uint)((tmp + ((carry) ? (1UL << 32) : 0UL)
					- (t_ulint)small_nb->blocks[i]) & 0xFFFFFFFFUL);
		i++;
	}
	result->length = ft_bigint_size(result);
	return (result);
}
