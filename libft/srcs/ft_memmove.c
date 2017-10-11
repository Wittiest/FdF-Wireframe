/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:44:26 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/18 14:44:27 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
**	1.	We create two pointers (s1,s2) as clones of *dst,*src.
**	2.	If s1 == s2, we don't need to do anything, so we just return dst as we
**		usually would.
**	3.	If dst>src we copy from the length backwards, starting right before the
**		null byte.
**	4.	Otherwise, we copy forwards.
**	5.	In the end, we return the original dst, as instructed.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (s1 == s2)
		return (dst);
	if (dst > src)
	{
		s1 += len - 1;
		s2 += len - 1;
		while (len--)
			*s1-- = *s2--;
	}
	else
		while (len--)
			*(s1++) = *(s2++);
	return (dst);
}
