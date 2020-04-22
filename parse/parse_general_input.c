/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_general_input.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 11:28:13 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/21 15:22:44 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		parse_general_input(char *line, t_data *data)
{
	char	**input_data;

	input_data = ft_split(line, ' ');
	if (!input_data)
		parse_error(35, data, 0, 0);
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
		parse_error(24, data, input_data, &line);
}

void		parse_resolution(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 3)
		parse_error(4, data, input_data, 0);
	if (data->res.validation == present)
		parse_error(5, data, input_data, 0);
	else
		data->res.validation = present;
	if (!digit(input_data[1]) || !digit(input_data[2]))
		parse_error(43, data, input_data, 0);
	data->res.x = ft_atoi(input_data[1]);
	data->res.y = ft_atoi(input_data[2]);
	free_array(input_data);
	check_resolution(data);
}

void		parse_floor(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(6, data, input_data, 0);
	if (data->color.floor.validation == present)
		parse_error(7, data, input_data, 0);
	else
		data->color.floor.validation = present;
	data->color.floor = color_value(input_data[1], data, input_data);
	free_array(input_data);
}

void		parse_ceilling(t_data *data, char **input_data)
{
	if (arguments_count(input_data) != 2)
		parse_error(8, data, input_data, 0);
	if (data->color.ceilling.validation == present)
		parse_error(9, data, input_data, 0);
	else
		data->color.ceilling.validation = present;
	data->color.ceilling = color_value(input_data[1], data, input_data);
	free_array(input_data);
}

void		general_input(t_data *data, int fd)
{
	int		res;
	char	*line;

	res = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			parse_error(24, data, 0, 0);
		if (!empty_line(line) && !general_input_line(line))
			break ;
		if (general_input_line(line))
			parse_general_input(line, data);
		free(line);
	}
	if (map_line(line))
	{
		data->map.map_input = ft_strdup(line);
		if (!data->map.map_input)
			parse_error(35, data, 0, 0);
	}
	free(line);
	validate_general_input(data);
}
