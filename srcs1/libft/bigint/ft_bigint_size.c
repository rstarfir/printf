/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:41:57 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/17 22:42:27 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return the number of blocks used to store the bigint.
*/

size_t			ft_bigint_size(const t_bigint *bigint)
{
	size_t		i;

	i = BIGINT_SIZE;
	while (i--)
		if (bigint->blocks[i])
			return (i + 1);
	return (0);
}
