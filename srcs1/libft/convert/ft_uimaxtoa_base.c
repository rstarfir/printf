/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:37:30 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/24 10:15:05 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uimaxtoa_base(uintmax_t nb, char const *base)
{
	char	*str;
	int		digits;
	int		radix;

	if (!ft_is_valid_base(base))
		return (NULL);
	radix = ft_strlen(base);
	if ((digits = ft_udigits_base(nb, radix)) < 0
			|| !(str = (char *)ft_strnew(digits)))
		return (NULL);
	while (digits > 0)
	{
		str[digits - 1] = base[nb % radix];
		nb /= radix;
		--digits;
	}
	return (str);
}
