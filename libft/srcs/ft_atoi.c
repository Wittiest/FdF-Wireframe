/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 01:38:00 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/21 01:38:01 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Skip spaces. Ignore a plus sign or check for an equal sign, but not both.
**	While numbers, create int by multiplying current int by 10 and adding new
**	character. If we marked negative earlier, make int negative.
*/

int		ft_atoi(const char *str)
{
	int		fml[3];

	fml[0] = 0;
	fml[1] = 0;
	fml[2] = 1;
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\v' ||
		*str == '\n' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-' && str++)
		fml[2] = -fml[2];
	while ('9' >= str[fml[0]] && str[fml[0]] >= '0')
		fml[1] = (fml[1] * 10) + str[fml[0]++] - '0';
	if (fml[2] == -1)
		fml[1] = -fml[1];
	return (fml[1]);
}
