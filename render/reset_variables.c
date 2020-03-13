/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:52:21 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/10 14:12:05 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reset_variables(t_data *data)
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
	data->raycasting.perp_wall_distance = 0;
	data->raycasting.side = 0;
}
