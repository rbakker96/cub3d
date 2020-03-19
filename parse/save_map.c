/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 13:20:20 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/14 14:42:25 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

int		line_ofset(char *line)
{
	int ofset;

	ofset = 0;
	while (line[ofset] == ' ' && line[ofset] != '1' && line[ofset] != '\0')
		ofset++;
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
		if (line[x] != ' ' || (line[x] == ' ' && (line[x + 1] == ' ' ||
			line[x - 1] == ' ')))
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
		if (line[x] != ' ' || (line[x] == ' ' && (line[x + 1] == ' ' ||
			line[x - 1] == ' ')))
		{
			new_string[y] = line[x];
			y++;
		}
		x++;
	}
	new_string[y] = '\0';
	return (new_string);
}
