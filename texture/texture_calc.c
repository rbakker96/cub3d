/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_calc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 08:35:22 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/25 19:23:22 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	calculate_texture_variables(t_data *data)
{
	calculate_north_variables(data);
	calculate_south_variables(data);
	calculate_west_variables(data);
	calculate_east_variables(data);
}

void	calculate_north_variables(t_data *data)
{
	WALL_X_north = calculate_wall_x(data);
	TEX_X_north = calculate_tex_x(data, WALL_X_north, TEX_WIDTH_north);
	TEX_STEP_north = 1.0 * TEX_HEIGHT_north / LINE_HEIGHT;
	TEX_POS_north = (DRAW_START - HEIGHT / 2 + LINE_HEIGHT / 2)
					* TEX_STEP_north;
}

void	calculate_south_variables(t_data *data)
{
	WALL_X_south = calculate_wall_x(data);
	TEX_X_south = calculate_tex_x(data, WALL_X_south, TEX_WIDTH_south);
	TEX_STEP_south = 1.0 * TEX_HEIGHT_south / LINE_HEIGHT;
	TEX_POS_south = (DRAW_START - HEIGHT / 2 + LINE_HEIGHT / 2)
					* TEX_STEP_south;
}

void	calculate_west_variables(t_data *data)
{
	WALL_X_west = calculate_wall_x(data);
	TEX_X_west = calculate_tex_x(data, WALL_X_west, TEX_WIDTH_west);
	TEX_STEP_west = 1.0 * TEX_HEIGHT_west / LINE_HEIGHT;
	TEX_POS_west = (DRAW_START - HEIGHT / 2 + LINE_HEIGHT / 2) * TEX_STEP_west;
}

void	calculate_east_variables(t_data *data)
{
	WALL_X_east = calculate_wall_x(data);
	TEX_X_east = calculate_tex_x(data, WALL_X_east, TEX_WIDTH_east);
	TEX_STEP_east = 1.0 * TEX_HEIGHT_east / LINE_HEIGHT;
	TEX_POS_east = (DRAW_START - HEIGHT / 2 + LINE_HEIGHT / 2) * TEX_STEP_east;
}
