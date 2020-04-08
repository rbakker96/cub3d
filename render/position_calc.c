/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   position_calc.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:44:02 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/08 21:06:17 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	set_start_position(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map.map[y] != 0)
	{
		x = 0;
		while (data->map.map[y][x] != '\0')
		{
			if (data->map.map[y][x] == data->map.spawning_point)
			{
				data->raycast.pos.x = x + 0.5;
				data->raycast.pos.y = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	current_position(t_data *data)
{
	data->raycast.map.x = data->raycast.pos.x;
	data->raycast.map.y = data->raycast.pos.y;
}
