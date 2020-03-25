/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:15:38 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/25 08:57:34 by roybakker     ########   odam.nl         */
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
	printf("Path input north = %s \n", data.texture_data.north_texture.path);
	printf("Path input south = %s \n", data.texture_data.south_texture.path);
	printf("Path input east = %s \n", data.texture_data.east_texture.path);
	printf("Path input west = %s \n", data.texture_data.west_texture.path);
	printf("Path input sprite = %s \n", data.texture_data.sprite_texture.path);
	printf("\n");
	printf("Floor color R = %d \n", data.color.floor_color.r);
	printf("Floor color G = %d \n", data.color.floor_color.g);
	printf("Floor color B = %d \n", data.color.floor_color.b);
	printf("\n");
	printf("Ceilling color R = %d \n", data.color.ceilling_color.r);
	printf("Ceilling color G = %d \n", data.color.ceilling_color.g);
	printf("Ceilling color B = %d \n", data.color.ceilling_color.b);
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
	mlx_hook(data.mlx_data.mlx_win, KEYPRESS, PRESS_MASK, &key_press, &data);
	mlx_hook(data.mlx_data.mlx_win, KEYRELEASE, RELEASE_MASK, &key_release, &data);
	mlx_loop_hook(data.mlx_data.mlx, &process_movement, &data);
	mlx_loop(data.mlx_data.mlx);
	return (0);
}
