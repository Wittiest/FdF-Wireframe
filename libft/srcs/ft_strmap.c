/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:52:58 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/19 14:52:59 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	newstr = NULL;
	i = 0;
	if (s)
	{
		newstr = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (newstr)
		{
			while (*(s + i))
			{
				*(newstr + i) = (*f)(*(s + i));
				i++;
			}
			*(newstr + i) = '\0';
		}
	}
	return (newstr);
}
