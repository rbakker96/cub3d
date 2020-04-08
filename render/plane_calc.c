/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_calc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:44:57 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/08 10:36:57 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		initialize_plane(t_data *data)
{
	if (data->map.spawning_point == 'W')
	{
		data->raycast.plane.x = 0;
		data->raycast.plane.y = -0.66;
	}
	if (data->map.spawning_point == 'E')
	{
		data->raycast.plane.x = 0;
		data->raycast.plane.y = 0.66;
	}
	if (data->map.spawning_point == 'N')
	{
		data->raycast.plane.x = 0.66;
		data->raycast.plane.y = 0;
	}
	if (data->map.spawning_point == 'S')
	{
		data->raycast.plane.x = -0.66;
		data->raycast.plane.y = 0;
	}
}
