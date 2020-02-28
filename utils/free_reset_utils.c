/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_reset_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:37:41 by rbakker           #+#    #+#             */
/*   Updated: 2020/02/28 17:35:27 by rbakker          ###   ########.fr       */
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

void	validation_reset(t_data *data)
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

