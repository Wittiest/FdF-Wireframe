/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 09:23:30 by dpearson          #+#    #+#             */
/*   Updated: 2017/11/26 09:23:31 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		transform_point_x(t_img *img, int x, int y)
{
	double z;

	z = img->map[y][x] * img->width * 10000 / 100000 * img->ln_count;
	y *= img->width;
	x *= img->width;
	x = cos(img->b) * (x * cos(img->g) - y * sin(img->g)) + z * sin(img->b);
	return (x);
}

int		transform_point_y(t_img *img, int x, int y)
{
	double z;

	z = img->map[y][x] * img->width * 10000 / 100000 * img->ln_count;
	y *= img->width;
	x *= img->width;
	y = sin(img->a) * sin(img->b) * (x * cos(img->g) - y * sin(img->g)) +
		cos(img->b) * (z * sin(img->a) + x * sin(img->g)) + y * cos(img->a) *
		cos(img->g);
	return (y);
}

void	create_pair_list(t_img *img)
{
	int x;
	int y;
	t_pair **list;

	list = (t_pair **)(malloc(sizeof(t_pair *) * img->ln_count));
	y = 0;
	while (y < img->ln_count)
	{
		list[y] = (t_pair *)(malloc(sizeof(t_pair) * img->width));
		x = 0;
		while (x < img->width)
		{
			list[y][x].x = transform_point_x(img, x, y);
			list[y][x].y = transform_point_y(img, x, y);
			x++;
		}
		y++;
	}
	img->render_head = list;
}

void	update_pair_list(t_img *img)
{
	int x;
	int y;

	y = 0;
	while (y < img->ln_count)
	{
		x = 0;
		while (x < img->width)
		{
			img->render_head[y][x].x = transform_point_x(img, x, y);
			img->render_head[y][x].y = transform_point_y(img, x, y);
			x++;
		}
		y++;
	}
}