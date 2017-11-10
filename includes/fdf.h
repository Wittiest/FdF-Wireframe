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

typedef	struct	s_vector3
{
	int		x;
	int		y;
	int		z;
}				t_vector3;


typedef	struct	s_mesh
{
	t_vector3	position; // location of center of object
	t_vector3	rotation;
	// linked list of vertices
}				t_mesh;

typedef	struct	s_cam
{
	t_vector3	position;
	t_vector3	target;
}				t_cam;

typedef struct	s_img
{
	void		*mlx;
	void		*win;
	char		*file_name;
	int			ln_count;
	int			width;
	int			**map;
}				t_img;

void			read_file(t_img *img, int fd);
void			mlx(t_img *img);
void			draw(t_img img);
//prototype everything or make it static

#endif
