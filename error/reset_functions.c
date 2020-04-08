/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:30:30 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/08 11:25:21 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	reset_validation(t_data *data)
{
	data->color.ceilling.validation = 0;
	data->east.validation = 0;
	data->color.floor.validation = 0;
	data->north.validation = 0;
	data->res.validation = 0;
	data->south.validation = 0;
	data->sprite.validation = 0;
	data->west.validation = 0;
}

void	reset_texture(t_data *data)
{
	data->east.path = 0;
	data->north.path = 0;
	data->south.path = 0;
	data->west.path = 0;
	data->sprite.dis = 0;
	data->map.spawning_point = 0;
}

void	reset_color(t_data *data)
{
	data->color.floor.r = 0;
	data->color.floor.g = 0;
	data->color.floor.b = 0;
	data->color.ceilling.r = 0;
	data->color.ceilling.g = 0;
	data->color.ceilling.b = 0;
	data->res.x = 0;
	data->res.y = 0;
}

void	reset_input_struct(t_data *data)
{
	reset_validation(data);
	reset_texture(data);
	reset_color(data);
}
