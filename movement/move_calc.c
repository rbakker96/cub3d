/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:49:36 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/16 16:33:10 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void	move_forward(t_data *data)
{
	if (MAP[(int)POS_Y][(int)(POS_X + DIR_X * 0.06)] != '1')
		POS_X += DIR_X * 0.06;
	if (MAP[(int)(POS_Y + DIR_Y * 0.06)][(int)POS_X] != '1')
		POS_Y += DIR_Y * 0.06;
}

void	move_backward(t_data *data)
{
	if (MAP[(int)POS_Y][(int)(POS_X - DIR_X * 0.06)] != '1')
		POS_X -= DIR_X * 0.06;
	if (MAP[(int)(POS_Y - DIR_Y * 0.06)][(int)POS_X] != '1')
		POS_Y -= DIR_Y * 0.06;
}

/*
** To calculate the turn vectors sin(270) and cos(270) are used.
** sin(270) always equals -1
** cos(270) always equals 0
*/

void	move_left(t_data *data)
{
	t_2d_double turn_vec;

	turn_vec.x = DIR_X * 0 - DIR_Y * -1;
	turn_vec.y = DIR_X * -1 + DIR_Y * 0;
	if (MAP[(int)POS_Y][(int)(POS_X + turn_vec.x * 0.06)] != '1')
		POS_X += turn_vec.x * 0.06;
	if (MAP[(int)(POS_Y + turn_vec.y * 0.06)][(int)POS_X] != '1')
		POS_Y += turn_vec.y * 0.06;
}

/*
** To calculate the turn vectors sin(90) and cos(90) are used.
** sin(90) always equals 1
** cos(90) always equals 0
*/

void	move_right(t_data *data)
{
	t_2d_double turn_vec;

	turn_vec.x =  DIR_X * 0 - DIR_Y * 1;
	turn_vec.y = DIR_X * 1 + DIR_Y * 0;
	if (MAP[(int)POS_Y][(int)(POS_X + turn_vec.x * 0.06)] != '1')
		POS_X += turn_vec.x * 0.06;
	if (MAP[(int)(POS_Y + turn_vec.y * 0.06)][(int)POS_X] != '1')
		POS_Y += turn_vec.y * 0.06;
}
