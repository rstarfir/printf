/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimax_to_bigint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:45:39 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 12:25:01 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert a uintmax_t number to a bigint and store the obtained bigint in
** `result'.
** Return a pointer to `result'.
*/

t_bigint		*ft_uimax_to_bigint(uintmax_t nb, t_bigint *result)
{
	int			i;

	i = -1;
	while (nb && ++i < BIGINT_SIZE)
	{
		result->blocks[i] = (t_uint)(nb & 0xFFFFFFFFUL);
		nb >>= BIGINT_BLOCK_SIZE;
	}
	result->length = ft_bigint_size(result);
	return (result);
}
