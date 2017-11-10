/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:37:58 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/21 17:37:59 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	We check if the given list exists, if not we return null. We will use the
**	variable head to store the beginning of our fresh list that has been
**	modified by the function
**
**	While there is a next spot in the list, we go to it and advance our list and
**	lst variables, setting list->next to the modified (*f)(lst).
**	If we reach a position where the function pointer doesn't return correctly,
**	we cannot give a valid return, so we return NULL.
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*list;

	if (!lst)
		return (NULL);
	list = (*f)(lst);
	head = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = (*f)(lst)))
		{
			free(list->next);
			return (NULL);
		}
		list = list->next;
	}
	return (head);
}
