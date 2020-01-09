/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:48:20 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/14 20:55:37 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *next_ptr;

	if (alst && *alst && del)
	{
		ptr = *alst;
		while (ptr)
		{
			next_ptr = ptr->next;
			del(ptr->content, ptr->content_size);
			free(ptr);
			ptr = next_ptr;
		}
		*alst = NULL;
	}
}
