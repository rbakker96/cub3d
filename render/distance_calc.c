/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_calc.c             d                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:38:04 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/10 14:12:57 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		delta_distance(t_data *data)
{
	DELTA_DIS_X = fabs(1 / RAY_DIR_X); /*kijken of fabs wel gebruikt mag worden */
	DELTA_DIS_Y = fabs(1 / RAY_DIR_Y);
}

void		side_distance(t_data *data)
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
