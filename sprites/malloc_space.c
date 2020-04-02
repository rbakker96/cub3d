/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   malloc_space.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 12:07:08 by roybakker      #+#    #+#                */
/*   Updated: 2020/04/01 13:39:18 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		count_sprites(t_data *data)
{
	int i;

	i = 0;
	while (data->map.map_input[i] != '\0')
	{
		if (data->map.map_input[i] == '2')
			SPRITE_AMOUNT++;
		i++;
	}
}

void		malloc_distance_array(t_data *data)
{
	data->texture_data.sprite_texture.distance = malloc(sizeof(double) * WIDTH);
	if (!data->texture_data.sprite_texture.distance)
		parse_error(35, 0, 0);
}

void		malloc_sprites_array(t_data *data)
{
	data->texture_data.sprite_texture.sprite_position = malloc(sizeof(t_sprite_position) * SPRITE_AMOUNT + 1);
	if (!data->texture_data.sprite_texture.sprite_position)
		parse_error(35, 0, 0);
}
