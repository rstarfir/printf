/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exponent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:35:20 by rstarfir          #+#    #+#             */
/*   Updated: 2019/12/08 17:35:26 by rstarfir         ###   ########.fr       */
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
