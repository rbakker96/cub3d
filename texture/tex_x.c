/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tex_x.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 10:52:14 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/08 10:43:03 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

int	calculate_tex_x(t_data *data, double wall_x, int tex_width)
{
	int tex_x;

	tex_x = (int)(wall_x * (double)tex_width);
	if (data->raycast.side == 0 && data->raycast.ray_dir.x > 0)
	{
		tex_x = tex_width - tex_x - 1;
	}
	if (data->raycast.side == 1 && data->raycast.ray_dir.y < 0)
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}
