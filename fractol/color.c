/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 14:13:19 by amathias          #+#    #+#             */
/*   Updated: 2016/01/25 10:48:19 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		*init_mandelbrot_color(int max_iter)
{
	int *color_array;
	int i;
	int tmp;

	tmp = 0xff6600;
	if ((color_array = (int *)malloc(sizeof(int) * max_iter + 1)) == NULL)
		return (NULL);
	i = 0;
	printf("%#08x\n", 0xff6600 - 0xff1a75);
	printf("%#08x\n", 0xe65c00 - 0xff6600);
	while (i < max_iter + 1)
	{
		tmp += 0x000301;
		printf("%#08x\n",tmp);
		if (i == max_iter)
			color_array[i] = 0x000000;
		else
			color_array[i] = tmp;
		i++;
	}
	return (color_array);	
}

int		*init_julia_color(int max_iter)
{
	int *color_array;
	int i;
	int tmp;

	tmp = 0xff6600;
	if ((color_array = (int *)malloc(sizeof(int) * max_iter + 1)) == NULL)
		return (NULL);
	i = 0;
	printf("%#08x\n", 0xff6600 - 0xff1a75);
	printf("%#08x\n", 0xe65c00 - 0xff6600);
	while (i < max_iter + 1)
	{
		tmp += 0x000301;
		if (tmp > 0xffffff)
			tmp = 0x05bfff;
		printf("%#08x\n",tmp);
		color_array[i] = tmp;
		i++;
	}
	return (color_array);	
}