/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 14:16:53 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/25 20:21:15 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		place_texture_color(t_data *data, int x, int y)
{
	if (SIDE == 1 && RAY_DIR_Y > 0)
		east_texture(data, x, y);
	else if (SIDE == 1 && RAY_DIR_Y < 0)
		west_texture(data, x, y);
	else if (SIDE == 0 && RAY_DIR_X > 0)
		south_texture(data, x, y);
	else
		north_texture(data, x, y);
}

void		north_texture(t_data *data, int x, int y)
{
	int pixel;

	TEX_Y_north = (int)TEX_POS_north & (TEX_HEIGHT_north - 1);
	TEX_POS_north += TEX_STEP_north;
	pixel = ((TEX_Y_north * LL_north) + (TEX_X_north * (BPP_north / 8)));
	TEX_COLOR_north = *(unsigned int *)(ADDRES_north + pixel);
	if (SIDE == 1)
		TEX_COLOR_north = (TEX_COLOR_north >> 1) & 8355711;
	pixel_to_image(data, x, y, TEX_COLOR_north);
}

void		south_texture(t_data *data, int x, int y)
{
	int pixel;

	TEX_Y_south = (int)TEX_POS_south & (TEX_HEIGHT_south - 1);
	TEX_POS_south += TEX_STEP_south;
	pixel = ((TEX_Y_south * LL_south) + (TEX_X_south * (BPP_south / 8)));
	TEX_COLOR_south = *(unsigned int *)(ADDRES_south + pixel);
	if (SIDE == 1)
		TEX_COLOR_south = (TEX_COLOR_south >> 1) & 8355711;
	pixel_to_image(data, x, y, TEX_COLOR_south);
}

void		east_texture(t_data *data, int x, int y)
{
	int pixel;

	TEX_Y_east = (int)TEX_POS_east & (TEX_HEIGHT_east - 1);
	TEX_POS_east += TEX_STEP_east;
	pixel = ((TEX_Y_east * LL_east) + (TEX_X_east * (BPP_east / 8)));
	TEX_COLOR_east = *(unsigned int *)(ADDRES_east + pixel);
	if (SIDE == 1)
		TEX_COLOR_east = (TEX_COLOR_east >> 1) & 8355711;
	pixel_to_image(data, x, y, TEX_COLOR_east);
}

void		west_texture(t_data *data, int x, int y)
{
	int pixel;

	TEX_Y_west = (int)TEX_POS_west & (TEX_HEIGHT_west - 1);
	TEX_POS_west += TEX_STEP_west;
	pixel = ((TEX_Y_west * LL_west) + (TEX_X_west * (BPP_west / 8)));
	TEX_COLOR_west = *(unsigned int *)(ADDRES_west + pixel);
	if (SIDE == 1)
		TEX_COLOR_west = (TEX_COLOR_west >> 1) & 8355711;
	pixel_to_image(data, x, y, TEX_COLOR_west);
}
