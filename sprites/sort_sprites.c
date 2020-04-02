/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 15:33:02 by roybakker      #+#    #+#                */
/*   Updated: 2020/04/01 10:51:49 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		sort_sprites(t_data *data)
{
	t_sprite_position	temp;
	int					i;

	i = 0;
	while (i < data->texture_data.sprite_texture.amount_of_sprites)
	{
		if (data->texture_data.sprite_texture.sprite_position[i].distance < data->texture_data.sprite_texture.sprite_position[i + 1].distance)
		{
			temp = data->texture_data.sprite_texture.sprite_position[i];
			data->texture_data.sprite_texture.sprite_position[i] = data->texture_data.sprite_texture.sprite_position[i + 1];
			data->texture_data.sprite_texture.sprite_position[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
