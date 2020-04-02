/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_position.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 11:28:33 by roybakker      #+#    #+#                */
/*   Updated: 2020/04/01 10:49:30 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		sprite_position_and_distance(t_data *data)
{
	int			x;
	int			y;
	int 		i;
	t_2d_double position;

	i = 0;
	y = 0;
	while (data->map.map[y] != 0)
	{
		x = 0;
		while (data->map.map[y][x] != '\0')
		{
			if (data->map.map[y][x] == '2')
			{
				position.x = x + 0.5;
				position.y = y + 0.5;
				data->texture_data.sprite_texture.sprite_position[i].position = position;
				sprite_distance(data, i);
				i++;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	sprite_distance(t_data *data, int i)
{
	data->texture_data.sprite_texture.sprite_position[i].distance = ((POS_X - data->texture_data.sprite_texture.sprite_position[i].position.x) * (POS_X - data->texture_data.sprite_texture.sprite_position[i].position.x) +
																	(POS_Y - data->texture_data.sprite_texture.sprite_position[i].position.y) * (POS_Y - data->texture_data.sprite_texture.sprite_position[i].position.y));
}
