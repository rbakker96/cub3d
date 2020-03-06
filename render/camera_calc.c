/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:43:26 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/06 14:43:43 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		initialize_camera_x(t_data *data, t_raycasting *raycasting, int i)
{
	CAM_X = ((2 * i) / (double)WIDTH) - 1;
}
