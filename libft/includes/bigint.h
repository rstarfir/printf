/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:34:02 by hthunder          #+#    #+#             */
/*   Updated: 2020/02/17 21:00:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
# define BIGINT_H

# include "custom_data_types.h"
# include <stdlib.h>

# define BIG_INT_SIZE 515

typedef struct	s_bigint {
	size_t		length;
	t_uint		blocks[BIG_INT_SIZE];
}				t_bigint;

void			ft_ullint_to_bigint(t_ullint ull, t_bigint *bi);
void			ft_bigint_shiftleft(t_bigint *bi, t_uint shift);
t_bigint		ft_bigint_multiply(t_bigint *bi1, t_bigint *bi2, t_ulint temp);
size_t			ft_bigint_size(t_bigint *bi);
int				ft_bigint_divide(t_bigint *dividend, t_bigint *divisor);
t_bigint		*ft_bi_uint_mult(t_bigint *bi, t_uint nb);
t_bigint		*ft_bigint_subt(t_bigint *num1, t_bigint *num2, t_bigint *num3);
t_bigint		ft_bigint_x10(t_uint exponent);
void			ft_bigint_order(t_bigint *bi1, t_bigint *bi2,
				t_bigint **small_nb, t_bigint **large_nb);
int				ft_bigint_comp(t_bigint *bi1, t_bigint *bi2);

#endif
