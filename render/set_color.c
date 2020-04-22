/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 18:56:56 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/21 13:32:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

uint32_t	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void		set_floor_and_ceilling_color(t_data *data)
{
	data->color.ceilling.color = create_rgb(data->color.ceilling.r,
											data->color.ceilling.g,
											data->color.ceilling.b);
	data->color.floor.color = create_rgb(data->color.floor.r,
										data->color.floor.g,
										data->color.floor.b);
}
