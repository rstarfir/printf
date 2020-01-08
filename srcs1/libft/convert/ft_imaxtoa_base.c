/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:42:20 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/24 10:14:57 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_imaxtoa_base(intmax_t nb, const char *base)
{
	char	*str;
	int		digits;
	int		neg;
	int		pos;
	int		radix;

	neg = (nb < 0) ? 1 : 0;
	if (!ft_is_valid_base(base))
		return (NULL);
	radix = ft_strlen(base);
	if ((digits = ft_digits_base(nb, radix)) < 0
			|| !(str = (char *)ft_strnew(digits + neg)))
		return (NULL);
	if (neg)
		str[0] = '-';
	while (digits > 0)
	{
		pos = nb % radix;
		str[digits + neg - 1] = base[(pos < 0) ? -pos : pos];
		nb /= radix;
		--digits;
	}
	return (str);
}
