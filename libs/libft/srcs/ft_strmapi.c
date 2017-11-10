/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:14:07 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/19 15:14:08 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int i, char c))
{
	char			*newstr;
	unsigned int	i;

	i = 0;
	newstr = NULL;
	if (s)
	{
		newstr = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (newstr)
		{
			while (*(s + i))
			{
				*(newstr + i) = (*f)(i, *(s + i));
				i++;
			}
			*(newstr + i) = '\0';
		}
	}
	return (newstr);
}
