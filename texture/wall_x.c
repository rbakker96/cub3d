/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 10:52:46 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/25 20:22:16 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

double	calculate_wall_x(t_data *data)
{
	double wall_x;

	if (SIDE == 0)
		wall_x = POS_Y + WALL_DIS * RAY_DIR_Y;
	else
		wall_x = POS_X + WALL_DIS * RAY_DIR_X;
	wall_x -= (int)wall_x;
	return (wall_x);
}
