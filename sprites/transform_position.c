/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform_position.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 12:05:28 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/21 13:32:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		transform_sprite_position(t_data *data, int i)
{
	data->sprites.sprite_x = data->sprite.pos[i].pos.x - data->raycast.pos.x;
	data->sprites.sprite_y = data->sprite.pos[i].pos.y - data->raycast.pos.y;
	data->sprites.matrix = 1.0 / (data->raycast.plane.x * data->raycast.dir.y -
								data->raycast.dir.x * data->raycast.plane.y);
	data->sprites.transform_x = data->sprites.matrix * (data->raycast.dir.y *
								data->sprites.sprite_x - data->raycast.dir.x *
								data->sprites.sprite_y);
	data->sprites.transform_y = data->sprites.matrix * (-data->raycast.plane.y *
								data->sprites.sprite_x + data->raycast.plane.x *
								data->sprites.sprite_y);
	data->sprites.spritescreen = ((data->res.x / 2) *
								(1 + data->sprites.transform_x /
								data->sprites.transform_y));
}
