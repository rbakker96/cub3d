/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform_position.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 12:05:28 by roybakker      #+#    #+#                */
/*   Updated: 2020/04/02 12:10:12 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		transform_sprite_position(t_data *data, int i)
{
	SPRITE_X = data->texture_data.sprite_texture.sprite_position[i].position.x - POS_X;
	printf("sprite x %f \n", SPRITE_X);
	SPRITE_Y = data->texture_data.sprite_texture.sprite_position[i].position.y - POS_Y;
	printf("sprite y %f \n", SPRITE_Y);
	printf("plane x %f \n", PLANE_X);
	printf("dir y %f \n", DIR_Y);
	printf("dir x %f \n", DIR_X);
	printf("plane y %f \n", PLANE_Y);
	MATRIX = (1.0 / (PLANE_X * DIR_Y - DIR_X * PLANE_Y)) *-1;
	printf("matrix %f \n", MATRIX);
	TRANSFORM_X = MATRIX * (DIR_Y * SPRITE_X - DIR_X * SPRITE_Y);
	printf("transform x %f \n", TRANSFORM_X);
	TRANSFORM_Y = MATRIX * (-PLANE_Y * SPRITE_X + PLANE_X * SPRITE_Y);
	printf("transform y %f \n", TRANSFORM_Y);
	SPLITSCREEN_X = ((WIDTH / 2) * (1 + TRANSFORM_X / TRANSFORM_Y));
	printf("sprite screen x %d \n", SPLITSCREEN_X);
}
