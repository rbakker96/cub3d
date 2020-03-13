/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:44:02 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/13 11:56:25 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_position(t_data *data)
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
				POS_Y = y + 0.5;
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
	MAP_X = POS_X;
	MAP_Y = POS_Y;
}
