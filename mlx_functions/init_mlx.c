/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 10:57:45 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/19 11:15:27 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx_data.mlx = mlx_init();
	if (!data->mlx_data.mlx)
		parse_error(31, 0, 0);
	open_window(data);
	create_new_image(data);
	get_data_addres(data);
}

void	open_window(t_data *data)
{
	data->mlx_data.mlx_win = mlx_new_window(data->mlx_data.mlx, data->resolution.x, data->resolution.y, "Cub3d");
	if (!data->mlx_data.mlx_win)
		parse_error(32, 0, 0);
}

void	create_new_image(t_data *data)
{
	data->mlx_data.img = mlx_new_image(data->mlx_data.mlx, data->resolution.x, data->resolution.y);
	if (!data->mlx_data.img)
		parse_error(33 , 0, 0);
}

void	get_data_addres(t_data *data)
{
	data->mlx_data.addr = mlx_get_data_addr(data->mlx_data.img, &data->mlx_data.bits_per_pixel,&data->mlx_data.line_length, &data->mlx_data.endian);
	if (!data->mlx_data.addr)
		parse_error(34, 0, 0);
}
