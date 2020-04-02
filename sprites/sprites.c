/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 13:48:55 by roybakker      #+#    #+#                */
/*   Updated: 2020/04/02 14:10:03 by roybakker     ########   odam.nl         */
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
	while (i < SPRITE_AMOUNT)
	{
		calculate_sprite_variables(data, i);
		while(STRIPE < DRAW_END_X)
		{
			TEX_X_SPRITE = (int)((256 * (STRIPE - (-SPRITE_WIDTH / 2 + SPLITSCREEN_X))
							* TEX_WIDTH_SPRITE / SPRITE_WIDTH)) / 256;
			y = DRAW_START_Y;
			if (TRANSFORM_Y > 0 && STRIPE > 0 && STRIPE < WIDTH && TRANSFORM_Y < data->texture_data.sprite_texture.distance[STRIPE])
				while (y < DRAW_END_Y)
				{
					sprite_color(data, y);
					y++;
				}
			STRIPE++;
		}
		i++;
	}
}
