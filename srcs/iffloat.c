/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:11:19 by rstarfir          #+#    #+#             */
/*   Updated: 2019/11/22 12:54:05 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdarg.h>

void	iffloat(t_parser *f, va_list ap)
{
	long double		number;

	number = 0;
	if (f->size == 0)
		number = (long double)va_arg(ap, double);
	else if (f->size == UCL)
		number = (long double)va_arg(ap, long double);
	/*
	** send to function
	*/
}
