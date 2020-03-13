/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:51:50 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/10 15:03:06 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_put_pixel(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	dst = mlx_data->addr + (y * mlx_data->line_length + x *
							(mlx_data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		create_argb(int t, int r, int g, int b)
{
	return (b << 24 | g << 16 | r << 8 | t);
}
