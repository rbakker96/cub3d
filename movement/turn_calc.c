/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turn_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 14:07:05 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/08 11:42:05 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	turn_right(t_data *data)
{
	data->raycast.old_dir.x = data->raycast.dir.x;
	data->raycast.dir.x = data->raycast.dir.x * cos(0.06) - data->raycast.dir.y
																	* sin(0.06);
	data->raycast.dir.y = data->raycast.old_dir.x * sin(0.06) +
												data->raycast.dir.y * cos(0.06);
	data->raycast.old_plane.x = data->raycast.plane.x;
	data->raycast.plane.x = data->raycast.plane.x * cos(0.06) -
											data->raycast.plane.y * sin(0.06);
	data->raycast.plane.y = data->raycast.old_plane.x * sin(0.06) +
											data->raycast.plane.y * cos(0.06);
}

void	turn_left(t_data *data)
{
	data->raycast.old_dir.x = data->raycast.dir.x;
	data->raycast.dir.x = data->raycast.dir.x * cos(-0.06) - data->raycast.dir.y
																* sin(-0.06);
	data->raycast.dir.y = data->raycast.old_dir.x * sin(-0.06) +
											data->raycast.dir.y * cos(-0.06);
	data->raycast.old_plane.x = data->raycast.plane.x;
	data->raycast.plane.x = data->raycast.plane.x * cos(-0.06) -
											data->raycast.plane.y * sin(-0.06);
	data->raycast.plane.y = data->raycast.old_plane.x * sin(-0.06) +
											data->raycast.plane.y * cos(-0.06);
}
