/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 22:40:35 by rstarfir          #+#    #+#             */
/*   Updated: 2019/12/30 20:00:27 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"
#include "stdio.h"
#include <limits.h>

#include <float.h>

int main(void)
{
	 //printf("Double max: %Lf\n", LDBL_MAX);
	//ft_printf("%.3f\n", 2.00250027);
	printf("\n{%f}{%lf}{%Lf}\n", 1.62, 1.42, 1.42l);
	ft_printf("\n{%f}{%lf}{%Lf}", 1.62, 1.62, 1.72l);
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