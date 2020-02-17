/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullint_to_bi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:43:55 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 19:46:08 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

void			ft_ullint_to_bigint(t_ullint ull, t_bigint *bi)
{
	t_ullint	temp;
	size_t		i;

	i = 2;
	temp = (ull << 32) >> 32;
	bi->blocks[0] = (t_uint)temp;
	bi->blocks[1] = (t_uint)(ull >> 32);
	while (i--)
		if (bi->blocks[i])
			break ;
	bi->length = i + 1;
}
