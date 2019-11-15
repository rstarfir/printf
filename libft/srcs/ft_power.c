/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:51:44 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/17 17:01:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int val, int pow)
{
	long res;

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
