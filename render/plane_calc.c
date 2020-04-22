/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_calc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:44:57 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/21 13:32:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
