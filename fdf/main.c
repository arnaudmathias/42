/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:17:52 by amathias          #+#    #+#             */
/*   Updated: 2016/01/11 15:39:59 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_map *map)
{
	//map->env.img = mlx_new_image(map->env.mlx, 640, 480);
	draw_iso(map->env, map->grid, map->height, map->width);
	return (0);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	print_grid(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j].z == 10)
				printf(" %d",map->grid[i][j].x);
			else
				printf("  %d",map->grid[i][j].x);
			j++;
		}
	printf("\n");
	i++;
	}
}

void	shift_grid(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->grid[i][j].x -= (map->width / 2);
			map->grid[i][j].y -= (map->height / 2);
			map->grid[i][j].x *= WIDTH;
			map->grid[i][j].y *= WIDTH;
			map->grid[i][j].x -= map->grid[i][j].z;
			map->grid[i][j].y -= map->grid[i][j].z;
			map->grid[i][j] = convertcord(map->grid[i][j]);
			j++;
		}
	i++;
	}
}

int		main(int argc, char **argv)
{
	t_env e;
	t_map *map;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "42");
	if (argc != 2)
		ft_error();
	else
	{
		if (!(map = get_map(argv[1])))
			ft_error();
		map->env = e;
		print_grid(map);
		shift_grid(map);
		printf("\n");
		print_grid(map);
		adapt_grid(map);
		mlx_expose_hook(e.win, expose_hook, map);
	}
	mlx_loop(e.mlx);
	sleep(5);
	if (argc == 1)
		argv[0] = NULL;
	return (0);
}
