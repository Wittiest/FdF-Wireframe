/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:13:47 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/20 13:13:48 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
**	We return "total length of string we tried to create", which is:
**	len of the dst (before concatenation) + len of src.
**	Line 32 triggers when dst's > size
**	we return src and as much of dst as < size
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			dstlen;
	size_t			srclen;
	size_t			i;

	srclen = 0;
	dstlen = 0;
	i = 0;
	while (size-- && *(dst + dstlen))
		dstlen++;
	size++;
	if (!size)
		return (dstlen + ft_strlen(src));
	while (*(src + srclen))
	{
		if (size != 1)
		{
			dst[dstlen + i++] = src[srclen];
			size--;
		}
		srclen++;
	}
	*(dst + dstlen + i) = '\0';
	return (dstlen + srclen);
}
