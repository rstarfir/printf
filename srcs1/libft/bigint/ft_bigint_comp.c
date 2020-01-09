/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_comp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:21:33 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/19 10:37:26 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** First compare bigint lengths, and return 1 if length of bigint1 is greater
** than length of bigint2.
** If lengths are equal, compare blocks one by one from high to low.
** If blocks values are not equal, return 1 if block of bigint1 is greater than
** block of bigint2, else return -1.
** If all blocks are equal, return 0.
*/

int				ft_bigint_comp(const t_bigint *bigint1, const t_bigint *bigint2)
{
	size_t		i;

	if (bigint1->length != bigint2->length)
		return ((bigint1->length > bigint2->length) ? 1 : -1);
	i = bigint1->length;
	while (i--)
		if (bigint1->blocks[i] != bigint2->blocks[i])
			return ((bigint1->blocks[i] > bigint2->blocks[i]) ? 1 : -1);
	return (0);
}
