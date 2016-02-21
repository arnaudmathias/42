/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/02/21 14:54:24 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		**init_grid(int row, int col)
{
	int i;
	int j;
	int **grid;

	i = 0;
	if ((grid = (int**)malloc(sizeof(int*) * row)) == NULL)
		return (NULL);
	while (i < row)
	{
		if ((grid[i] = (int*)malloc(sizeof(int) * col)) == NULL)
			return(NULL);
		j = 0;
		while (j < col)
		{
			if (j == 0 || j == col - 1 || i == 0 || i == row - 1)
				grid[i][j] = 1;
			else
				grid[i][j] = 0;
			j++;
		}
		i++;
	}
	/*i = 0;
	while (i < 400)
	{
		grid[rand() % 99][rand () % 99] = 1;
		i++;
	} */
	grid[1][1] = 0;
	grid[3][3] = 2;
	grid[4][4] = 3;
	grid[5][5] = 4;
	grid[6][6] = 5;
	grid[7][7] = 5;
	grid[8][8] = 6;
	grid[1][7] = 6;
	grid[1][5] = 7;
	grid[2][3] = 1;
	return (grid);
}

void	draw(t_map *map)
{
	t_args *arg;

	map->img.img = mlx_new_image(map->env.mlx, WIDTH, HEIGHT);
	map->img.data = mlx_get_data_addr(map->img.img, &(map->img.bpp),
			&(map->img.size_line), &(map->img.endian));
	//init_image(map, 0x000000);
	if (map->multithread)
		multi_thread(map, ray);
	else
	{
		arg = init_thread(map, getpos(0,0), getpos(WIDTH, 0));
		ray(arg);
		//printf("singlethread\n");
		free(arg);
	}
	if (map->pause)
		pause_on(map);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);	
	if (map->pause)
		mlx_string_put(map->env.mlx, map->env.win,
				(WIDTH /2) - 24, (HEIGHT / 2) - 10, 0xffffff, "PAUSE");
	//draw_mmap(map);
	mlx_destroy_image(map->env.mlx,map->img.img);
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
			printf(" %d",map->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	init_map(t_map *map)
{
	map->height = 15;
	map->width = 15;
	map->grid = init_grid(map->height, map->width);
	map->tex = init_tex_array(9);
	map->multithread = 1;
	map->pause = 0;
	map->pos.x = 2.5;
	map->pos.y = 2.5;
	map->cvec.x = 0.0;
	map->cvec.y = 0.66;
	map->dirvec.x = -1.0;
	map->dirvec.y = 0.0;
	init_key(map);	
}

int		main(void)
{
	t_env e;
	t_map *map;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Wolf3d");
	map = (t_map*)malloc(sizeof(t_map));
	map->env = e;
	init_map(map);
	print_grid(map);
	mlx_key_hook(e.win, key_hook, map);
	mlx_hook(e.win, 2, (1L << 0), key_press, map);
	mlx_loop_hook(e.mlx, loop_hook, map);
	mlx_expose_hook(e.win, expose_hook, map);
	mlx_loop(e.mlx);
	return (0);
}
