/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exponent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:03:45 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/17 22:15:30 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_exponent(long double value)
{
	int			exp;

	exp = 0;
	if (!value || ((value >= 1) && (value <= 9)))
		return (exp);
	if (value < 0)
		value *= -1;
	if (value >= 10)
	{
		while (value >= 10)
		{
			value /= 10;
			++exp;
		}
		return (exp);
	}
	while (value < 1)
	{
		value *= 10;
		++exp;
	}
	return (-exp);
}
