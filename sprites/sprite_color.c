/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_color.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 11:51:16 by roybakker      #+#    #+#                */
/*   Updated: 2020/04/02 14:10:17 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	sprite_color(t_data *data, int y)
{
	int pixel;
	int d;

	d = (y) * 256 - HEIGHT * 128 + SPRITE_HEIGHT * 128;
	TEX_Y_SPRITE = ((d * TEX_HEIGHT_SPRITE) / SPRITE_HEIGHT) / 256;
	pixel = ((TEX_Y_SPRITE * LL_SPRITE) + (TEX_X_SPRITE * (BPP_SPRITE / 8)));
	SPRITE_COLOR = *(unsigned int *)(ADDRES_SPRITE + pixel);
	if ((SPRITE_COLOR & 0x00FFFFFF) != 0)
		pixel_to_image(data, STRIPE, y, SPRITE_COLOR);
}
