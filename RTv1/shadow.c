/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:23:44 by amathias          #+#    #+#             */
/*   Updated: 2016/03/10 13:01:15 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	init_lightpos(t_vec lightpos)
{
	t_vec light;

	light.x = lightpos.x - 20.0;
	light.y = lightpos.y;
	light.z = lightpos.z - 20.0;
	return (light);
}

t_vec	get_lightpos(t_vec lightpos, double off_x, double off_y)
{
	t_vec light;

	light = init_lightpos(lightpos);
	light.x += off_x;
	light.z += off_y;
	return (light);
}

int		get_shadow_color(int color, int nb)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	double			div;

	div = (((nb) * (1.7 - 0.4)) / 256.0) + 0.4;
	red = (color & 0xFF0000) >> 16;
	green = (color & 0xFF00) >> 8;
	blue = color & 0xFF;
	red *= div;
	blue *= div;
	green *= div;
	red = red > 255 ? 255 : red;
	blue = blue > 255 ? 255 : blue;
	green = green > 255 ? 255 : green;
	return (red << 16 | green << 8 | blue);
}

double	rand_double(void)
{
	return (rand() / (RAND_MAX / (2.5)));
}

int		get_shadow(t_map *map, void *shape, t_vec inter, int color)
{
	t_sphere	*light;
	t_pos		pos;
	int			count;
	t_sphere	*sph;
	t_vec		offset;

	sph = shape;
	pos.y = -1;
	count = 0;
	//printf("inter.x: %f| inter.y: %f| inter.z: %f\n", inter.z, inter.z, inter.z);
	while (++pos.y < 16 && (pos.x = -1))
	{
		while (++pos.x < 16)
		{
			offset.x = (pos.x * 2.5) + rand_double();
			offset.y = (pos.y * 2.5) + rand_double();
			light = (t_sphere*)iter(map,
				ray_light(inter, get_lightpos(map->scene.light, offset.x, offset.y))
				, get_lightpos(map->scene.light, offset.x, offset.y));
			if (shape == light)
				count++;
		}
	}
	return (get_shadow_color(get_color(shape, inter,
					ray_light(inter, map->scene.light), color), count));
}
