/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:44:24 by hthunder          #+#    #+#             */
/*   Updated: 2019/11/30 17:39:32 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

static char	*strrev(char *str)
{
	int		i;
	int		j;
	char	a;
	size_t	len;

	if (str)
	{
		len = ft_strlen((const char *)str);
		i = 0;
		j = len - 1;
		while (i < j)
		{
			a = str[i];
			str[i] = str[j];
			str[j] = a;
			i++;
			j--;
		}
		return (str);
	}
	else
		return (NULL);
}

/*
** char	*ft_itoabase(long long int num, int base)
** {
** size_t	i;
** int		is_negative;
** int		rem;
** char	*str;
**
** i = 0;
** is_negative = 0;
** if (!(str = (char *)malloc(sizeof(char) * 21)))
** return (NULL);
** if (num == 0)
** {
** str[i++] = '0';
** str[i] = '\0';
** return (str);
** }
** //if (base != 10 && num < 0)
** //	num *= -1;
** if (num < 0 && base == 10)
** {
** is_negative = 1;
** num = -num;
** }
** while (num != 0)
** {
** rem = num % base;
** str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
** num = num / base;
** }
** if (is_negative)
** str[i++] = '-';
** str[i] = '\0';
** return (strrev(str));
** }
*/

static	int	ft_nsize(long long int nb)
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

char		*ft_llitoa(long long int n)
{
    char    *ptr;
	int		i;
	int		size;

	size = ft_nsize(n);
	i = 0;
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

char		*ft_itoabase_unsigned(unsigned long long int num, int base)
{
	size_t	i;
	int		rem;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	str[i] = '\0';
	return (strrev(str));
}
