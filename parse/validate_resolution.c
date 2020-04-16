/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_resolution.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/09 10:40:49 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/16 11:56:42 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	check_resolution(t_data *data)
{
	int current_x;
	int current_y;

	if (data->res.x < 0 || data->res.y < 0)
		parse_error(36, data, 0, 0);
	mlx_get_screen_size(data->mlx, &current_x, &current_y);
	if (data->res.x > current_x)
		data->res.x = current_x;
	if (data->res.y > current_y)
		data->res.y = current_y;
}
