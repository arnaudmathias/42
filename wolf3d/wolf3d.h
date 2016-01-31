/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:28:49 by amathias          #+#    #+#             */
/*   Updated: 2016/01/30 14:13:56 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLD3D_H
# define WOLD3D_H
# include <mlx.h>
# include <math.h>
#include <stdio.h>
# include "libft.h"
# define WIDTH 480
# define HEIGHT 300
# include "libft.h"
# define RED  "\x1B[31m"
# define WHT  "\x1B[37m"
# define RST "\033[0m"
typedef struct 	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}				t_line;

typedef struct 	s_pos
{
	int			x;
	int			y;
	int			r;
	int			color;
}				t_pos;

typedef struct	s_map
{
	t_env		env;
	t_img		img;
	int			type;
	int			**grid;
	int			height;
	int			width;
	t_pos		cpos;

}				t_map;

void			draw(t_map *map);
void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

int				expose_hook(t_map *map);
int				key_hook(int keycode, t_map *map);

void			ray(t_map *map);
void			draw_wall_slice(t_map *map, int x, int height);
void			draw_line(t_map *map, t_pos from, t_pos to, int color);
#endif