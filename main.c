/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:15:38 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/14 14:34:25 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	print_struct(t_data data)
{
	int i;

	i = 0;
	printf("Resolution x value = %d \n", data.resolution.x);
	printf("Resolution y value = %d \n", data.resolution.y);
	printf("\n");
	printf("Path input north = %s \n", data.north_texture.path);
	printf("Path input south = %s \n", data.south_texture.path);
	printf("Path input east = %s \n", data.east_texture.path);
	printf("Path input west = %s \n", data.west_texture.path);
	printf("Path input sprite = %s \n", data.sprite_texture.path);
	printf("\n");
	printf("Floor color R = %d \n", data.floor_color.r);
	printf("Floor color G = %d \n", data.floor_color.g);
	printf("Floor color B = %d \n", data.floor_color.b);
	printf("\n");
	printf("Ceilling color R = %d \n", data.ceilling_color.r);
	printf("Ceilling color G = %d \n", data.ceilling_color.g);
	printf("Ceilling color B = %d \n", data.ceilling_color.b);
	printf("\n");
	while (data.map[i] != 0)
	{
		printf("%s \n", data.map[i]);
		i++;
	}
	printf("\n");
}

int		main(int argv, char **argc)
{
	t_data			data;

	parse_file(argv, argc, &data);
	print_struct(data);
	data.mlx_data.mlx = mlx_init();
	data.mlx_data.mlx_win = mlx_new_window(data.mlx_data.mlx, data.resolution.x, data.resolution.y, "Cub3d");
	data.mlx_data.img = mlx_new_image(data.mlx_data.mlx, data.resolution.x, data.resolution.y);
	data.mlx_data.addr = mlx_get_data_addr(data.mlx_data.img, &data.mlx_data.bits_per_pixel,&data.mlx_data.line_length, &data.mlx_data.endian);
	spawn_player(&data);
	mlx_hook(data.mlx_data.mlx_win, KEYPRESS, PRESS_MASK, &key_press, &data);
	mlx_hook(data.mlx_data.mlx_win, KEYRELEASE, RELEASE_MASK, &key_release, &data);
	mlx_loop_hook(data.mlx_data.mlx, &process_movement, &data);
	mlx_loop(data.mlx_data.mlx);
	return (0);
}
