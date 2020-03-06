/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:20:20 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/06 17:59:31 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		line_count(char **input_data)
{
	int i;

	i = 0;
	while (input_data[i] != 0)
		i++;
	return (i);
}

int		whitespace_check(char *line)
{
	int x;

	x = 0;
	while (line[x] == ' ' && line[x] != '\0')
		x++;
	while (line[x] != '\0')
	{
		if (line[x] == ' ')
			return (1);
		x++;
	}
	return (0);
}

int		line_ofset(char *line)
{
	int ofset;

	ofset = 0;
	while (line[ofset] == ' ' && line[ofset] != '\0')
		ofset++;
	ofset = ofset / 2;
	return (ofset);
}

char	*ofset_not_present(char *line, char *new_string, int x, int y)
{
	while (line[x] == ' ' && line[x] != '\0')
	{
		new_string[y] = line[x];
		y++;
		x++;
	}
	while (line[x] != '\0')
	{
		if (line[x] != ' ')
		{
			new_string[y] = line[x];
			y++;
		}
		x++;
	}
	new_string[y] = '\0';
	return (new_string);
}

char	*ofset_present(char *line, char *new_string, int ofset, int y)
{
	int x;

	x = 0;
	while (line[x] == ' ' && line[x] != '\0')
	{
		if (y < ofset)
		{
			new_string[y] = line[x];
			y++;
		}
		x++;
	}
	while (line[x] != '\0')
	{
		if (line[x] != ' ')
		{
			new_string[y] = line[x];
			y++;
		}
		x++;
	}
	new_string[y] = '\0';
	return (new_string);
}
