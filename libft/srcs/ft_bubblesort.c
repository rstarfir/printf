/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:19:20 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/17 16:05:03 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubblesort(int *num, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	if (num)
	{
		while (i < size - 1)
		{
			j = size - 1;
			while (j > i)
			{
				if (num[j - 1] > num[j])
				{
					temp = num[j - 1];
					num[j - 1] = num[j];
					num[j] = temp;
				}
				j--;
			}
			i++;
		}
	}
}
