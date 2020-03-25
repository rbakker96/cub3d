/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   register_movement.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 13:37:38 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/20 10:21:50 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

int		key_press(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		FORWARD = 1;
	if (keycode == S_KEY)
		BACKWARD = 1;
	if (keycode == A_KEY)
		MOVE_LEFT = 1;
	if (keycode == LEFT_KEY)
		LOOK_LEFT = 1;
	if (keycode == D_KEY)
		MOVE_RIGHT = 1;
	if (keycode == RIGHT_KEY)
		LOOK_RIGHT = 1;
	return (0);
}

int		key_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		FORWARD = 0;
	if (keycode == S_KEY)
		BACKWARD = 0;
	if (keycode == A_KEY)
		MOVE_LEFT = 0;
	if (keycode == LEFT_KEY)
		LOOK_LEFT = 0;
	if (keycode == D_KEY)
		MOVE_RIGHT = 0;
	if (keycode == RIGHT_KEY)
		LOOK_RIGHT = 0;
	return (0);
}

int		process_movement(t_data *data)
{
	if (FORWARD == 1)
		move_forward(data);
	else if (BACKWARD == 1)
		move_backward(data);
	else if (MOVE_LEFT == 1)
		move_left(data);
	else if (MOVE_RIGHT == 1)
		move_right(data);
	else if (LOOK_LEFT == 1)
		turn_left(data);
	else if (LOOK_RIGHT == 1)
		turn_right(data);
	if (FORWARD == 1 || BACKWARD == 1 || LOOK_LEFT == 1 || LOOK_RIGHT == 1 ||
		MOVE_RIGHT == 1 || MOVE_LEFT == 1)
		render_screen(data, 0);
	return (0);
}
