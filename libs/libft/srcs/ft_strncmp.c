/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:07:43 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/20 14:07:43 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 1 && (*s1 || *s2) && *s1 == *s2)
	{
		(void)*s1++;
		(void)*s2++;
		n--;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
