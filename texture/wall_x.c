/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 10:52:46 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/08 10:44:42 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

double	calculate_wall_x(t_data *data)
{
	double wall_x;

	if (data->raycast.side == 0)
		wall_x = data->raycast.pos.y + data->raycast.wall_dis *
														data->raycast.ray_dir.y;
	else
		wall_x = data->raycast.pos.x + data->raycast.wall_dis *
														data->raycast.ray_dir.x;
	wall_x -= (int)wall_x;
	return (wall_x);
}
