/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_sprite.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/26 09:38:20 by roybakker      #+#    #+#                */
/*   Updated: 2020/04/01 19:33:39 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		create_sprite_image(t_data *data)
{
	IMG_SPRITE = mlx_png_file_to_image(MLX, PATH_SPRITE, &TEX_WIDTH_SPRITE,
															&TEX_HEIGHT_SPRITE);
	if (!IMG_SPRITE)
		parse_error(33 , 0, 0);
	ADDRES_SPRITE = mlx_get_data_addr(IMG_SPRITE, &BPP_SPRITE, &LL_SPRITE,
																&ENDIAN_SPRITE);
	if (!ADDRES_SPRITE)
		parse_error(34, 0, 0);
}
