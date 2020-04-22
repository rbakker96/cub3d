/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_read_lines.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:34:18 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/21 13:32:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		line_count(char **input_data)
{
	int i;

	i = 0;
	while (input_data[i] != 0)
		i++;
	return (i);
}

int		empty_line(char *line)
{
	int i;

	i = 0;
	while (line[0] == '\0')
		return (1);
	return (0);
}

int		general_input_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'R' && line[i + 1] == ' ')
			return (1);
		if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
			return (1);
		if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
			return (1);
		if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
			return (1);
		if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
			return (1);
		if (line[i] == 'S' && line[i + 1] == ' ')
			return (1);
		if (line[i] == 'F' && line[i + 1] == ' ')
			return (1);
		if (line[i] == 'C' && line[i + 1] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		map_line(char *line)
{
	int i;

	i = 0;
	if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != '2')
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != 'N' && line[i] != 'S' && line[i] != 'E' &&
			line[i] != 'W' && line[i] != '1' && line[i] != '0' &&
			line[i] != ' ' && line[i] != '2')
			return (0);
		i++;
	}
	return (1);
}
