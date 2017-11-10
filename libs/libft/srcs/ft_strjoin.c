/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:21:31 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/19 17:21:32 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*merge;
	int		len;

	merge = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		merge = (char *)malloc(sizeof(char) * (len + 1));
		if (merge)
		{
			ft_strcpy(merge, s1);
			ft_strcat(merge, s2);
		}
	}
	return (merge);
}
