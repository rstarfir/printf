/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_pow10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:00:17 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/19 18:19:23 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const t_uint		g_first_pow10[8] = {1, 10, 100, 1000, 10000, 100000,
	1000000, 10000000};
static const t_bigint	g_lookup_tbl[6] = {
	{1, {100000000}},
	{2, {0x6fc10000, 0x002386f2}},
	{4, {0x00000000, 0x85acef81, 0x2d6d415b, 0x000004ee}},
	{7, {0x00000000, 0x00000000, 0xbf6a1f01, 0x6e38ed64,
			0xdaa797ed, 0xe93ff9f4, 0x00184f03}},
	{14, {0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x2e953e01, 0x03df9909, 0x0f1538fd, 0x2374e42f,
			0xd3cff5ec, 0xc404dc08, 0xbccdb0da, 0xa6337f19,
			0xe91f2603, 0x0000024e}},
	{27, {0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x00000000, 0x00000000, 0x00000000, 0x00000000,
			0x982e7c01, 0xbed3875b, 0xd8d99f72, 0x12152f87,
			0x6bde50c6, 0xcf4a6e70, 0xd595d80f, 0x26b2716e,
			0xadc666b0, 0x1d153624, 0x3c42d35a, 0x63ff540e,
			0xcc5573c0, 0x65f9ef17, 0x55bc28f2, 0x80dcc7f7,
			0xf46eeddc, 0x5fdcefce, 0x000553f7}}
};

static void			long_double_pow10(t_bigint *result, t_uint exponent)
{
	t_uint			count;
	t_uint			i;

	count = 1U << 1;
	while (exponent)
	{
		if (exponent & 1U)
		{
			i = 0;
			while (i < count)
			{
				*result = ft_bigint_multiply(result, &g_lookup_tbl[5]);
				i++;
			}
		}
		exponent >>= 1;
		count <<= 1;
	}
}
/*
void				ft_bigint_pow10(t_bigint *result, t_uint exponent)
{
	t_uint			tbl_index;

	if (exponent & 0x7)
		ft_uimax_to_bigint(g_first_pow10[exponent & 0x7], result);
	else
		ft_uimax_to_bigint(1U, result);
	exponent >>= 3;
	tbl_index = 0;
	while (exponent && tbl_index < 6)
	{
		if (exponent & 1U)
			*result = ft_bigint_multiply(result, &g_lookup_tbl[tbl_index]);
		exponent >>= 1;
		++tbl_index;
	}
	if (exponent)
		long_double_pow10(result, exponent);
}
*/

t_bigint 		    ft_bigint_pow10(t_uint exponent)
{
    t_uint			tbl_index;
    t_bigint		pow10;

    pow10 = (t_bigint){0, {0}};
    if (exponent & 0x7)
        ft_uimax_to_bigint(g_first_pow10[exponent & 0x7], &pow10);
    else
        ft_uimax_to_bigint(1U, &pow10);
    exponent >>= 3;
    tbl_index = 0;
    while (exponent && tbl_index < 6)
    {
        if (exponent & 1U)
            pow10 = ft_bigint_multiply(&pow10, &g_lookup_tbl[tbl_index]);
        exponent >>= 1;
        ++tbl_index;
    }
    if (exponent)
        long_double_pow10(&pow10, exponent);
    return pow10;
}