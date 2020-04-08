/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 15:23:10 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/08 21:37:33 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		pre_calculations(t_data *data)
{
	reset_variables(data);
	initialize_plane(data);
	set_start_position(data);
	set_view_direction(data);
	set_floor_and_ceilling_color(data);
	set_prep_distance_array(data);
	set_sprites_array(data);
	render_screen(data, 0);
}

void		calculate_variables(t_data *data, int x)
{
	camera_x(data, x);
	current_position(data);
	ray_direction(data);
	delta_distance(data);
	step_size(data);
	side_distance(data);
	identify_wall(data);
	prep_wall_distance(data, x);
}

void		render_screen(t_data *data, int x)
{
	while (x < data->res.x)
	{
		calculate_variables(data, x);
		draw_screen(data, x);
		x++;
	}
	cast_sprites(data, 0);
	if (data->image_one.usage == off_screen)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->image_one.img,
																		0, 0);
		data->image_one.usage = on_screen;
		data->image_two.usage = off_screen;
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->image_two.img,
																		0, 0);
		data->image_two.usage = on_screen;
		data->image_one.usage = off_screen;
	}
}
