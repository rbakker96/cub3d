/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_sprites.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 15:33:02 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/08 11:18:07 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		sort_sprites(t_data *data)
{
	t_sprite_pos		temp;
	int					i;

	i = 0;
	while (i < data->sprite.amount)
	{
		if (data->sprite.pos[i].dis < data->sprite.pos[i + 1].dis)
		{
			temp = data->sprite.pos[i];
			data->sprite.pos[i] = data->sprite.pos[i + 1];
			data->sprite.pos[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
