/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_input.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:22:51 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/22 11:36:13 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char		*join_map_lines(char *map, char *line, t_data *data, int i)
{
	char	*complete_map;
	int		x;

	x = ft_strlen(map);
	i = ft_strlen(line);
	complete_map = malloc(sizeof(char) * (i + x + 2));
	if (!complete_map)
		parse_error(35, data, &line, 0);
	x = 0;
	i = 0;
	while (map[i] != '\0')
	{
		complete_map[i] = map[i];
		i++;
	}
	complete_map[i] = '\n';
	i++;
	while (line[x] != '\0')
	{
		complete_map[i + x] = line[x];
		x++;
	}
	complete_map[i + x] = '\0';
	return (complete_map);
}

void		update_map(char *line, t_data *data)
{
	char	*updated_map;

	updated_map = join_map_lines(data->map.map_input, line, data, 0);
	free(data->map.map_input);
	data->map.map_input = updated_map;
}

void		map_input(t_data *data, int fd)
{
	int		res;
	char	*line;

	res = 1;
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			parse_error(24, data, 0, 0);
		if (empty_line(line) || !map_line(line))
			break ;
		update_map(line, data);
		free(line);
	}
	free(line);
	data->map.map = ft_split(data->map.map_input, '\n');
	if (!data->map.map)
		parse_error(35, data, 0, 0);
	floodfill_algorithm(data);
}
