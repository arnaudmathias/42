/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:10:42 by amathias          #+#    #+#             */
/*   Updated: 2016/01/24 14:49:31 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_map *map, int max_iter)
{
	int x;
	int y;
	int i;
	int *color_array;
	t_complex c;
	t_complex z;
	t_complex tmp;

	color_array = init_mandelbrot_color(max_iter);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = 1.5 * (x - (WIDTH / 2)) / (WIDTH * map->zoom / 2);
			c.ima = 1.5 * (y - (HEIGHT / 2)) / (HEIGHT * map->zoom / 2);
			z.real = 0.0;
			z.ima = 0.0;
			i = 0;
			while (i < max_iter)
			{
				tmp.real = z.real * z.real - z.ima * z.ima + c.real;
				z.ima = 2 * z.real * z.ima + c.ima;
				z.real = tmp.real;
				i++;
				if (z.real * z.real + z.ima * z.ima > 4)
					break;
			}
			draw_pixel_to_image(map, x, y, color_array[i]);
			x++;
		}
		y++;
	}
}