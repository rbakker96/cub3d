/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   direction_calc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:40:29 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/21 13:32:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		set_view_direction(t_data *data)
{
	if (data->map.spawning_point == 'S')
	{
		data->raycast.dir.x = 0.0;
		data->raycast.dir.y = 1.0;
	}
	if (data->map.spawning_point == 'W')
	{
		data->raycast.dir.x = -1.0;
		data->raycast.dir.y = 0.0;
	}
	if (data->map.spawning_point == 'E')
	{
		data->raycast.dir.x = 1.0;
		data->raycast.dir.y = 0.0;
	}
	if (data->map.spawning_point == 'N')
	{
		data->raycast.dir.x = 0.0;
		data->raycast.dir.y = -1.0;
	}
}

void		ray_direction(t_data *data)
{
	data->raycast.ray_dir.x = data->raycast.dir.x + data->raycast.plane.x *
														data->raycast.camera_x;
	data->raycast.ray_dir.y = data->raycast.dir.y + data->raycast.plane.y *
														data->raycast.camera_x;
}

void		step_size(t_data *data)
{
	if (data->raycast.ray_dir.x < 0)
		data->raycast.step.x = -1;
	else
		data->raycast.step.x = 1;
	if (data->raycast.ray_dir.y < 0)
		data->raycast.step.y = -1;
	else
		data->raycast.step.y = 1;
}
