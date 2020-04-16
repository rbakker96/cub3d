/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:49:36 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/15 10:23:24 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	move_forward(t_data *data)
{
	int tmp;

	tmp = data->raycast.pos.x + data->raycast.dir.x * 0.06;
	if (data->map.map[(int)data->raycast.pos.y][tmp] != '1')
		data->raycast.pos.x += data->raycast.dir.x * 0.06;
	tmp = data->raycast.pos.y + data->raycast.dir.y * 0.06;
	if (data->map.map[tmp][(int)data->raycast.pos.x] != '1')
		data->raycast.pos.y += data->raycast.dir.y * 0.06;
}

void	move_backward(t_data *data)
{
	int tmp;

	tmp = data->raycast.pos.x - data->raycast.dir.x * 0.06;
	if (data->map.map[(int)data->raycast.pos.y][tmp] != '1')
		data->raycast.pos.x -= data->raycast.dir.x * 0.06;
	tmp = data->raycast.pos.y - data->raycast.dir.y * 0.06;
	if (data->map.map[tmp][(int)data->raycast.pos.x] != '1')
		data->raycast.pos.y -= data->raycast.dir.y * 0.06;
}

/*
** To calculate the turn vectors sin(270) and cos(270) are used.
** sin(270) always equals -1
** cos(270) always equals 0
*/

void	move_left(t_data *data)
{
	t_2d_double	turn_vec;
	int			tmp;

	turn_vec.x = data->raycast.dir.x * 0 - data->raycast.dir.y * -1;
	turn_vec.y = data->raycast.dir.x * -1 + data->raycast.dir.y * 0;
	tmp = data->raycast.pos.x + turn_vec.x * 0.06;
	if (data->map.map[(int)data->raycast.pos.y][tmp] != '1')
		data->raycast.pos.x += turn_vec.x * 0.06;
	tmp = data->raycast.pos.y + turn_vec.y * 0.06;
	if (data->map.map[tmp][(int)data->raycast.pos.x] != '1')
		data->raycast.pos.y += turn_vec.y * 0.06;
}

/*
** To calculate the turn vectors sin(90) and cos(90) are used.
** sin(90) always equals 1
** cos(90) always equals 0
*/

void	move_right(t_data *data)
{
	t_2d_double	turn_vec;
	int			tmp;

	turn_vec.x = data->raycast.dir.x * 0 - data->raycast.dir.y * 1;
	turn_vec.y = data->raycast.dir.x * 1 + data->raycast.dir.y * 0;
	tmp = data->raycast.pos.x + turn_vec.x * 0.06;
	if (data->map.map[(int)data->raycast.pos.y][tmp] != '1')
		data->raycast.pos.x += turn_vec.x * 0.06;
	tmp = data->raycast.pos.y + turn_vec.y * 0.06;
	if (data->map.map[tmp][(int)data->raycast.pos.x] != '1')
		data->raycast.pos.y += turn_vec.y * 0.06;
}
