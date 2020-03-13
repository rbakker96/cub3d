/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:22:51 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/10 15:01:10 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		validate_map(t_data *data, int x, int y)
{
	int map_size;

	map_size = line_count(data->map);
	check_top_line(data, x, y);
	y++;
	while (y < (map_size - 1))
	{
		check_middel_lines(data, 0, y);
		y++;
	}
	check_bottom_line(data, 0, y);
	check_start_position_and_spawning(data);
}

void		create_map(char *line, t_data *data)
{
	char	*new_map;
	int		len_map_addition;
	int		ofset;

	ofset = line_ofset(line);
	len_map_addition = ft_strlen(line);
	new_map = malloc(sizeof(char) * len_map_addition + 1);
	if (!new_map)
		free_machine(line, 0);
	new_map = (ofset) ? ofset_present(line, new_map, ofset, 0) :
						ofset_not_present(line, new_map, 0, 0);
	data->map_input = new_map;
}

void		update_map(char *line, t_data *data, int x)
{
	char	*updated_map;
	int		len_current_map;
	int		len_map_addition;
	int		ofset;

	len_current_map = ft_strlen(data->map_input);
	len_map_addition = ft_strlen(line);
	ofset = line_ofset(line);
	updated_map = malloc(sizeof(char) * len_current_map + len_map_addition + 2);
	if (!updated_map)
		free_machine(line, 0);
	while (data->map_input[x] != '\0')
	{
		updated_map[x] = data->map_input[x];
		x++;
	}
	updated_map[x] = '\n';
	x++;
	ofset = (ofset) ? ofset + x : 0;
	updated_map = (ofset) ? ofset_present(line, updated_map, ofset, x) :
							ofset_not_present(line, updated_map, 0, x);
	free(data->map_input);
	data->map_input = updated_map;
	data->map = ft_split(updated_map, '\n');
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
			free_machine(line, 0);
		if (res == 0)
			free(line);
		if (empty_line(line) || !map_line(line))
			break ;
		update_map(line, data, 0);
	}
	validate_map(data, 0, 0);
}
