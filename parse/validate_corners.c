/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_corners.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 14:58:34 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/20 10:25:48 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

/*
** Corner type one (y + 1 & x + 1)is specified as
**       ___
**		|
**      |
*/

/*
** Corner type two (y - 1 & x + 1) is specified as
**		|
**		|
**       ---
*/

/*
** Corner type three (y - 1 & x - 1) is specified as
**		   |
**		   |
**		---
*/

/*
** Corner type four (y + 1 & x - 1) is specified as
**		___
**		   |
**	       |
*/

void	coner_type_one(t_data *data, int i, int x, int y)
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
		parse_error(26, 0, 0);
}

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
		parse_error(26, 0, 0);
}

int		coner_type_three(t_data *data, int i, int x, int y)
{
	if (i == top)
		while (MAP[y][x] == '1' && MAP[y - 1][x] == '1')
		{
			y--;
			if (y == 0)
				break ;
		}
	if (i == bottom)
		while (MAP[y][x] == '1' && MAP[y - 1][x] == '1' && MAP[y][x + 1] == ' ')
		{
			y--;
			if (y == 0)
				break ;
		}
	if (MAP[y][x] == '1' && MAP[y][x + 1] == '1')
		return (y);
	else
		parse_error(26, 0, 0);
	return (y);
}

int		coner_type_four(t_data *data, int i, int x, int y)
{
	if (i == top)
		while (MAP[y][x] == '1' && MAP[y][x + 1] == ' ')
			y++;
	else if (i == bottom)
		while (MAP[y][x] == '1' && y < (line_count(data->map.map) - 1))
			y++;
	if (MAP[y][x] == '1' && MAP[y][x + 1] == '1')
		return (y);
	else
		parse_error(26, 0, 0);
	return (y);
}
