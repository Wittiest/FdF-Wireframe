/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 04:55:09 by dpearson          #+#    #+#             */
/*   Updated: 2017/11/08 04:55:11 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	read_file(t_img *img, int fd)
{
	int		i;
	int		row;
	char	**lines;
	char	***split_array;

	row = 0;
	lines = (char **)malloc(sizeof(char *));
	while (get_next_line(fd, &lines[row]) > 0)
	{	
		row++;
		lines = ft_realloc(lines, sizeof(char *) * (row + 1));
	}
	img->map = (int **)malloc(sizeof(int *) * (row));
	split_array = (char ***)malloc(sizeof(char **) * row);
	while (img->ln_count < row)
	{
		split_array[img->ln_count] = ft_strsplit(lines[img->ln_count], ' ');
		i = 0;
		img->map[img->ln_count] = (int *)malloc(sizeof(int));
		while (split_array[img->ln_count][i])
		{
			img->map[img->ln_count][i] = ft_atoi(split_array[img->ln_count][i]);
			i++;
			if (split_array[img->ln_count][i])
				img->map[img->ln_count] = ft_realloc(img->map[img->ln_count], sizeof(int) * (i + 2));
		}
		if (img->ln_count == 0)
			img->width = i;
		else if (i != img->width)
		{
			write(1, "Lines are different widths\n", 6);
			exit(1);
		}
		img->ln_count++;
	}
}
