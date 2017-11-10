/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:18:45 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/18 14:18:48 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	while (i < n)
	{
		*(b + i) = *(a + i);
		if (*(a + i) == ((unsigned char)c))
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
