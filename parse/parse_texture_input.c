/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture_input.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 11:37:17 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/21 14:29:31 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_north(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(14, data, input_data, 0);
	if (data->north.validation == present)
		parse_error(15, data, input_data, 0);
	else
		data->north.validation = present;
	data->north.path = ft_strdup(input_data[1]);
	if (!data->north.path)
		parse_error(35, data, input_data, 0);
	free_array(input_data);
}

void	parse_south(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(16, data, input_data, 0);
	if (data->south.validation == present)
		parse_error(17, data, input_data, 0);
	else
		data->south.validation = present;
	data->south.path = ft_strdup(input_data[1]);
	if (!data->south.path)
		parse_error(35, data, input_data, 0);
	free_array(input_data);
}

void	parse_east(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(18, data, input_data, 0);
	if (data->east.validation == present)
		parse_error(19, data, input_data, 0);
	else
		data->east.validation = present;
	data->east.path = ft_strdup(input_data[1]);
	if (!data->east.path)
		parse_error(35, data, input_data, 0);
	free_array(input_data);
}

void	parse_west(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(20, data, input_data, 0);
	if (data->west.validation == present)
		parse_error(21, data, input_data, 0);
	else
		data->west.validation = present;
	data->west.path = ft_strdup(input_data[1]);
	if (!data->west.path)
		parse_error(35, data, input_data, 0);
	free_array(input_data);
}

void	parse_sprite(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(22, data, input_data, 0);
	if (data->sprite.validation == present)
		parse_error(23, data, input_data, 0);
	else
		data->sprite.validation = present;
	data->sprite.path = ft_strdup(input_data[1]);
	if (!data->sprite.path)
		parse_error(35, data, input_data, 0);
	free_array(input_data);
}
