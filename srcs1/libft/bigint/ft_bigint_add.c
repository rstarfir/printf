/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:32:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 12:24:07 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add `bigint1' and `bigint2' and store the sum in `result'.
** Return a pointer to `result'.
*/

t_bigint    ft_bigint_add(t_bigint fNum, t_bigint sNum)
{
    t_bigint result;
    size_t i;
    unsigned long carry;
    unsigned long sum;
    size_t max_len;
    carry = 0;
    i = 0;
    result = (t_bigint){0, {0}};
    max_len = (size_t)ft_max(fNum.length, sNum.length);
    while (i < max_len) {
        sum = carry + fNum.blocks[i] + sNum.blocks[i];
        result.blocks[i] = sum & 0xFFFFFFFF;
        carry = sum >> 32;
        i++;
    }
    if (carry && (i < BIGINT_SIZE))
        result.blocks[i] = carry & 0xFFFFFFFF;
    if (carry)
        result.length = max_len + 1;
    else
        result.length = max_len;
    return (result);
}
