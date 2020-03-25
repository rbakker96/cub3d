/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   direction_calc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:40:29 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/20 10:27:28 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		view_direction(t_data *data)
{
	if (data->map.spawning_point == 'S')
	{
		DIR_X = 0.0;
		DIR_Y = 1.0;
	}
	if (data->map.spawning_point == 'W')
	{
		DIR_X = -1.0;
		DIR_Y = 0.0;
	}
	if (data->map.spawning_point == 'E')
	{
		DIR_X = 1.0;
		DIR_Y = 0.0;
	}
	if (data->map.spawning_point == 'N')
	{
		DIR_X = 0.0;
		DIR_Y = -1.0;
	}
}

void		ray_direction(t_data *data)
{
	RAY_DIR_X = DIR_X + PLANE_X * CAM_X;
	RAY_DIR_Y = DIR_Y + PLANE_Y * CAM_X;
}

void		step_size(t_data *data)
{
	if (RAY_DIR_X < 0)
		STEP_X = -1;
	else
		STEP_X = 1;
	if (RAY_DIR_Y < 0)
		STEP_Y = -1;
	else
		STEP_Y = 1;
}
