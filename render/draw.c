/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/19 09:14:55 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/19 11:27:55 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		draw_screen(t_data *data, int x)
{
	LINE_HEIGHT = (int)(HEIGHT / WALL_DIS);
	DRAW_START = -LINE_HEIGHT / 2 + HEIGHT / 2;
	if (DRAW_START < 0)
		DRAW_START = 0;
	DRAW_END = LINE_HEIGHT / 2 + HEIGHT / 2;
	if (DRAW_END >= HEIGHT)
		DRAW_END = HEIGHT - 1;
	draw_ceilling(data, x);
	draw_wall(data, x);
	draw_floor(data, x);
}

void	draw_ceilling(t_data *data, int x)
{
	int y;

	y = 0;
	while (y < DRAW_START)
	{
		if (SIDE == 1)
			my_put_pixel(&data->mlx_data, x, y, 0x00000000);
		else
			my_put_pixel(&data->mlx_data, x, y, 0x00000000);
		y++;
	}
}

void	draw_wall(t_data *data, int x)
{
//	int y;

//	y = DRAW_START;
//	STEP = 1.0 * TEX_HEIGHT / LINE_HEIGHT;
//	TEX_POS = (DRAW_START - HEIGHT / 2 + LINE_HEIGHT / 2) * STEP;
//	while( y < DRAW_END)
//	{
//		TEX_Y = (int)TEX_POS & (int)(TEX_HEIGHT - 1); /* WHY bitwise operation needed ? */
//		TEX_POS += STEP;
		/* Somehow get the right color from the texture png*/
		//my_put_pixel(&data->mlx_data, x, y, right color here);
//		y++;
//	}
	int y;

	y = DRAW_START;
	while (y < DRAW_END)
	{
		if (data->raycasting.side == 1)
			my_put_pixel(&data->mlx_data, x, y, 0x00ff0000);
		else
			my_put_pixel(&data->mlx_data, x, y, 0x00f66666);
		y++;
	}
}

void	draw_floor(t_data *data, int x)
{
	int y;

	y = DRAW_END;
	while (y < HEIGHT)
	{
		if (data->raycasting.side == 1)
			my_put_pixel(&data->mlx_data, x, y, 0x00000000);
		else
			my_put_pixel(&data->mlx_data, x, y, 0x00000000);
		y++;
	}
}
