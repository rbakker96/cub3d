/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 16:47:23 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/20 10:26:57 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	check_top_line(t_data *data, int x, int y)
{
	while (MAP[y][x] == ' ')
		x++;
	if (MAP[y][x] != '1' || MAP[y + 1][x] != '1' || MAP[y][x + 1] != '1')
		parse_error(25, 0, 0);
	while (MAP[y][x] == '1' && MAP[y][x + 1] != '\0' && MAP[y][x + 1] != ' ')
		x++;
	if (MAP[y][x + 1] == ' ' && MAP[y][x] == '1' && MAP[y + 1][x] == '1')
		y = coner_type_four(data, top, x, y);
	while (MAP[y][x] == '1' && MAP[y][x + 1] == '1' && MAP[y][x + 1] != '\0' &&
			MAP[y][x + 1] != ' ')
		x++;
	if (MAP[y][x] == '1' && y != 0)
		y = coner_type_three(data, top, x, y);
	while (MAP[y][x] == '1' && MAP[y][x + 1] != '\0' && MAP[y][x + 1] != ' ')
		x++;
	if (MAP[y][x] == '1' && MAP[y][x + 1] == '\0' && MAP[y + 1][x] == '1')
		return ;
	else
		parse_error(25, 0, 0);
}

void	check_middel_lines(t_data *data, int x, int y)
{
	while (MAP[y][x] == ' ')
		x++;
	if (MAP[y][x] == '1' && MAP[y + 1][x] == '1' && MAP[y][x + 1] == '1')
		coner_type_one(data, left, x, y);
	else if (MAP[y][x] == '1' && MAP[y - 1][x] == '1' && MAP[y][x + 1] == '1')
		coner_type_two(data, left, x, y);
	else if (MAP[y][x] != '1' || MAP[y + 1][x] != '1' || MAP[y - 1][x] != '1')
		parse_error(25, 0, 0);
	while (MAP[y][x + 1] != '\0' && MAP[y - 1][x + 1] != '\0' &&
			MAP[y + 1][x + 1] != '\0')
		x++;
	if (MAP[y][x] == '1' && MAP[y - 1][x] == '1' && MAP[y][x + 1] == '1')
		return (coner_type_two(data, right, x, y));
	else if (MAP[y][x] == '1' && MAP[y + 1][x] == '1' && MAP[y][x + 1] == '1')
		return (coner_type_one(data, right, x, y));
	else if (MAP[y][x] != '1' || MAP[y + 1][x] != '1' || MAP[y - 1][x] != '1')
		parse_error(25, 0, 0);
	return ;
}

void	check_bottom_line(t_data *data, int x, int y)
{
	while (MAP[y][x] == ' ')
		x++;
	if (MAP[y][x] != '1' || MAP[y - 1][x] != '1' || MAP[y][x + 1] != '1')
		parse_error(25, 0, 0);
	while (MAP[y][x] == '1' && MAP[y][x + 1] != '\0' && MAP[y][x + 1] != ' ')
		x++;
	if (MAP[y][x + 1] == ' ' && MAP[y][x] == '1' && MAP[y - 1][x] == '1')
		y = coner_type_three(data, bottom, x, y);
	while (MAP[y][x] == '1' && MAP[y][x + 1] == '1' && MAP[y][x + 1] != '\0' &&
			MAP[y][x + 1] != ' ')
		x++;
	if (MAP[y + 1][x - 1] == ' ' && MAP[y][x] == '1' && MAP[y + 1][x] == '1')
		y = coner_type_four(data, bottom, x, y);
	while (MAP[y][x] == '1' && MAP[y][x + 1] != '\0' && MAP[y][x + 1] != ' ')
		x++;
	if (MAP[y][x] == '1' && MAP[y][x + 1] == '\0' && MAP[y - 1][x] == '1')
		return ;
	else
		parse_error(25, 0, 0);
}

void	check_start_position_and_spawning(t_data *data)
{
	int i;
	int validation;

	i = 0;
	validation = 0;
	while (data->map.map_input[i] != '\0')
	{
		if (data->map.map_input[i] == 'S' || data->map.map_input[i] == 'N' ||
			data->map.map_input[i] == 'W' || data->map.map_input[i] == 'E')
			validation++;
		if (data->map.map_input[i] == 'S')
			data->map.spawning_point = 'S';
		if (data->map.map_input[i] == 'W')
			data->map.spawning_point = 'W';
		if (data->map.map_input[i] == 'E')
			data->map.spawning_point = 'E';
		if (data->map.map_input[i] == 'N')
			data->map.spawning_point = 'N';
		i++;
	}
	if (validation != 1)
		parse_error(30, 0, 0);
	return ;
}
