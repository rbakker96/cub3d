/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:37:17 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/10 14:49:23 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_north(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(14, input_data, 0);
	if (data->north_texture.validation == present)
		parse_error(15, input_data, 0);
	else
		data->north_texture.validation = present;
	data->north_texture.path = input_data[1];
}

void	parse_south(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(16, input_data, 0);
	if (data->south_texture.validation == present)
		parse_error(17, input_data, 0);
	else
		data->south_texture.validation = present;
	data->south_texture.path = input_data[1];
}

void	parse_east(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(18, input_data, 0);
	if (data->east_texture.validation == present)
		parse_error(19, input_data, 0);
	else
		data->east_texture.validation = present;
	data->east_texture.path = input_data[1];
}

void	parse_west(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(20, input_data, 0);
	if (data->west_texture.validation == present)
		parse_error(21, input_data, 0);
	else
		data->west_texture.validation = present;
	data->west_texture.path = input_data[1];
}

void	parse_sprite(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(22, input_data, 0);
	if (data->sprite_texture.validation == present)
		parse_error(23, input_data, 0);
	else
		data->sprite_texture.validation = present;
	data->sprite_texture.path = input_data[1];
}
