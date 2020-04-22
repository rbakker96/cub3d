/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 10:57:45 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/21 13:32:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		parse_error(31, data, 0, 0);
	open_window(data);
	create_new_image(data);
	get_data_addres(data);
	create_texture_images(data);
	create_sprite_image(data);
}

void	open_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->res.x, data->res.y,
																	"Cub3d");
	if (!data->mlx_win)
		parse_error(32, data, 0, 0);
}

void	create_new_image(t_data *data)
{
	data->image_one.img = mlx_new_image(data->mlx, data->res.x, data->res.y);
	data->image_one.usage = off_screen;
	if (!data->image_one.img)
		parse_error(33, data, 0, 0);
	data->image_two.img = mlx_new_image(data->mlx, data->res.x, data->res.y);
	data->image_two.usage = off_screen;
	if (!data->image_two.img)
		parse_error(33, data, 0, 0);
}

void	get_data_addres(t_data *data)
{
	data->image_one.addr = mlx_get_data_addr(data->image_one.img,
		&data->image_one.bpp, &data->image_one.line_len,
		&data->image_one.endian);
	if (!data->image_one.addr)
		parse_error(34, data, 0, 0);
	data->image_two.addr = mlx_get_data_addr(data->image_two.img,
							&data->image_two.bpp, &data->image_two.line_len,
							&data->image_two.endian);
	if (!data->image_two.addr)
		parse_error(34, data, 0, 0);
}
