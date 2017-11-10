/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:35:08 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/21 16:35:08 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t n))
{
	t_list *temp;

	while (*alst)
	{
		temp = *alst;
		(*del)((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(temp);
		temp = NULL;
	}
	alst = NULL;
}
