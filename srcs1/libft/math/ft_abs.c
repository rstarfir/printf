/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:50:03 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 20:56:35 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_abs(int nb)
{
	long	lnb;

	if (nb >= 0)
		return (nb);
	lnb = -nb;
	return ((unsigned int)lnb);
}
