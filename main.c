/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 13:15:38 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/17 19:07:35 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

int		main(int argv, char **argc)
{
	t_data			data;

	parse_file(argv, argc, &data);
	init_mlx(&data);
	pre_calculations(&data);
	mlx_hook(data.mlx_win, CLOSE, 1L << 17, &button_close_screen, &data);
	mlx_hook(data.mlx_win, KEYPRESS, 1L << 0, &key_press, &data);
	mlx_hook(data.mlx_win, KEYRELEASE, 1L << 1, &key_release, &data);
	mlx_loop_hook(data.mlx, &process_movement, &data);
	mlx_loop(data.mlx);
	return (0);
}
