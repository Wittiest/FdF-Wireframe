/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 23:09:28 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/19 23:09:28 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	is_end(char const *s)
{
	while (*s)
	{
		if (!(is_space(*s)))
			return (0);
		s++;
	}
	return (1);
}

char		*ft_strtrim(char const *s)
{
	char			*clone;
	unsigned int	start;
	size_t			len;

	start = 0;
	len = 0;
	clone = NULL;
	if (s)
	{
		while (is_space(*(s + start)))
			start++;
		len = start;
		while (*(s + len))
		{
			if (is_end(s + len))
				break ;
			len++;
		}
		clone = ft_strsub(s, start, (len - start));
	}
	return (clone);
}
