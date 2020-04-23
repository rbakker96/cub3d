/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill_map_check.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 10:15:43 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/23 11:37:10 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		floodfill_algorithm(t_data *data)
{
	t_2d_int	pos;
	char		**floodfill_map;

	check_spawning_point(data);
	pos = position(data, 0, 0);
	floodfill_map = ft_split(data->map.map_input, '\n');
	if (!floodfill_map)
		parse_error(35, data, 0, 0);
	check_top_and_bottom_line(floodfill_map, data, 0, 0);
	flood_map(floodfill_map, data, pos.x, pos.y);
	free_array(floodfill_map);
}

void		flood_map(char **map, t_data *data, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'f')
		return ;
	if (map[y][x] == '2' || map[y][x] == '0' ||
		map[y][x] == data->map.spawning_point)
	{
		map[y][x] = 'f';
		flood_map(map, data, x, y + 1);
		flood_map(map, data, x, y - 1);
		flood_map(map, data, x + 1, y);
		flood_map(map, data, x - 1, y);
		flood_map(map, data, x + 1, y + 1);
		flood_map(map, data, x + 1, y - 1);
		flood_map(map, data, x - 1, y + 1);
		flood_map(map, data, x - 1, y - 1);
	}
	else
		parse_error(25, data, 0, 0);
}

t_2d_int	position(t_data *data, int x, int y)
{
	t_2d_int	pos;

	pos.x = 0;
	pos.y = 0;
	while (data->map.map[y] != 0)
	{
		x = 0;
		while (data->map.map[y][x] != '\0')
		{
			if (data->map.map[y][x] == data->map.spawning_point)
			{
				pos.x = x + 0.5;
				pos.y = y + 0.5;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void		check_spawning_point(t_data *data)
{
	int i;
	int validation;

	i = 0;
	validation = 0;
	while (data->map.map_input[i] != '\0')
	{
		if (data->map.map_input[i] == 'S' || data->map.map_input[i] == 'N' ||
			data->map.map_input[i] == 'W' || data->map.map_input[i] == 'E')
		{
			validation++;
			data->map.spawning_point = data->map.map_input[i];
		}
		i++;
	}
	if (validation != 1)
		parse_error(30, data, 0, 0);
}

void		check_top_and_bottom_line(char **map, t_data *data, int x, int y)
{
	while (map[y][x] != '\0')
	{
		if (map[y][x] != ' ' && map[y][x] != '1')
			parse_error(25, data, 0, 0);
		x++;
	}
	y = arguments_count(map) - 1;
	x = 0;
	while (map[y][x] != '\0')
	{
		if (map[y][x] != ' ' && map[y][x] != '1')
			parse_error(25, data, 0, 0);
		x++;
	}
}
