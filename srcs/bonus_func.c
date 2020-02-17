/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:22:38 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:00:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			add_style(char *str, t_parser *f)
{
	int flag;

	flag = 0;
	if (ft_strstr(str, "{BOLD}") && (flag = 6))
		write(1, BOLD, 4);
	else if (ft_strstr(str, "{UNDERLINE}") && (flag = 11))
		write(1, UNDERLINE, 4);
	else if (ft_strstr(str, "{REVERSE}") && (flag = 9))
		write(1, REVERSE, 4);
	else if (ft_strstr(str, "{RESETALL}") && (flag = 10))
		write(1, RESETALL, 4);
	f->i += flag;
	if (flag != 0)
		f->nprinted += 4;
	return (flag);
}

int			add_color(const char *str, t_parser *f)
{
	int		flag;
	char	*copy;

	flag = 0;
	copy = ft_strndup(str, ft_strchr(str, '}') - str + 1);
	if (add_style(copy, f))
	{
		free(copy);
		return (1);
	}
	if (ft_strstr(copy, "{RED}") && (flag = 5))
		write(1, RED, 5);
	else if (ft_strstr(copy, "{GREEN}") && (flag = 7))
		write(1, GREEN, 5);
	else if (ft_strstr(copy, "{YELLOW}") && (flag = 8))
		write(1, YELLOW, 5);
	else if (ft_strstr(copy, "{RESET}") && (flag = 7))
		write(1, RESET, 4);
	f->i += flag;
	if (ft_strstr(copy, "{RESET}"))
		f->nprinted += 4;
	else if (flag != 0)
		f->nprinted += 5;
	free(copy);
	return (flag);
}

static	int	utf8_for_4char(char *s, t_uint uni)
{
	s[0] = (char)(((uni >> 18) & 0x07) | 0xF0);
	s[1] = (char)(((uni >> 12) & 0x3F) | 0x80);
	s[2] = (char)(((uni >> 6) & 0x3F) | 0x80);
	s[3] = (char)(((uni >> 0) & 0x3F) | 0x80);
	s[4] = 0;
	return (4);
}

int			utf8_encode(char *s, t_uint uni)
{
	if (uni <= 0x7F)
	{
		s[0] = (char)uni;
		s[1] = 0;
		return (1);
	}
	else if (uni <= 0x07FF)
	{
		s[0] = (char)(((uni >> 6) & 0x1F) | 0xC0);
		s[1] = (char)(((uni >> 0) & 0x3F) | 0x80);
		s[2] = 0;
		return (2);
	}
	else if (uni <= 0xFFFF)
	{
		s[0] = (char)(((uni >> 12) & 0x0F) | 0xE0);
		s[1] = (char)(((uni >> 6) & 0x3F) | 0x80);
		s[2] = (char)(((uni >> 0) & 0x3F) | 0x80);
		s[3] = 0;
		return (3);
	}
	else if (uni <= 0x10FFFF)
		return (utf8_for_4char(s, uni));
	return (0);
}
