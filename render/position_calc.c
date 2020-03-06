/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:44:02 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/06 14:44:38 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_and_current_position(t_data *data, t_raycasting *raycasting)
{
	int		x;
	int		y;

	y = 0;
	while (data->map[y] != 0)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == data->spawning_point)
			{
				POS_X = x + 0.5;
				MAP_X = x;
				POS_Y = y + 0.5;
				MAP_Y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}
