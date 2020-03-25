/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tex_x.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 10:52:14 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/25 11:00:56 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

int	calculate_tex_x(t_data *data, double wall_x, int tex_width)
{
	int tex_x;

	tex_x = (int)(wall_x * (double)tex_width);
	if (SIDE == 0 && RAY_DIR_X > 0)
	{
		tex_x = tex_width - tex_x - 1;
	}
	if (SIDE == 1 && RAY_DIR_Y < 0)
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}
