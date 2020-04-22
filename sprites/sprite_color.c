/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_color.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 11:51:16 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/21 13:32:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_color(t_data *data, int y)
{
	int pixel;
	int d;

	d = (y) * 256 - data->res.y * 128 + data->sprites.height * 128;
	data->sprites.tex_y = ((d * data->sprite.res.x) / data->sprites.height) /
																			256;
	pixel = ((data->sprites.tex_y * data->sprite.mlx.line_len) +
						(data->sprites.tex_x * (data->sprite.mlx.bpp / 8)));
	data->sprite.color = *(unsigned int *)(data->sprite.mlx.addr + pixel);
	if ((data->sprite.color & 0x00FFFFFF) != 0)
		pixel_to_image(data, data->sprites.stripe, y, data->sprite.color);
}
