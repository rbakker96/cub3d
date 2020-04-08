/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_variables.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:52:21 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/08 10:38:15 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	reset_variables(t_data *data)
{
	data->raycast.pos.x = 0;
	data->raycast.pos.y = 0;
	data->raycast.map.x = 0;
	data->raycast.map.y = 0;
	data->raycast.dir.x = 0;
	data->raycast.dir.y = 0;
	data->raycast.plane.x = 0;
	data->raycast.plane.y = 0;
	data->raycast.side_dis.x = 0;
	data->raycast.side_dis.y = 0;
	data->raycast.delta_dis.x = 0;
	data->raycast.delta_dis.y = 0;
	data->raycast.step.x = 0;
	data->raycast.step.y = 0;
	data->raycast.ray_dir.x = 0;
	data->raycast.ray_dir.y = 0;
	data->raycast.camera_x = 0;
	data->raycast.wall_dis = 0;
	data->raycast.side = 0;
}
