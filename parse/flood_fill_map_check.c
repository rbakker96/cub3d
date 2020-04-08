/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill_map_check.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 10:15:43 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/08 21:00:48 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		floodfill_algorithm(t_data *data)
{
	t_2d_int	pos;
	char		**floodfill_map;
	char		spawning_point;

	spawning_point = check_spawning_point(data);
	pos = position(data, 0, 0);
	floodfill_map = ft_split(data->map.map_input, '\n');
	flood_map(floodfill_map, spawning_point, pos.x, pos.y);
	free_array(floodfill_map);
}

void		flood_map(char **map, char spawning_point, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'f')
		return ;
	if (map[y][x] == '2' || map[y][x] == '0' || map[y][x] == spawning_point)
	{
		map[y][x] = 'f';
		flood_map(map, spawning_point, x, y + 1);
		flood_map(map, spawning_point, x, y - 1);
		flood_map(map, spawning_point, x + 1, y);
		flood_map(map, spawning_point, x - 1, y);
		flood_map(map, spawning_point, x + 1, y + 1);
		flood_map(map, spawning_point, x + 1, y - 1);
		flood_map(map, spawning_point, x - 1, y + 1);
		flood_map(map, spawning_point, x - 1, y - 1);
	}
	else
		parse_error(25, 0, 0);
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

char	check_spawning_point(t_data *data)
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
		parse_error(30, 0, 0);
	return (data->map.spawning_point);
}
