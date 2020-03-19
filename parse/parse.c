/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 10:56:57 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/14 14:42:21 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

void		parse_file(int argv, char **argc, t_data *data)
{
	int		fd;

	reset_input_struct(data);
	if (argv != 2 && argv != 3)
		parse_error(1, 0, 0);
//	if (argv == 3)
//	{
//		if (ft_strncmp()(argc[2]) == -1)
//			parse_error(2, data, 0, 0);
		/* with --save have to save the image */
//	}
	if (check_file_name(argc[1]) == error)
		parse_error(2, 0, 0);
	fd = open(argc[1], O_RDONLY);
	general_input(data, fd);
	map_input(data, fd);
}
