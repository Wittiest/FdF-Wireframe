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
# define FDF_H

# include "../libs/miniLibX/mlx.h"
# include "../libs/libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>

# define WIDTH 1600
# define HEIGHT 1200

typedef struct	s_pair
{
	int			x;
	int			y;
	int			color;
}				t_pair;

typedef struct	s_img
{
	void		*mlx;
	void		*win;
	char		*file_name;
	int			ln_count;
	int			width;
	int			**map;
	t_pair		**render_head;
	double		a;
	double		b;
	double		g;
	double		zoom;
	int			x;
	int			y;
	int			c_tog;
}				t_img;

void			read_file(t_img *img, int fd);
void			mlx(t_img *img);
void			draw(t_img *img);
void			create_pair_list(t_img *img);
void			update_pair_list(t_img *img);
int				transform_point_x(t_img *img, int x, int y);
int				transform_point_y(t_img *img, int x, int y);
int				define_color(int z);
int				key_hook(int keycode, t_img *img);

#endif
