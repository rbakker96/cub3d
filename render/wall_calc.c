/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:42:10 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/12 12:50:13 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		identify_wall(t_data *data)
{
	while (1)
	{
		if (SIDE_DIS_X < SIDE_DIS_Y)
		{
			SIDE_DIS_X = SIDE_DIS_X + DELTA_DIS_X;
			MAP_X = MAP_X + STEP_X;
			data->raycasting.side = 0;
		}
		else
		{
			SIDE_DIS_Y = SIDE_DIS_Y + DELTA_DIS_Y;
			MAP_Y = MAP_Y + STEP_Y;
			data->raycasting.side = 1;
		}
		if (data->map[MAP_Y][MAP_X] == '1')
			break ;
	}
}

void		prep_wall_distance(t_data *data)
{
	if (data->raycasting.side == 0)
		WALL_DIS = (MAP_X - POS_X + (1 - STEP_X) / 2) / RAY_DIR_X;
	else
		WALL_DIS = (MAP_Y - POS_Y + (1 - STEP_Y) / 2) / RAY_DIR_Y;
}

void		draw_screen(t_data *data, int i)
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
	draw_ceilling(data, draw_start, i);
	draw_wall(data, draw_start, draw_end, i);
	draw_floor(data, draw_end, i);
//	while (draw_start < draw_end)
//	{
//		if (data->raycasting.side == 1)
//			my_put_pixel(&data->mlx_data, i, draw_start, 0x00ff0000);
//		else
//			my_put_pixel(&data->mlx_data, i, draw_start, 0x00f66666);
//		draw_start++;
//	}
}

void	draw_ceilling(t_data *data, int draw_start, int i)
{
	int x;

	x = 0;
	while (x < draw_start)
	{
		if (data->raycasting.side == 1)
			my_put_pixel(&data->mlx_data, i, x, 0x00000000);
		else
			my_put_pixel(&data->mlx_data, i, x, 0x00000000);
		x++;
	}
}

void	draw_wall(t_data *data, int draw_start, int draw_end, int i)
{
	while (draw_start < draw_end)
	{
		if (data->raycasting.side == 1)
			my_put_pixel(&data->mlx_data, i, draw_start, 0x00ff0000);
		else
			my_put_pixel(&data->mlx_data, i, draw_start, 0x00f66666);
		draw_start++;
	}
}

void	draw_floor(t_data *data, int draw_end, int i)
{
	while (draw_end < HEIGHT)
	{
		if (data->raycasting.side == 1)
			my_put_pixel(&data->mlx_data, i, draw_end, 0x00000000);
		else
			my_put_pixel(&data->mlx_data, i, draw_end, 0x00000000);
		draw_end++;
	}
}
