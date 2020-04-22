/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_calc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 08:35:22 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/21 13:32:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_texture_variables(t_data *data)
{
	calculate_north_variables(data);
	calculate_south_variables(data);
	calculate_west_variables(data);
	calculate_east_variables(data);
}

void	calculate_north_variables(t_data *data)
{
	data->north.wall_x = calculate_wall_x(data);
	data->north.tex_x = calculate_tex_x(data, data->north.wall_x,
											data->north.tex_res.y);
	data->north.step = 1.0 * data->north.tex_res.x / data->raycast.lineheight;
	data->north.tex_pos = (data->raycast.draw_start - data->res.y / 2 +
							data->raycast.lineheight / 2) * data->north.step;
}

void	calculate_south_variables(t_data *data)
{
	data->south.wall_x = calculate_wall_x(data);
	data->south.tex_x = calculate_tex_x(data, data->south.wall_x,
											data->south.tex_res.y);
	data->south.step = 1.0 * data->south.tex_res.x / data->raycast.lineheight;
	data->south.tex_pos = (data->raycast.draw_start - data->res.y / 2 +
							data->raycast.lineheight / 2) * data->south.step;
}

void	calculate_west_variables(t_data *data)
{
	data->west.wall_x = calculate_wall_x(data);
	data->west.tex_x = calculate_tex_x(data, data->west.wall_x,
											data->west.tex_res.y);
	data->west.step = 1.0 * data->west.tex_res.x / data->raycast.lineheight;
	data->west.tex_pos = (data->raycast.draw_start - data->res.y / 2 +
								data->raycast.lineheight / 2) * data->west.step;
}

void	calculate_east_variables(t_data *data)
{
	data->east.wall_x = calculate_wall_x(data);
	data->east.tex_x = calculate_tex_x(data, data->east.wall_x,
											data->east.tex_res.y);
	data->east.step = 1.0 * data->east.tex_res.x / data->raycast.lineheight;
	data->east.tex_pos = (data->raycast.draw_start - data->res.y / 2 +
								data->raycast.lineheight / 2) * data->east.step;
}
