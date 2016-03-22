/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:15:30 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 16:29:13 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	vec_multbyscalar(t_vec vec, double sca)
{
	t_vec mult;

	mult.x = vec.x * sca;
	mult.y = vec.y * sca;
	mult.z = vec.z * sca;
	return (mult);
}

void	vec_normalize(t_vec *vec)
{
	double tmp;

	tmp = 1.0 / sqrt(vec_dot(*vec, *vec));
	vec->x *= tmp;
	vec->y *= tmp;
	vec->z *= tmp;
}

double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	vec_project(t_vec v1, t_vec v2)
{
	t_vec	pro;
	double	tmp;

	tmp = (vec_dot(v1, v2) / vec_dot(v2, v2));
	pro = vec_multbyscalar(v2, tmp);
	vec_normalize(&pro);
	return (pro);
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	t_vec sub;

	sub.x = v1.x - v2.x;
	sub.y = v1.y - v2.y;
	sub.z = v1.z - v2.z;
	return (sub);
}
