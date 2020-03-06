/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:45:36 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/06 14:47:54 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reset_variables(t_raycasting *raycasting)
{
	POS_X = 0;
	POS_Y = 0;
	MAP_X = 0;
	MAP_Y = 0;
	DIR_X = 0;
	DIR_Y = 0;
	PLANE_X = 0;
	PLANE_Y = 0;
	SIDE_DIS_X = 0;
	SIDE_DIS_Y = 0;
	DELTA_DIS_X = 0;
	DELTA_DIS_Y = 0;
	STEP_X = 0;
	STEP_Y = 0;
	RAY_DIR_X = 0;
	RAY_DIR_Y = 0;
	CAM_X = 0;
	raycasting->perp_wall_distance = 0;
	raycasting->hit = 0;
	raycasting->side = 0;
}
