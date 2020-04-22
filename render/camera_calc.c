/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera_calc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:43:26 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/21 13:32:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		camera_x(t_data *data, int x)
{
	data->raycast.camera_x = ((2 * x) / (double)data->res.x) - 1;
}
