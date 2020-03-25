/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 09:14:55 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/25 20:16:17 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		draw_screen(t_data *data, int x)
{
	LINE_HEIGHT = (int)(HEIGHT / WALL_DIS);
	DRAW_START = -LINE_HEIGHT / 2 + HEIGHT / 2;
	if (DRAW_START < 0)
		DRAW_START = 0;
	DRAW_END = LINE_HEIGHT / 2 + HEIGHT / 2;
	if (DRAW_END >= HEIGHT)
		DRAW_END = HEIGHT - 1;
	calculate_texture_variables(data);
	draw_ceilling(data, x);
	draw_wall(data, x);
	draw_floor(data, x);
}

void	draw_ceilling(t_data *data, int x)
{
	int y;

	y = 0;
	while (y < DRAW_START)
	{
		pixel_to_image(data, x, y, data->color.ceilling_color.color);
		y++;
	}
}

void	draw_wall(t_data *data, int x)
{
	int y;

	y = DRAW_START;
	while (y < DRAW_END)
	{
		place_texture_color(data, x, y);
		y++;
	}
}

void	draw_floor(t_data *data, int x)
{
	int y;

	y = DRAW_END;
	while (y < HEIGHT)
	{
		pixel_to_image(data, x, y, data->color.floor_color.color);
		y++;
	}
}
