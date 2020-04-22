/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 10:56:57 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/21 13:53:04 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		parse_file(int argv, char **argc, t_data *data)
{
	int		fd;

	reset_input_struct(data);
	if (argv != 2 && argv != 3)
		parse_error(1, data, 0, 0);
	if (argv == 3)
	{
		if (ft_strncmp((argc[2]), "--save", 10))
			parse_error(41, data, 0, 0);
		else
			data->bmp_needed = 1;
	}
	if (check_file_name(argc[1]) == error)
		parse_error(2, data, 0, 0);
	fd = open(argc[1], O_RDONLY);
	if (fd == -1)
		parse_error(38, data, 0, 0);
	general_input(data, fd);
	map_input(data, fd);
}
