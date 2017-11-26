/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:20:35 by dpearson          #+#    #+#             */
/*   Updated: 2017/11/06 11:27:08 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	print_term(t_img *img)
// {
// 	int i = 0;
// 	int j;
// 	while (i < img->ln_count)
// 	{
// 		j = 0;
// 		while (j < img->width)
// 		{
// 			printf("%d ", img->map[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

/*
**	I made the img var static so that it would all be initialized to 0.
**	Usually statics are only declared in main when they are a structure that
**	could be so big that it overflows the stack. I don't think that would happen
**	with this program.
**
**	I open the file and write the fd + filename into the struct, then pass it
**	to be parsed. If there is an error along the way, the program will exit.
*/

int		main(int argc, char **argv)
{
	static t_img	img;
	int fd;

	if (argc != 2)
		write(2, "usage: ./fdf filename.fdf\n", 26);
	else
	{
		img.file_name = argv[1];
		fd = open(img.file_name, O_RDONLY);
		read_file(&img, fd);
		close(fd);
		// print_term(&img);		
		mlx(&img);
	}
	return (0);
}
