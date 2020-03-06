/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_reset_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 13:37:41 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/06 16:04:43 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_start_position_and_spawning(t_data *data)
{
	int i;
	int validation;

	i = 0;
	validation = 0;
	while (data->map_input[i] != '\0')
	{
		if (data->map_input[i] == 'S' || data->map_input[i] == 'N' ||
			data->map_input[i] == 'W' || data->map_input[i] == 'E')
			validation++;
		if (data->map_input[i] == 'S')
			data->spawning_point = 'S';
		if (data->map_input[i] == 'W')
			data->spawning_point = 'W';
		if (data->map_input[i] == 'E')
			data->spawning_point = 'E';
		if (data->map_input[i] == 'N')
			data->spawning_point = 'N';
		i++;
	}
	if (validation != 1)
		parse_error(24, 0, 0);
	return ;
}

void	free_array(char **array)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != 0)
		i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

void	free_machine(char *string, char **array)
{
	if (string)
		free(string);
	parse_error(24, array, 0);
}

void	reset_validation(t_data *data)
{
	data->ceilling_color.validation = 0;
	data->east_texture.validation = 0;
	data->floor_color.validation = 0;
	data->north_texture.validation = 0;
	data->resolution.validation = 0;
	data->south_texture.validation = 0;
	data->sprite_texture.validation = 0;
	data->west_texture.validation = 0;
}

void	reset_texture(t_data *data)
{
	data->east_texture.path = 0;
	data->north_texture.path = 0;
	data->south_texture.path = 0;
	data->west_texture.path = 0;
	data->spawning_point = 0;
}

void	reset_color(t_data *data)
{
	data->floor_color.r = 0;
	data->floor_color.g = 0;
	data->floor_color.b = 0;
	data->ceilling_color.r = 0;
	data->ceilling_color.g = 0;
	data->ceilling_color.b = 0;
	data->resolution.x = 0;
	data->resolution.y = 0;
}

void	reset_input_struct(t_data *data)
{
	reset_validation(data);
	reset_texture(data);
	reset_color(data);
}
