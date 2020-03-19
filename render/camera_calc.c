/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_calc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:43:26 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/14 14:42:57 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		camera_x(t_data *data, int i)
{
	CAM_X = ((2 * i) / (double)WIDTH) - 1;
}
