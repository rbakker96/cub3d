/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_dimensions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 14:00:44 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/17 13:34:46 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		sprite_dimensions(t_data *data)
{
	sprite_height(data);
	sprite_width(data);
	data->sprites.stripe = data->sprites.draw_start_x;
}

void		sprite_height(t_data *data)
{
	data->sprites.height = abs((int)(data->res.y / data->sprites.transform_y));
	data->sprites.draw_start_y = -data->sprites.height / 2 + data->res.y / 2;
	if (data->sprites.draw_start_y < 0)
		data->sprites.draw_start_y = 0;
	data->sprites.draw_end_y = data->sprites.height / 2 + data->res.y / 2;
	if (data->sprites.draw_end_y > data->res.y)
		data->sprites.draw_end_y = data->res.y - 1;
}

void		sprite_width(t_data *data)
{
	data->sprites.width = abs((int)(data->res.y / data->sprites.transform_y));
	data->sprites.draw_start_x = -data->sprites.width / 2 +
												data->sprites.spritescreen;
	if (data->sprites.draw_start_x < 0)
		data->sprites.draw_start_x = 0;
	data->sprites.draw_end_x = data->sprites.width / 2 +
													data->sprites.spritescreen;
	if (data->sprites.draw_end_x >= data->res.x)
		data->sprites.draw_end_x = data->res.x - 1;
}
