/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:42:10 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/27 14:09:01 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		identify_wall(t_data *data)
{
	while (1)
	{
		if (SIDE_DIS_X < SIDE_DIS_Y)
		{
			SIDE_DIS_X = SIDE_DIS_X + DELTA_DIS_X;
			MAP_X = MAP_X + STEP_X;
			SIDE = 0;
		}
		else
		{
			SIDE_DIS_Y = SIDE_DIS_Y + DELTA_DIS_Y;
			MAP_Y = MAP_Y + STEP_Y;
			SIDE = 1;
		}
		if (data->map.map[MAP_Y][MAP_X] == '1')
			break ;
	}
}

void		prep_wall_distance(t_data *data, int x)
{
	if (SIDE == 0)
		WALL_DIS = (MAP_X - POS_X + (1 - STEP_X) / 2) / RAY_DIR_X;
	else
		WALL_DIS = (MAP_Y - POS_Y + (1 - STEP_Y) / 2) / RAY_DIR_Y;
	data->texture_data.sprite_texture.distance[x] = WALL_DIS;
}
