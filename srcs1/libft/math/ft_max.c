/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:55:42 by jkettani          #+#    #+#             */
/*   Updated: 2019/02/24 14:58:03 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

intmax_t		ft_max(intmax_t n1, intmax_t n2)
{
	return ((n1 < n2) ? n2 : n1);
}
