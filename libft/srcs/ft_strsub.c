/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:12:07 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/19 16:12:08 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *freshstr;
	char *save;

	save = NULL;
	if (s)
	{
		freshstr = (char *)malloc(sizeof(char) * len + 1);
		save = freshstr;
		if (freshstr)
		{
			while (*(s + start) && len > 0)
			{
				*freshstr = *(s + start);
				freshstr++;
				len--;
				s++;
			}
			*freshstr = '\0';
		}
	}
	return (save);
}
