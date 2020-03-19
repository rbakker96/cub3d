/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_calc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 08:35:22 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/19 08:51:53 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	calculate_wall_x(t_data *data)
{
	if (SIDE == 0)
		WALL_X = POS_Y + WALL_DIS * RAY_DIR_Y;
	else
		WALL_X = POS_X + WALL_DIS * RAY_DIR_X;
	WALL_X -= (int)WALL_X;
}

void	calculate_tex_x(t_data *data)
{
	TEX_X = (int)WALL_X * (double)TEX_WIDTH;
	if (SIDE == 0 && RAY_DIR_X > 0)
		TEX_X = TEX_WIDTH - TEX_X - 1;
	if (SIDE == 1 && RAY_DIR_Y < 0)
		TEX_X = TEX_WIDTH - TEX_X - 1;
}
