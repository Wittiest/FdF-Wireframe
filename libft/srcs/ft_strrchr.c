/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:47:51 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/20 13:47:51 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *save;

	save = ((void *)(0));
	while (*s)
	{
		if (*s == (unsigned char)c)
			save = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return (char *)s;
	return (save);
}
