/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 06:22:30 by dpearson          #+#    #+#             */
/*   Updated: 2017/11/08 06:22:30 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		key_hook1(int keycode, t_img *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	else if (keycode == 34)
	{
		img->zoom += 1;
		update_pair_list(img);
	}
	else if (keycode == 31)
	{
		img->zoom -= 1;
		update_pair_list(img);
	}
	else if (keycode == 2)
	{
		img->b += .05;
		update_pair_list(img);
	}
	else if (keycode == 0)
	{
		img->b -= .05;
		update_pair_list(img);
	}
}

int				key_hook(int keycode, t_img *img)
{
	key_hook1(keycode, img);
	if (keycode == 8)
		img->c_tog *= -1;
	else if (keycode == 13)
	{
		img->a -= .05;
		update_pair_list(img);
	}
	else if (keycode == 1)
	{
		img->a += .05;
		update_pair_list(img);
	}
	else if (keycode == 126)
		img->y -= HEIGHT / 50;
	else if (keycode == 125)
		img->y += HEIGHT / 50;
	else if (keycode == 123)
		img->x -= WIDTH / 50;
	else if (keycode == 124)
		img->x += WIDTH / 50;
	mlx_clear_window(img->mlx, img->win);
	draw(img);
	return (0);
}

void			mlx(t_img *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "FDF");
	mlx_key_hook(img->win, &key_hook, img);
	img->x = WIDTH / 2 - img->width;
	img->y = HEIGHT / 2 - img->ln_count;
	img->zoom = 1;
	img->c_tog = 1;
	create_pair_list(img);
	draw(img);
	mlx_loop(img->mlx);
}
