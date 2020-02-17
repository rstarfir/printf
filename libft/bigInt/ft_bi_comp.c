/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bi_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:39:23 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:00:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

int			ft_bigint_comp(t_bigint *bi1, t_bigint *bi2)
{
	size_t	i;

	if (bi1->length != bi2->length)
		return ((bi1->length > bi2->length) ? 1 : -1);
	i = bi1->length;
	while (i--)
		if (bi1->blocks[i] != bi2->blocks[i])
			return ((bi1->blocks[i] > bi2->blocks[i]) ? 1 : -1);
	return (0);
}
