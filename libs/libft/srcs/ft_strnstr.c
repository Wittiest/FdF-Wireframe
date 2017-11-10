/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:14:10 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/20 16:14:11 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
**	First we check if little has anything in it's first spot. If it doesn't,
**	we just return big, because the "first occurence" is the first spot in big.
**
**	We iterate through big, if we find a spot where they match, we begin to
**	iterate along big and little. If little hits its null byte, we know we found
**	it at big + i;
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	save;
	char	*bigclone;
	char	*littleclone;

	i = 0;
	bigclone = (char *)big;
	littleclone = (char *)little;
	if (!*littleclone)
		return (bigclone);
	while (i < len && *(bigclone + i))
	{
		j = 0;
		save = i;
		while ((save < len) && bigclone[save++] == littleclone[j++])
			if (!*(littleclone + j))
				return (bigclone + i);
		i++;
	}
	return (NULL);
}
