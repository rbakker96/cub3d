/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 18:56:56 by roybakker      #+#    #+#                */
/*   Updated: 2020/03/25 19:03:51 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

uint32_t		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	set_floor_and_ceilling_dcolor(t_data *data)
{
	data->color.ceilling_color.color = create_rgb(data->color.ceilling_color.r,
												data->color.ceilling_color.g,
												data->color.ceilling_color.b);
	data->color.floor_color.color = create_rgb(data->color.floor_color.r,
												data->color.floor_color.g,
												data->color.floor_color.b);
}
