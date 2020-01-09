/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:51:44 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/28 17:40:00 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_power(int val, int pow)
{
	long long  res;

	res = 1;
	while (pow > 0)
	{
		if (pow % 2 == 0)
		{
			pow /= 2;
			val *= val;
		}
		else
		{
			pow--;
			res *= val;
		}
	}
	return (res);
}
