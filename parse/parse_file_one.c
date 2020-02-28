/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:28:13 by rbakker           #+#    #+#             */
/*   Updated: 2020/02/27 12:51:04 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_general_input(char *line, t_data *data)
{
	char	**input_data;

	input_data = ft_split(line, ' ');
	if (!ft_strncmp(input_data[0], "R", 10))
		return (parse_resolution(data, input_data));
	if (!ft_strncmp(input_data[0], "NO", 10))
		return (parse_north(data, input_data));
	if (!ft_strncmp(input_data[0], "SO", 10))
		return (parse_south(data, input_data));
	if (!ft_strncmp(input_data[0], "WE", 10))
		return (parse_west(data, input_data));
	if (!ft_strncmp(input_data[0], "EA", 10))
		return (parse_east(data, input_data));
	if (!ft_strncmp(input_data[0], "S", 10))
		return (parse_sprite(data, input_data));
	if (!ft_strncmp(input_data[0], "F", 10))
		return (parse_floor(data, input_data));
	if (!ft_strncmp(input_data[0], "C", 10))
		return (parse_ceilling(data, input_data));
	else
	{
		free(line);
		parse_error(24, input_data, 0);
	}
	free_array(input_data);
}

void	parse_resolution(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 3)
		parse_error(4, input_data, 0);
	if (data->resolution.validation == present)
		parse_error(5, input_data, 0);
	else
		data->resolution.validation = present;
	data->resolution.x = ft_atoi(input_data[1]);
	data->resolution.y = ft_atoi(input_data[2]);
}

void	parse_floor(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(6, input_data, 0);
	if (data->floor_color.validation == present)
		parse_error(7, input_data, 0);
	else
		data->floor_color.validation = present;
	data->floor_color = color_value(input_data[1], input_data);
}

void	parse_ceilling(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(8, input_data, 0);
	if (data->ceilling_color.validation == present)
		parse_error(9, input_data, 0);
	else
		data->ceilling_color.validation = present;
	data->ceilling_color = color_value(input_data[1], input_data);
}
