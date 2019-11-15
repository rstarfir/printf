/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:11:51 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/15 17:47:54 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

static	int	ft_isemptystr(char const *s)
{
	while (*s != '\0')
	{
		if (!ft_isspace(*s))
			return (0);
		s++;
	}
	return (1);
}

static	int	ft_newlength(char const *s)
{
	int length;
	int i;
	int beginspace;
	int endspace;

	length = ft_strlen(s);
	i = 0;
	beginspace = 0;
	endspace = 0;
	if (!ft_isemptystr(s))
	{
		while (length && ft_isspace(s[length - 1]))
		{
			endspace++;
			length--;
		}
		while (ft_isspace(s[i]))
		{
			beginspace++;
			i++;
		}
		return (ft_strlen(s) - beginspace - endspace);
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*s1;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s)
	{
		len = ft_newlength(s);
		if (!(s1 = (char *)malloc(len + 1)))
			return (NULL);
		while (ft_isspace(s[i]))
			i++;
		while (j < len)
		{
			s1[j] = s[i];
			i++;
			j++;
		}
		s1[j] = '\0';
		return (s1);
	}
	return (NULL);
}
