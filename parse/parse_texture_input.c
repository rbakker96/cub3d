/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture_input.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 11:37:17 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/09 14:25:45 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	parse_north(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(14, input_data, 0);
	if (data->north.validation == present)
		parse_error(15, input_data, 0);
	else
		data->north.validation = present;
	data->north.path = input_data[1];
}

void	parse_south(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(16, input_data, 0);
	if (data->south.validation == present)
		parse_error(17, input_data, 0);
	else
		data->south.validation = present;
	data->south.path = input_data[1];
}

void	parse_east(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(18, input_data, 0);
	if (data->east.validation == present)
		parse_error(19, input_data, 0);
	else
		data->east.validation = present;
	data->east.path = input_data[1];
}

void	parse_west(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(20, input_data, 0);
	if (data->west.validation == present)
		parse_error(21, input_data, 0);
	else
		data->west.validation = present;
	data->west.path = input_data[1];
}

void	parse_sprite(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(22, input_data, 0);
	if (data->sprite.validation == present)
		parse_error(23, input_data, 0);
	else
		data->sprite.validation = present;
	data->sprite.path = input_data[1];
}
