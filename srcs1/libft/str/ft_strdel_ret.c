/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 12:23:27 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/17 12:23:56 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strdel_ret(char **as, int ret)
{
	if (as != NULL && *as)
	{
		free(*as);
		*as = NULL;
	}
	return (ret);
}
