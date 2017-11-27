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

void	put_colored_pixel(t_pair point_start, t_pair point_end, t_img *img)
{
	int tog;

	tog = 1;
	if (img->c_tog == -1)
	{
		tog = rand();
	}
	if (point_start.color > point_end.color)
		mlx_pixel_put(img->mlx, img->win, point_start.x + img->x,
		point_start.y + img->y, point_start.color * tog);
	else
		mlx_pixel_put(img->mlx, img->win, point_start.x + img->x,
		point_start.y + img->y, point_end.color * tog);
}

void	draw_line(t_pair point_start, t_pair point_end, t_img *img, int dx)
{
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dy = abs(point_end.y - point_start.y);
	sx = point_start.x < point_end.x ? 1 : -1;
	sy = point_start.y < point_end.y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (point_start.x != point_end.x || point_start.y != point_end.y)
	{
		put_colored_pixel(point_start, point_end, img);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			point_start.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			point_start.y += sy;
		}
	}
}

void	draw(t_img *img)
{
	int x;
	int y;

	y = 0;
	while (y < img->ln_count)
	{
		x = 0;
		while (x < img->width)
		{
			if (x + 1 < img->width)
				draw_line(img->render_head[y][x], img->render_head[y][x + 1],
			img, abs(img->render_head[y][x].x - img->render_head[y][x + 1].x));
			if (y + 1 < img->ln_count)
				draw_line(img->render_head[y][x], img->render_head[y + 1][x],
			img, abs(img->render_head[y][x].x - img->render_head[y + 1][x].x));
			x++;
		}
		y++;
	}
}
