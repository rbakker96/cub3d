/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_image.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 19:05:46 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/25 20:15:47 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (data->mlx_data.image_one.usage == off_screen)
		dst = ADDRES_ONE + (y * LL_ONE + x * (BPP_ONE / 8));
	else
		dst = ADDRES_TWO + (y * LL_TWO + x * (BPP_TWO / 8));
	*(unsigned int*)dst = color;
}
