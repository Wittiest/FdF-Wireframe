/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 03:52:23 by dpearson          #+#    #+#             */
/*   Updated: 2017/11/08 03:52:24 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
#define FDF_H

#include "../libs/miniLibX/mlx.h"
#include "../libs/libft/includes/libft.h"
#include <math.h>
#include <fcntl.h>

#define WIDTH 1600
#define HEIGHT 1200

typedef struct	s_img
{
	void		*mlx;
	void		*win;
	char		*file_name;
	int			ln_count;
	int			width;
	int			**map;
	double		alpha;
	double		beta;
	double		gamma;
}				t_img;

void			read_file(t_img *img, int fd);
void			mlx(t_img *img);
void			draw(t_img *img);
//prototype everything or make it static
//• You must be able to quit the program by pressing ’esc’.
#endif
