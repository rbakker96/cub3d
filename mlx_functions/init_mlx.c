/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 10:57:45 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/25 19:34:57 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	init_mlx(t_data *data)
{
	MLX = mlx_init();
	if (!MLX)
		parse_error(31, 0, 0);
	open_window(data);
	create_new_image(data);
	get_data_addres(data);
	create_texture_images(data);
}

void	open_window(t_data *data)
{
	WINDOW = mlx_new_window(MLX, HEIGHT, WIDTH, "Cub3d");
	if (!WINDOW)
		parse_error(32, 0, 0);
}

void	create_new_image(t_data *data)
{
	IMG_ONE = mlx_new_image(MLX, HEIGHT, WIDTH);
	data->mlx_data.image_one.usage = off_screen;
	if (!IMG_ONE)
		parse_error(33 , 0, 0);
	IMG_TWO = mlx_new_image(MLX, HEIGHT, WIDTH);
	data->mlx_data.image_two.usage = off_screen;
	if (!IMG_TWO)
		parse_error(33 , 0, 0);
}

void	get_data_addres(t_data *data)
{
	ADDRES_ONE = mlx_get_data_addr(IMG_ONE, &BPP_ONE, &LL_ONE, &ENDIAN_ONE);
	if (!ADDRES_ONE)
		parse_error(34, 0, 0);
	ADDRES_TWO = mlx_get_data_addr(IMG_TWO, &BPP_TWO, &LL_TWO, &ENDIAN_TWO);
	if (!ADDRES_TWO)
		parse_error(34, 0, 0);
}
