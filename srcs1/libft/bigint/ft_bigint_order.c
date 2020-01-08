/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:38:30 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/19 10:14:44 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Make `large_nb' point on the biggest big int, and `small_nb` on the
** smallest.
*/

void			ft_bigint_order(const t_bigint *bigint1,
					const t_bigint *bigint2, const t_bigint **small_nb,
					const t_bigint **large_nb)
{
	if (ft_bigint_comp(bigint1, bigint2) >= 0)
	{
		*large_nb = bigint1;
		*small_nb = bigint2;
	}
	else
	{
		*large_nb = bigint2;
		*small_nb = bigint1;
	}
}
