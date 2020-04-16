/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distance_calc.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:38:04 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/16 11:56:48 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		delta_distance(t_data *data)
{
	data->raycast.delta_dis.x = fabs(1 / data->raycast.ray_dir.x);
	data->raycast.delta_dis.y = fabs(1 / data->raycast.ray_dir.y);
}

void		side_distance(t_data *data)
{
	if (data->raycast.step.x == -1)
		data->raycast.side_dis.x = (data->raycast.pos.x - data->raycast.map.x) *
													data->raycast.delta_dis.x;
	else
		data->raycast.side_dis.x = (data->raycast.map.x + 1 -
							data->raycast.pos.x) * data->raycast.delta_dis.x;
	if (data->raycast.step.y == -1)
		data->raycast.side_dis.y = (data->raycast.pos.y - data->raycast.map.y) *
													data->raycast.delta_dis.y;
	else
		data->raycast.side_dis.y = (data->raycast.map.y + 1 -
							data->raycast.pos.y) * data->raycast.delta_dis.y;
}

void		set_prep_distance_array(t_data *data)
{
	data->sprite.dis = malloc(sizeof(double) * data->res.x);
	if (!data->sprite.dis)
		parse_error(35, data, 0, 0);
}
