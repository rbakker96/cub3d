/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_texture.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 12:09:39 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/17 12:09:42 by roybakker     ########   odam.nl         */
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
	data->east.mlx.img = mlx_png_file_to_image(data->mlx, data->east.path,
								&data->east.tex_res.y, &data->east.tex_res.x);
	if (!data->east.mlx.img)
		parse_error(33, data, 0, 0);
	data->east.mlx.addr = mlx_get_data_addr(data->east.mlx.img,
								&data->east.mlx.bpp, &data->east.mlx.line_len,
								&data->east.mlx.endian);
	if (!data->east.mlx.addr)
		parse_error(34, data, 0, 0);
}

void		north_texture_image(t_data *data)
{
	data->north.mlx.img = mlx_png_file_to_image(data->mlx, data->north.path,
								&data->north.tex_res.y, &data->north.tex_res.x);
	if (!data->north.mlx.img)
		parse_error(33, data, 0, 0);
	data->north.mlx.addr = mlx_get_data_addr(data->north.mlx.img,
								&data->north.mlx.bpp, &data->north.mlx.line_len,
								&data->north.mlx.endian);
	if (!data->north.mlx.addr)
		parse_error(34, data, 0, 0);
}

void		south_texture_image(t_data *data)
{
	data->south.mlx.img = mlx_png_file_to_image(data->mlx, data->south.path,
								&data->south.tex_res.y, &data->south.tex_res.x);
	if (!data->south.mlx.img)
		parse_error(33, data, 0, 0);
	data->south.mlx.addr = mlx_get_data_addr(data->south.mlx.img,
								&data->south.mlx.bpp, &data->south.mlx.line_len,
								&data->south.mlx.endian);
	if (!data->south.mlx.addr)
		parse_error(34, data, 0, 0);
}

void		west_texture_image(t_data *data)
{
	data->west.mlx.img = mlx_png_file_to_image(data->mlx, data->west.path,
								&data->west.tex_res.y, &data->west.tex_res.x);
	if (!data->west.mlx.img)
		parse_error(33, data, 0, 0);
	data->west.mlx.addr = mlx_get_data_addr(data->west.mlx.img,
								&data->west.mlx.bpp, &data->west.mlx.line_len,
								&data->west.mlx.endian);
	if (!data->west.mlx.addr)
		parse_error(34, data, 0, 0);
}
