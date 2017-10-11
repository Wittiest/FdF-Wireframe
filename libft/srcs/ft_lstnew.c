/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:16:18 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/21 14:16:18 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	We create a pointer list which will be the first position in our new list.
**	If we allocate the memory correctly and we are given proper content, we
**	allocate memory for the content. If this doesn't work, we use memdel to
**	free the memory and set the pointer to NULL.
**
**	We then copy over the content to our list and return it.
*/

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*list;

	list = ft_memalloc(sizeof(t_list));
	if (list && content)
	{
		list->content = ft_memalloc(content_size);
		if (!list->content)
		{
			ft_memdel((void*)&list);
			return (0);
		}
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	return (list);
}
