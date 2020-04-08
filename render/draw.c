/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 09:14:55 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/08 10:36:42 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		draw_screen(t_data *data, int x)
{
	data->raycast.lineheight = (int)(data->res.y / data->raycast.wall_dis);
	data->raycast.draw_start = -data->raycast.lineheight / 2 + data->res.y / 2;
	if (data->raycast.draw_start < 0)
		data->raycast.draw_start = 0;
	data->raycast.draw_end = data->raycast.lineheight / 2 + data->res.y / 2;
	if (data->raycast.draw_end >= data->res.y)
		data->raycast.draw_end = data->res.y - 1;
	calculate_texture_variables(data);
	draw_ceilling(data, x);
	draw_wall(data, x);
	draw_floor(data, x);
}

void	draw_ceilling(t_data *data, int x)
{
	int y;

	y = 0;
	while (y < data->raycast.draw_start)
	{
		pixel_to_image(data, x, y, data->color.ceilling.color);
		y++;
	}
}

void	draw_wall(t_data *data, int x)
{
	int y;

	y = data->raycast.draw_start;
	while (y < data->raycast.draw_end)
	{
		place_texture_color(data, x, y);
		y++;
	}
}

void	draw_floor(t_data *data, int x)
{
	int y;

	y = data->raycast.draw_end;
	while (y < data->res.y)
	{
		pixel_to_image(data, x, y, data->color.floor.color);
		y++;
	}
}
