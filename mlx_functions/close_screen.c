/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_screen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/09 11:23:49 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/16 12:09:37 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

int		button_close_screen(t_data *data)
{
	mlx_destroy_image(data->mlx, data->image_one.img);
	mlx_destroy_image(data->mlx, data->image_two.img);
	free_struct(data);
	exit(1);
}

int		key_close_screen(t_data *data)
{
	mlx_destroy_image(data->mlx, data->image_one.img);
	mlx_destroy_image(data->mlx, data->image_two.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	free_struct(data);
	exit(1);
}
