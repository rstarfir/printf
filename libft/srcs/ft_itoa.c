/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:34:59 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/12 22:19:50 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	ft_nsize(int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		size += 1;
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		size;

	size = ft_nsize(n);
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ptr[size] = '\0';
	if (n < 0)
	{
		ptr[i] = '-';
		n *= -1;
		i++;
	}
	while (i < size--)
	{
		ptr[size] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
