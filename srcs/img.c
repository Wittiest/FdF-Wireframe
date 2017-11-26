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
#include <stdio.h>
void	esc_key(t_img *img)
{
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
}

int		key_hook(int keycode, t_img *img)
{
	if (keycode == 53)
		esc_key(img);
	if (keycode == 2)
	{
		img->b += .05;
		update_pair_list(img);
		mlx_clear_window(img->mlx, img->win);
		draw(img);
	}
	if (keycode == 0)
	{
		img->b -= .05;
		update_pair_list(img);
		mlx_clear_window(img->mlx, img->win);
		draw(img);
	}	
	// if (keycode == KEY_M)
	// 	view->project = view->project ? 0 : 1;
	// toggle_pressed(keycode, view, 1);
	return (0);
}

void	mlx(t_img *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "FDF");
	//hook up key presses
	mlx_key_hook(img->win, &key_hook, img);
	draw(img);
	mlx_loop(img->mlx);
}