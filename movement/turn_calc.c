/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:07:05 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/13 14:07:25 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_right(t_data *data)
{
	OLD_DIR_X = DIR_X;
	DIR_X = DIR_X * cos(0.06) - DIR_Y * sin(0.06);
	DIR_Y = OLD_DIR_X * sin(0.06) + DIR_Y * cos(0.06);
	OLD_PLANE_X = PLANE_X;
	PLANE_X = PLANE_X * cos(0.06) - PLANE_Y * sin(0.06);
	PLANE_Y = OLD_PLANE_X * sin(0.06) + PLANE_Y * cos(0.06);
}

void	turn_left(t_data *data)
{
	OLD_DIR_X = DIR_X;
	DIR_X = DIR_X * cos(-0.06) - DIR_Y * sin(-0.06);
	DIR_Y = OLD_DIR_X * sin(-0.06) + DIR_Y * cos(-0.06);
	OLD_PLANE_X = PLANE_X;
	PLANE_X = PLANE_X * cos(-0.06) - PLANE_Y * sin(-0.06);
	PLANE_Y = OLD_PLANE_X * sin(-0.06) + PLANE_Y * cos(-0.06);
}
