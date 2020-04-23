/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:42:10 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/22 19:47:59 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		identify_wall(t_data *data)
{
	while (1)
	{
		if (data->raycast.side_dis.x < data->raycast.side_dis.y)
		{
			data->raycast.side_dis.x += data->raycast.delta_dis.x;
			data->raycast.map.x = data->raycast.map.x + data->raycast.step.x;
			data->raycast.side = 0;
		}
		else
		{
			data->raycast.side_dis.y += data->raycast.delta_dis.y;
			data->raycast.map.y = data->raycast.map.y + data->raycast.step.y;
			data->raycast.side = 1;
		}
		if (data->map.map[data->raycast.map.y][data->raycast.map.x] == '1')
			break ;
	}
}

void		prep_wall_distance(t_data *data, int x)
{
	if (data->raycast.side == 0)
		data->raycast.wall_dis = (data->raycast.map.x - data->raycast.pos.x +
					(1 - data->raycast.step.x) / 2) / data->raycast.ray_dir.x;
	else
		data->raycast.wall_dis = (data->raycast.map.y - data->raycast.pos.y +
					(1 - data->raycast.step.y) / 2) / data->raycast.ray_dir.y;
	data->sprite.dis[x] = data->raycast.wall_dis;
}
