/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   register_movement.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 13:37:38 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/08 11:55:28 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

int		key_press(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->raycast.move.forward = 1;
	if (keycode == S_KEY)
		data->raycast.move.backward = 1;
	if (keycode == A_KEY)
		data->raycast.move.move_left = 1;
	if (keycode == LEFT_KEY)
		data->raycast.move.turn_left = 1;
	if (keycode == D_KEY)
		data->raycast.move.move_right = 1;
	if (keycode == RIGHT_KEY)
		data->raycast.move.turn_right = 1;
	return (0);
}

int		key_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->raycast.move.forward = 0;
	if (keycode == S_KEY)
		data->raycast.move.backward = 0;
	if (keycode == A_KEY)
		data->raycast.move.move_left = 0;
	if (keycode == LEFT_KEY)
		data->raycast.move.turn_left = 0;
	if (keycode == D_KEY)
		data->raycast.move.move_right = 0;
	if (keycode == RIGHT_KEY)
		data->raycast.move.turn_right = 0;
	return (0);
}

int		process_movement(t_data *data)
{
	if (data->raycast.move.forward == 1)
		move_forward(data);
	else if (data->raycast.move.backward == 1)
		move_backward(data);
	else if (data->raycast.move.move_left == 1)
		move_left(data);
	else if (data->raycast.move.move_right == 1)
		move_right(data);
	else if (data->raycast.move.turn_left == 1)
		turn_left(data);
	else if (data->raycast.move.turn_right == 1)
		turn_right(data);
	if (data->raycast.move.forward == 1 || data->raycast.move.backward == 1 ||
		data->raycast.move.turn_left == 1 || data->raycast.move.turn_right == 1
										|| data->raycast.move.move_right == 1
										|| data->raycast.move.move_left == 1)
		render_screen(data, 0);
	return (0);
}
