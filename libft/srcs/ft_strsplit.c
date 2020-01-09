/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:18:29 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/16 18:02:13 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_wc(const char *str, char c)
{
	int wrdctr;

	wrdctr = 0;
	if (*str != c && *str)
	{
		str++;
		wrdctr++;
	}
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				wrdctr++;
		}
		str++;
	}
	return (wrdctr);
}

static	int		ft_sc(const char *str, char c)
{
	int symbctr;

	symbctr = 0;
	while (*str != c && *str)
	{
		symbctr++;
		str++;
	}
	return (symbctr);
}

static	void	ft_splitfree(char **ptr, int i)
{
	int cntr;

	cntr = 0;
	while (cntr < i)
	{
		free(ptr[cntr]);
		ptr[cntr] = NULL;
		cntr++;
	}
	free(ptr);
	ptr = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	if (!s || (!(ptr = (char **)malloc(sizeof(char *) * (ft_wc(s, c) + 1)))))
		return (NULL);
	while (!(j = 0) && *s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(ptr[i] = (char *)malloc(sizeof(char) * (ft_sc(s, c) + 1))))
			{
				ft_splitfree(ptr, i);
				return (NULL);
			}
			while (*s && *s != c)
				ptr[i][j++] = (char)*s++;
			ptr[i++][j] = '\0';
		}
	}
	ptr[i] = NULL;
	return (ptr);
}
