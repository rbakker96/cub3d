/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform_position.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 12:05:28 by roybakker      #+#    #+#                */
/*   Updated: 2020/04/02 14:09:52 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		transform_sprite_position(t_data *data, int i)
{
	SPRITE_X = data->texture_data.sprite_texture.sprite_position[i].position.x - POS_X;
	SPRITE_Y = data->texture_data.sprite_texture.sprite_position[i].position.y - POS_Y;
	MATRIX = 1.0 / (PLANE_X * DIR_Y - DIR_X * PLANE_Y);
	TRANSFORM_X = MATRIX * (DIR_Y * SPRITE_X - DIR_X * SPRITE_Y);
	TRANSFORM_Y = MATRIX * (-PLANE_Y * SPRITE_X + PLANE_X * SPRITE_Y);
	SPLITSCREEN_X = ((WIDTH / 2) * (1 + TRANSFORM_X / TRANSFORM_Y));
}
