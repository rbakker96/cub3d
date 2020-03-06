/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:38:04 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/06 14:39:42 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		delta_distance(t_raycasting *raycasting)
{
	DELTA_DIS_X = fabs(1 / RAY_DIR_X);
	DELTA_DIS_Y = fabs(1 / RAY_DIR_Y);
}

void		side_distance(t_raycasting *raycasting)
{
	if (STEP_X == -1)
		SIDE_DIS_X = (POS_X - MAP_X) * DELTA_DIS_X;
	else
		SIDE_DIS_X = (MAP_X + 1 - POS_X) * DELTA_DIS_X;
	if (STEP_Y == -1)
		SIDE_DIS_Y = (POS_Y - MAP_Y) * DELTA_DIS_Y;
	else
		SIDE_DIS_Y = (MAP_Y + 1 - POS_Y) * DELTA_DIS_Y;
}
