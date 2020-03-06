/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:47:23 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/02 16:56:53 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define MAP data->map

/*
** Coner type one (y + 1 & x + 1)is specified as
**       ___
**		|
**      |
*/

/*
** Coner type two (y - 1 & x + 1) is specified as
**		|
**		|
**       ---
*/

void	coner_type_two(t_data *data, int i, int x, int y)
{
	if (i == left)
		while (MAP[y][x] == '1' && MAP[y + 1][x] == ' ')
			x++;
	else if (i == right)
		while (MAP[y][x] == '1' && MAP[y][x + 1] != '\0')
			x++;
	if (MAP[y][x] == '1' || MAP[y + 1][x] == '1')
		return ;
	else
		parse_error(24, 0, 0);
}

void	coner_tye_one(t_data *data, int i, int x, int y)
{
	if (i == left)
		while (MAP[y][x] == '1' && MAP[y - 1][x] == ' ')
			x++;
	else if (i == right)
		while (MAP[y][x] == '1' && MAP[y][x + 1] != '\0')
			x++;
	if (MAP[y][x] == '1' && MAP[y - 1][x] == '1')
		return ;
	else
		parse_error(24, 0, 0);
}

void	check_middel_lines(t_data *data, int x, int y)
{
	while (MAP[y][x] == ' ')
		x++;
	if (MAP[y][x] == '1' && MAP[y + 1][x] == '1' && MAP[y][x + 1] == '1')
		coner_tye_one(data, left, x, y);
	else if (MAP[y][x] == '1' && MAP[y - 1][x] == '1' && MAP[y][x + 1] == '1')
		coner_type_two(data, left, x, y);
	else if (MAP[y][x] != '1' || MAP[y + 1][x] != '1' || MAP[y - 1][x] != '1')
		parse_error(24, 0, 0);
	while (MAP[y][x + 1] != '\0' && MAP[y - 1][x + 1] != '\0' &&
			MAP[y + 1][x + 1] != '\0')
		x++;
	if (MAP[y][x] == '1' && MAP[y - 1][x] == '1' && MAP[y][x + 1] == '1')
		return (coner_type_two(data, right, x, y));
	else if (MAP[y][x] == '1' && MAP[y + 1][x] == '1' && MAP[y][x + 1] == '1')
		return (coner_tye_one(data, right, x, y));
	else if (MAP[y][x] != '1' || MAP[y + 1][x] != '1' || MAP[y - 1][x] != '1')
		parse_error(24, 0, 0);
	return ;
}

void	check_top_line(t_data *data, int x, int y)
{
	while (MAP[y][x] == ' ')
		x++;
	if (MAP[y][x] != '1' || MAP[y + 1][x] != '1' || MAP[y][x + 1] != '1')
		parse_error(24, 0, 0);
	while (MAP[y][x] == '1' && MAP[y][x + 1] != '\0')
		x++;
	if (MAP[y][x] == '1' && MAP[y][x + 1] == '\0' && MAP[y + 1][x] == '1')
		return ;
	else
		parse_error(24, 0, 0);
}

void	check_bottom_line(t_data *data, int x, int y)
{
	while (MAP[y][x] == ' ')
		x++;
	if (MAP[y][x] != '1' || MAP[y - 1][x] != '1' || MAP[y][x + 1] != '1')
		parse_error(24, 0, 0);
	while (MAP[y][x] == '1' && MAP[y][x + 1] != '\0')
		x++;
	if (MAP[y][x] == '1' && MAP[y][x + 1] == '\0' && MAP[y - 1][x] == '1')
		return ;
	else
		parse_error(24, 0, 0);
}
