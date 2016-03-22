/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 14:16:51 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 16:06:35 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		light_rgb(int rgb, double angle)
{
	int		red;
	int		green;
	int		blue;

	red = (rgb & 0xFF0000) >> 16;
	green = (rgb & 0xFF00) >> 8;
	blue = rgb & 0xFF;
	red *= angle;
	blue *= angle;
	green *= angle;
	red = red > 255 ? 255 : red;
	blue = blue > 255 ? 255 : blue;
	green = green > 255 ? 255 : green;
	rgb = red << 16 | green << 8 | blue;
	return (rgb);
}

int		get_color(void *shape, t_vec inter, t_vec light, int color)
{
	t_vec		nor;
	double		angle;
	int			c;
	t_sphere	*sph;

	(void)inter;
	sph = shape;
	nor = sph->normal;
	angle = vec_dot(nor, light);
	if (angle <= 0.0)
		c = 0x000000;
	else
		c = light_rgb(color, angle);
	return (c);
}
