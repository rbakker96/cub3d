/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 15:23:10 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/25 18:59:29 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		pre_calculations(t_data *data)
{
	reset_variables(data);
	initialize_plane(data);
	start_position(data);
	view_direction(data);
	set_floor_and_ceilling_dcolor(data);
	render_screen(data, 0);
}

void		calculate_variables(t_data *data, int i)
{
	camera_x(data, i);
	current_position(data);
	ray_direction(data);
	delta_distance(data);
	step_size(data);
	side_distance(data);
	identify_wall(data);
	prep_wall_distance(data);
}

void		render_screen(t_data *data, int i)
{
	while (i < WIDTH)
	{
		calculate_variables(data, i);
		draw_screen(data, i);
		i++;
	}
	if (data->mlx_data.image_one.usage == off_screen)
	{
		mlx_put_image_to_window(data->mlx_data.mlx, data->mlx_data.mlx_win,
								data->mlx_data.image_one.img, 0, 0);
		data->mlx_data.image_one.usage = on_screen;
		data->mlx_data.image_two.usage = off_screen;
	}
	else
	{
		mlx_put_image_to_window(data->mlx_data.mlx, data->mlx_data.mlx_win,
								data->mlx_data.image_two.img, 0, 0);
		data->mlx_data.image_two.usage = on_screen;
		data->mlx_data.image_one.usage = off_screen;
	}
}
