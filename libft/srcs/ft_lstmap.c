/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:25:41 by hthunder          #+#    #+#             */
/*   Updated: 2019/09/16 17:55:54 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	ft_lstfree(t_list *top)
{
	t_list	*temp;

	while (top)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	if (!(head = f(lst)))
		return (NULL);
	ptr = head;
	while (lst->next)
	{
		if (!(ptr->next = f(lst->next)))
		{
			ft_lstfree(head);
			return (NULL);
		}
		lst = lst->next;
		ptr = ptr->next;
	}
	return (head);
}
