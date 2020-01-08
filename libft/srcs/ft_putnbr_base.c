/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:46:56 by adavis            #+#    #+#             */
/*   Updated: 2019/12/28 21:14:41 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

void	ft_putnbr_base(unsigned long long nbr, int base, t_bool upper)
{
	unsigned long long	tmp;
	unsigned long long	div;

	tmp = nbr;
	div = 1;
	while (tmp > (unsigned long long)(base - 1))
	{
		div *= base;
		tmp /= base;
	}
	while (div > 0)
	{
		if (upper)
			ft_putchar(BASE_CHARS_UPPER[nbr / div % base]);
		else
			ft_putchar(BASE_CHARS_LOWER[nbr / div % base]);
		div /= base;
	}
}
