/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_calc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:44:57 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/20 10:28:35 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		initialize_plane(t_data *data)
{
	if (data->map.spawning_point == 'W')
	{
		PLANE_X = 0;
		PLANE_Y = -0.66;
	}
	if (data->map.spawning_point == 'E')
	{
		PLANE_X = 0;
		PLANE_Y = 0.66;
	}
	if (data->map.spawning_point == 'N')
	{
		PLANE_X = 0.66;
		PLANE_Y = 0;
	}
	if (data->map.spawning_point == 'S')
	{
		PLANE_X = -0.66;
		PLANE_Y = 0;
	}
}
