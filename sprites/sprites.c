/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 13:48:55 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/08 21:24:51 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	calculate_sprite_variables(t_data *data, int i)
{
	transform_sprite_position(data, i);
	sprite_dimensions(data);
}

void	cast_sprites(t_data *data, int i)
{
	int y;

	sprite_position_and_distance(data);
	sort_sprites(data);
	while (i < data->sprite.amount)
	{
		calculate_sprite_variables(data, i);
		while (data->sprites.stripe < data->sprites.draw_end_x)
		{
			data->sprites.tex_x = (int)((256 * (data->sprites.stripe -
						(-data->sprites.width / 2 + data->sprites.spritescreen))
						* data->sprite.res.y / data->sprites.width)) / 256;
			y = data->sprites.draw_start_y;
			if (data->sprites.transform_y > 0 && data->sprites.stripe > 0 &&
				data->sprites.stripe < data->res.x && data->sprites.transform_y
				< data->sprite.dis[data->sprites.stripe])
				while (y < data->sprites.draw_end_y)
				{
					sprite_color(data, y);
					y++;
				}
			data->sprites.stripe++;
		}
		i++;
	}
}
