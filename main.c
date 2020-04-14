/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:15:38 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/09 13:46:35 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	print_struct(t_data data)
{
	int i;

	i = 0;
	printf("res x value = %d \n", data.res.x);
	printf("res y value = %d \n", data.res.y);
	printf("\n");
	printf("Path input north = %s \n", data.north.path);
	printf("Path input south = %s \n", data.south.path);
	printf("Path input east = %s \n", data.east.path);
	printf("Path input west = %s \n", data.west.path);
	printf("Path input sprite = %s \n", data.sprite.path);
	printf("\n");
	printf("Floor color R = %d \n", data.color.floor.r);
	printf("Floor color G = %d \n", data.color.floor.g);
	printf("Floor color B = %d \n", data.color.floor.b);
	printf("\n");
	printf("Ceilling color R = %d \n", data.color.ceilling.r);
	printf("Ceilling color G = %d \n", data.color.ceilling.g);
	printf("Ceilling color B = %d \n", data.color.ceilling.b);
	printf("\n");
	while (data.map.map[i] != 0)
	{
		printf("%s \n", data.map.map[i]);
		i++;
	}
	printf("\n");
}

int		main(int argv, char **argc)
{
	t_data			data;

	parse_file(argv, argc, &data);
	print_struct(data);
	init_mlx(&data);
	pre_calculations(&data);
	mlx_hook(data.mlx_win, CLOSE, 1L << 17, &button_close_screen, &data);
	mlx_hook(data.mlx_win, KEYPRESS, 1L << 0, &key_press, &data);
	mlx_hook(data.mlx_win, KEYRELEASE, 1L << 1, &key_release, &data);
	mlx_loop_hook(data.mlx, &process_movement, &data);
	mlx_loop(data.mlx);
	return (0);
}
