/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_position.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 11:28:33 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/08 21:34:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		sprite_position_and_distance(t_data *data)
{
	int			x;
	int			y;
	int			i;
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
				data->sprite.pos[i].pos = position;
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
	data->sprite.pos[i].dis = ((data->raycast.pos.x - data->sprite.pos[i].pos.x)
							* (data->raycast.pos.x - data->sprite.pos[i].pos.x)
							+ (data->raycast.pos.y - data->sprite.pos[i].pos.y)
							* (data->raycast.pos.y - data->sprite.pos[i].pos.y))
																			;
}

void		set_sprites_array(t_data *data)
{
	int i;

	i = 0;
	while (data->map.map_input[i] != '\0')
	{
		if (data->map.map_input[i] == '2')
			data->sprite.amount++;
		i++;
	}
	data->sprite.pos = malloc(sizeof(t_sprite_pos) * data->sprite.amount + 1);
	if (!data->sprite.pos)
		parse_error(35, 0, 0);
}
