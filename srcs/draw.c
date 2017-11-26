/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 06:37:43 by dpearson          #+#    #+#             */
/*   Updated: 2017/11/08 06:37:44 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		transform_point_x(t_img *img, int x, int y)
{
	double z;
	double beta = .3;
	double gamma = 0;

	z = img->map[y][x] * img->width * 10000 / 100000 * img->ln_count;
	y *= img->width;
	x *= img->width;
	x = cos(beta) * (x * cos(gamma) - y * sin(gamma)) + z * sin(beta);
	return (x);
}

int		transform_point_y(t_img *img, int x, int y)
{
	double z;
	double a = 0;
	double b = .3;
	double g = 0;

	z = img->map[y][x] * img->width * 10000 / 100000 * img->ln_count;
	y *= img->width;
	x *= img->width;
	y = sin(a) * sin(b) * (x * cos(g) - y * sin(g)) + cos(b) * (z * sin(a) + x * sin(g)) + y * cos(a) * cos(g);
	return (y);
}
 
void	draw(t_img *img)
{
	int x;
	int y;
	int z;

	y = 0;
	while (y < img->ln_count)
	{
		x = 0;
		while (x < img->width)
		{
			z = img->map[y][x];
			if (z < 5)
				mlx_pixel_put(img->mlx, img->win, transform_point_x(img, x, y), transform_point_y(img, x, y), 0x0000FF00);
			else
				mlx_pixel_put(img->mlx, img->win, transform_point_x(img, x, y), transform_point_y(img, x, y), 0x00FF0000);		
			x++;
		}
		y++;
	}
}
