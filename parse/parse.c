/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 10:56:57 by rbakker        #+#    #+#                */
/*   Updated: 2020/02/28 17:34:38 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define MAP data->map

void		validate_map(t_data *data, int x, int y)
{
	int map_size;

	map_size = line_count(data->map);
	check_top_line(data, 0, y);
	y++;
	x++;
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

	ofset = (whitespace_check(line)) ? line_ofset(line) : 0;
	len_map_addition = line_length(line);
	new_map = malloc(sizeof(char) * len_map_addition - ofset + 1);
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
	len_map_addition = line_length(line);
	ofset = (whitespace_check(line)) ? line_ofset(line) : 0;
	updated_map = malloc(sizeof(char) * len_current_map + (len_map_addition -
							ofset) + 2);
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

void		parse_lines(t_data *data, char *file_name)
{
	int		fd;
	int		res;
	char	*line;

	res = 1;
	fd = open(file_name, O_RDONLY);
	while (res > 0)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			free_machine(line, 0);
		else if (general_input_line(line))
			parse_general_input(line, data);
		else if (map_line(line))
			(data->map_input) ? update_map(line, data, 0) :
								create_map(line, data);
		else if (!empty_line(line))
			free_machine(line, 0);
		if (res == 0)
		{
			free(line);
			validate_map(data, 0, 0);
			return ;
		}
	}
}

void		parse_file(int argv, char **argc, t_data *data)
{
	validation_reset(data);
	if (argv != 2 && argv != 3)
		parse_error(1, 0, 0);
//	if (argv == 3)
//	{
//		if (ft_strncmp()(argc[2]) == -1)
//			parse_error(2, data, 0, 0);
		/* with --save have to save the image */
//	}
	if (check_file_name(argc[1]) == error)
		parse_error(2, 0, 0);
	parse_lines(data, argc[1]);
}
