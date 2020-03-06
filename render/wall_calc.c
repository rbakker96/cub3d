/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:42:10 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/06 14:42:57 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		identify_wall(t_data *data, t_raycasting *raycasting)
{
	while (1)
	{
		if (SIDE_DIS_X < SIDE_DIS_Y)
		{
			SIDE_DIS_X = SIDE_DIS_X + DELTA_DIS_X;
			MAP_X = MAP_X + STEP_X;
			raycasting->side = 0;
		}
		else
		{
			SIDE_DIS_Y = SIDE_DIS_Y + DELTA_DIS_Y;
			MAP_Y = MAP_Y + STEP_Y;
			raycasting->side = 1;
		}
		if (data->map[MAP_Y][MAP_X] == '1')
			break ;
	}
}

void		prep_wall_distance(t_raycasting *raycasting)
{
	if (raycasting->side == 0)
		WALL_DIS = (MAP_X - POS_X + (1 - STEP_X) / 2) / RAY_DIR_X;
	else
		WALL_DIS = (MAP_Y - POS_Y + (1 - STEP_Y) / 2) / RAY_DIR_Y;
}

void		draw_wall(t_data *data, t_raycasting *raycasting,
						t_mlx_data *mlx_data, int i)
{
	int	lineheight;
	int draw_start;
	int draw_end;

	lineheight = (int)(HEIGHT / WALL_DIS);
	draw_start = -lineheight / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = lineheight / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	while (draw_start < draw_end)
	{
		if (raycasting->side == 1)
			my_put_pixel(mlx_data, i, draw_start, 0x00ff0000);
		else
			my_put_pixel(mlx_data, i, draw_start, 0x00f66666);
		draw_start++;
	}
}
