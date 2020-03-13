/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:23:10 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/13 14:36:29 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		spawn_player(t_data *data)
{
	reset_variables(data);
	initialize_plane(data);
	start_position(data);
	view_direction(data);
	render_screen(data, 0);
	mlx_put_image_to_window(data->mlx_data.mlx, data->mlx_data.mlx_win, data->mlx_data.img, 0, 0);
}

void		calculate_variables(t_data *data, int i)
{
	camera_x(data, i);
	current_position(data);
	ray_direction(data);
	delta_distance(data);
	step_size(data);
	side_distance(data);
}

void		render_screen(t_data *data, int i)
{
	while (i < WIDTH)
	{
		calculate_variables(data, i);
		identify_wall(data);
		prep_wall_distance(data);
		draw_screen(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx_data.mlx, data->mlx_data.mlx_win, data->mlx_data.img, 0, 0);
}
