/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_dimensions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 14:00:44 by roybakker      #+#    #+#                */
/*   Updated: 2020/04/02 11:47:01 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		sprite_dimensions(t_data *data)
{
	sprite_height(data);
	sprite_width(data);
	STRIPE = DRAW_START_X;
	printf("stripe %d \n", STRIPE);
}

void		sprite_height(t_data *data)
{
	SPRITE_HEIGHT = abs((int)(HEIGHT / TRANSFORM_Y));
	DRAW_START_Y = -SPRITE_HEIGHT / 2 + HEIGHT / 2;
	if (DRAW_START_Y < 0)
		DRAW_START_Y = 0;
	DRAW_END_Y = SPRITE_HEIGHT / 2 + HEIGHT / 2;
	if (DRAW_END_Y)
		DRAW_END_Y = HEIGHT - 1;
	printf("draw start Y %d \n", DRAW_START_Y);
	printf("draw end Y %d \n", DRAW_END_Y);
}

void		sprite_width(t_data *data)
{
	SPRITE_WIDTH = abs((int)(HEIGHT / TRANSFORM_Y));
	DRAW_START_X = -SPRITE_WIDTH / 2 + SPLITSCREEN_X;
	if (DRAW_START_X < 0)
		DRAW_START_X = 0;
	DRAW_END_X = SPRITE_WIDTH / 2 + SPLITSCREEN_X;
	if (DRAW_END_X >= WIDTH)
		DRAW_END_X = WIDTH - 1;
	printf("draw start X %d \n", DRAW_START_X);
	printf("draw end X %d \n", DRAW_END_X);
}
