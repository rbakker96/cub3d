/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:23:10 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/06 14:44:22 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		calculate_variables(t_data *data, t_raycasting *raycasting, int i)
{
	reset_variables(raycasting);
	initialize_plane(raycasting);
	initialize_camera_x(data, raycasting, i);
	start_and_current_position(data, raycasting);
	view_direction(data, raycasting);
	ray_direction(raycasting);
	delta_distance(raycasting);
	step_size(raycasting);
	side_distance(raycasting);
}

void		render(t_data *data, t_raycasting *raycasting,
					t_mlx_data *mlx_data, int i)
{
	while (i < WIDTH)
	{
		calculate_variables(data, raycasting, i);
		identify_wall(data, raycasting);
		prep_wall_distance(raycasting);
		draw_wall(data, raycasting, mlx_data, i);
		i++;
	}
}




