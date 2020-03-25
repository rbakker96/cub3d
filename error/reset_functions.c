/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:30:30 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/20 17:23:11 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	reset_validation(t_data *data)
{
	data->color.ceilling_color.validation = 0;
	data->texture_data.east_texture.validation = 0;
	data->color.floor_color.validation = 0;
	data->texture_data.north_texture.validation = 0;
	data->resolution.validation = 0;
	data->texture_data.south_texture.validation = 0;
	data->texture_data.sprite_texture.validation = 0;
	data->texture_data.west_texture.validation = 0;
}

void	reset_texture(t_data *data)
{
	data->texture_data.east_texture.path = 0;
	data->texture_data.north_texture.path = 0;
	data->texture_data.south_texture.path = 0;
	data->texture_data.west_texture.path = 0;
	data->map.spawning_point = 0;
}

void	reset_color(t_data *data)
{
	data->color.floor_color.r = 0;
	data->color.floor_color.g = 0;
	data->color.floor_color.b = 0;
	data->color.ceilling_color.r = 0;
	data->color.ceilling_color.g = 0;
	data->color.ceilling_color.b = 0;
	data->resolution.x = 0;
	data->resolution.y = 0;
}

void	reset_input_struct(t_data *data)
{
	reset_validation(data);
	reset_texture(data);
	reset_color(data);
}
