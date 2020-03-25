/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_texture.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 14:09:33 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/25 20:10:47 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		create_texture_images(t_data *data)
{
	east_texture_image(data);
	north_texture_image(data);
	south_texture_image(data);
	west_texture_image(data);
}

void		east_texture_image(t_data *data)
{
	IMG_east = mlx_png_file_to_image(MLX, PATH_east, &TEX_WIDTH_east,
															&TEX_HEIGHT_east);
	if (!IMG_east)
		parse_error(33 , 0, 0);
	ADDRES_east = mlx_get_data_addr(IMG_east, &BPP_east, &LL_east,
																&ENDIAN_east);
	if (!ADDRES_east)
		parse_error(34, 0, 0);
}

void		north_texture_image(t_data *data)
{
	IMG_north = mlx_png_file_to_image(MLX, PATH_north, &TEX_WIDTH_north,
															&TEX_HEIGHT_north);
	if (!IMG_north)
		parse_error(33 , 0, 0);
	ADDRES_north = mlx_get_data_addr(IMG_north, &BPP_north, &LL_north,
																&ENDIAN_north);
	if (!ADDRES_north)
		parse_error(34, 0, 0);
}

void		south_texture_image(t_data *data)
{
	IMG_south = mlx_png_file_to_image(MLX, PATH_south, &TEX_WIDTH_south,
															&TEX_HEIGHT_south);
	if (!IMG_south)
		parse_error(33 , 0, 0);
	ADDRES_south = mlx_get_data_addr(IMG_south, &BPP_south, &LL_south,
																&ENDIAN_south);
	if (!ADDRES_south)
		parse_error(34, 0, 0);
}

void		west_texture_image(t_data *data)
{
	IMG_west = mlx_png_file_to_image(MLX, PATH_west, &TEX_WIDTH_west,
															&TEX_HEIGHT_west);
	if (!IMG_west)
		parse_error(33 , 0, 0);
	ADDRES_west = mlx_get_data_addr(IMG_west, &BPP_west, &LL_west,
																&ENDIAN_west);
	if (!ADDRES_west)
		parse_error(34, 0, 0);
}
