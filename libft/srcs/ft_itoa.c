/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 02:44:01 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/20 02:44:02 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa(int n)
{
	int		len;
	long	n_cpy;
	char	*str;

	len = ft_nbr_len(n);
	n_cpy = (long)n;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n_cpy < 0)
	{
		str[0] = '-';
		n_cpy = -n_cpy;
	}
	str[len--] = (n_cpy % 10) + '0';
	while (n_cpy >= 10)
	{
		n_cpy /= 10;
		str[len--] = (n_cpy % 10) + '0';
	}
	return (str);
}
