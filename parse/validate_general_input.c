/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_general_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:33:17 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/10 14:41:17 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_file_name(char *file_name)
{
	int i;

	i = 0;
	while (file_name[i] != '\0')
	{
		if (file_name[i] == '.' && file_name[i + 1] == 'c' && file_name[i + 2]
			== 'u' && file_name[i + 3] == 'b')
			return (correct);
		i++;
	}
	return (error);
}

int		arguments_count(char **input_data)
{
	int i;

	i = 0;
	while (input_data[i] != 0)
		i++;
	return (i);
}

t_color	color_value(char *input_str, char **input_array)
{
	t_color color;
	char	**colors;

	colors = ft_split(input_str, ',');
	if (arguments_count(colors) != 3)
		parse_error(10, input_array, colors);
	color.r = ft_atoi(colors[0]);
	if (color.r < 0 || color.r > 255)
		parse_error(11, input_array, colors);
	color.g = ft_atoi(colors[1]);
	if (color.g < 0 || color.g > 255)
		parse_error(12, input_array, colors);
	color.b = ft_atoi(colors[2]);
	if (color.b < 0 || color.b > 255)
		parse_error(13, input_array, colors);
	free_array(colors);
	return (color);
}

void	validate_general_input(t_data *data)
{
	if (data->east_texture.validation == 0 ||
		data->north_texture.validation == 0 ||
		data->south_texture.validation == 0 ||
		data->sprite_texture.validation == 0 ||
		data->west_texture.validation == 0)
		parse_error(27, 0, 0);
	if (data->floor_color.validation == 0 ||
		data->ceilling_color.validation == 0)
		parse_error(28, 0, 0);
	if (data->resolution.validation == 0)
		parse_error(29, 0, 0);
	else
		return ;
}
