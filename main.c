/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 22:40:35 by rstarfir          #+#    #+#             */
/*   Updated: 2020/01/08 16:38:39 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"
#include "stdio.h"
#include <limits.h>

#include <float.h>

int main(void)
{
    //printf("%d\n", ft_printf("%5"));
    //printf("%d", ft_printf("%5"));
    //printf("%lld\n", LLONG_MAX); // 9223372036854775807
	//ft_printf("%lld\n", LLONG_MAX); // 9223372036854775807
	//ft_printf("%lld", 0);
	//printf("%o\n", -50);
	//ft_printf("%o\n", -50);
	//printf("%lld\n", LLONG_MIN);
	//ft_printf("%lld", LLONG_MIN);
	//printf("%li\n", 22337203685477);
	//ft_printf("%li", 22337203685477);
	//printf("% -10.5i\n", -216);
	//ft_printf("% -10.5i", -216);
	//printf("%25.23lld\n", LLONG_MIN);
	//ft_printf("%25.23lld", LLONG_MIN);
	printf("%-20lx<--\n", ULONG_MAX);
	ft_printf("%-20lx<--", ULONG_MAX);

return (0);
}

/*
	limits.h synopsis

Macros:

	CHAR_BIT
	SCHAR_MIN
	SCHAR_MAX
	UCHAR_MAX
	CHAR_MIN
	CHAR_MAX
	MB_LEN_MAX
	SHRT_MIN
	SHRT_MAX
	USHRT_MAX
	INT_MIN
	INT_MAX
	UINT_MAX
	LONG_MIN
	LONG_MAX
	ULONG_MAX
	LLONG_MIN   // C99
	LLONG_MAX   // C99
	ULLONG_MAX  // C99

*/