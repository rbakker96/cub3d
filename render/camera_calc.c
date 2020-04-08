/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_calc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:43:26 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/08 10:45:23 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		camera_x(t_data *data, int x)
{
	data->raycast.camera_x = ((2 * x) / (double)data->res.x) - 1;
}
