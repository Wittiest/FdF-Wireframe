/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:20:41 by dpearson          #+#    #+#             */
/*   Updated: 2017/09/30 17:20:42 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*free_strnjoin(char *s1, char const *s2, int n)
{
	char	*merge;

	if (!s1 || !s2)
		return (NULL);
	if ((merge = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		ft_strcpy(merge, s1);
		ft_strncat(merge, s2, n);
	}
	free(s1);
	return (merge);
}

static	char	*change_line(char **str)
{
	char	*line;
	int		i;
	char	*tmp;

	i = 0;
	tmp = *str;
	while (*(*str + i) && (*(*str + i) != '\n'))
		i++;
	line = ft_strsub(*str, 0, i);
	if (*(*str + i))
		tmp = ft_strsub(*str, i + 1, ft_strlen(tmp) - i - 1);
	else
		tmp = ft_strnew(1);
	if (*str)
		free(*str);
	*str = ft_strdup(tmp);
	free(tmp);
	return (line);
}

static int		new(int fd, char **line, char **fd_arr)
{
	int		r;
	char	*buf;

	r = 0;
	SAFEMALLOC((buf = ft_strnew(BUFF_SIZE)));
	READ(r, buf, BUFF_SIZE, fd);
	SAFE_FREE_MALLOC((*fd_arr = ft_strdup(buf)), buf);
	while (r && !(ft_strstr(*fd_arr, "\n")))
	{
		READ(r, buf, BUFF_SIZE, fd);
		SAFEMALLOC((*fd_arr = free_strnjoin(*fd_arr, buf, r)));
	}
	*line = change_line(fd_arr);
	free(buf);
	return ((**line || r) ? 1 : 0);
}

static int		old(int fd, char **line, char **fd_arr)
{
	int		r;
	char	*buf;

	r = 1;
	SAFEMALLOC((buf = ft_strnew(BUFF_SIZE)));
	while (r && !(ft_strstr(*fd_arr, "\n")))
	{
		READ(r, buf, BUFF_SIZE, fd);
		if (r == 0)
			break ;
		SAFEMALLOC((*fd_arr = free_strnjoin(*fd_arr, buf, r)));
	}
	*line = change_line(fd_arr);
	free(buf);
	return ((**line || r) ? 1 : 0);
}

/*
**	Using ulimit -n, we know less than 4864 FDs will happen.
**	By using a static variable that will last until our program ends, we can see
**	which files have been read before, allowing us to continue reading after
**	having switched to a new file.
*/

int				get_next_line(const int fd, char **line)
{
	static char	*fd_arr[4864];

	if (!(line) || fd < 0 || fd > 4864)
		return (-1);
	return ((fd_arr[fd]) ? old(fd, line, &fd_arr[fd]) :
			new(fd, line, &fd_arr[fd]));
}
