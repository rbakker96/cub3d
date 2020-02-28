/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:44:11 by rbakker           #+#    #+#             */
/*   Updated: 2020/02/27 17:34:55 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_file_name(char *file_name)
{
	int i;

	i = 0;
	while (file_name[i] != '\0')
	{
		if (file_name[i] == '.' && file_name[i + 1] == 'c' && file_name[i + 2]
			== 'u' && file_name[i + 3] == 'b')
			return (correct);
		i++;
	}
	return (error);
}

int		line_length(char *line)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (line[x] == ' ' && line[x] != '\0')
		x++;
	while (line[x] != '\0')
	{
		if (line[x] == ' ')
			y++;
		x++;
	}
	return (x - y);
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
	while (line[i] != '\0')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
		{
			while (line[i] != '\0')
			{
				if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||
				line[i] == 'W' || line[i] == '1' || line[i] == '0')
					return (1);
				i++;
			}
		}
		i++;
	}
	return (0);
}
