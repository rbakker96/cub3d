/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_sprite.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/26 09:38:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/16 11:48:55 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		create_sprite_image(t_data *data)
{
	data->sprite.mlx.img = mlx_png_file_to_image(data->mlx,data->sprite.path,
						&data->sprite.res.y, &data->sprite.res.x);
	if (!data->sprite.mlx.img)
		parse_error(33, data, 0, 0);
	data->sprite.mlx.addr = mlx_get_data_addr(data->sprite.mlx.img,
						&data->sprite.mlx.bpp, &data->sprite.mlx.line_len,
						&data->sprite.mlx.endian);
	if (!data->sprite.mlx.addr)
		parse_error(34, data, 0, 0);
}
