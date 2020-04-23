/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_image.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 19:05:46 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/22 20:19:37 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (data->image_one.usage == off_screen)
		dst = data->image_one.addr + (y * data->image_one.line_len + x *
													(data->image_one.bpp / 8));
	else
		dst = data->image_two.addr + (y * data->image_two.line_len + x *
													(data->image_two.bpp / 8));
	*(unsigned int*)dst = color;
}
