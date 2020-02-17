/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:41:31 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:00:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void			ft_bigint_order(t_bigint *bi1, t_bigint *bi2,
								t_bigint **small_nb, t_bigint **large_nb)
{
	if (ft_bigint_comp(bi1, bi2) >= 0)
	{
		*large_nb = bi1;
		*small_nb = bi2;
	}
	else
	{
		*large_nb = bi2;
		*small_nb = bi1;
	}
}
