/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:15:38 by rbakker        #+#    #+#                */
/*   Updated: 2020/02/27 11:36:22 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	t_data		data;
//	t_mlx_data	mlx_data;

	parse_file(argv, argc, &data);
	print_struct(data);
//	mlx_data.mlx = mlx_init();
//	mlx_data.mlx_win = mlx_new_window(mlx_data.mlx, data.resolution.x,
//										data.resolution.y, "Hello world!");
//	mlx_data.img = mlx_new_image(mlx_data.mlx, data.resolution.x,
//									data.resolution.y);
//	mlx_data.addr = mlx_get_data_addr(mlx_data.img, &mlx_data.bits_per_pixel,
//									&mlx_data.line_length, &mlx_data.endian);
//
//	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win, mlx_data.img, 0, 0);
//	mlx_loop(mlx_data.mlx);
//	print_output(&data);
// 	free_memory(&data, 0, 0);
	return (0);
}

