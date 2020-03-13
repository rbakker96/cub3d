/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:49:36 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/13 16:24:36 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	move_left(t_data *data)
{
	if (data)
		return ;
}

void	move_right(t_data *data)
{
	if (data)
		return ;
}
