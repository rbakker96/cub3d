/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_general_input.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:33:17 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/22 11:09:34 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int		digit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

t_color	color_value(char *input_str, t_data *data, char **input_array)
{
	t_color color;
	char	**colors;

	colors = ft_split(input_str, ',');
	if (!colors)
		parse_error(35, data, input_array, 0);
	if (arguments_count(colors) != 3)
		parse_error(10, data, input_array, colors);
	if (!digit(colors[0]) || !digit(colors[1]) || !digit(colors[2]))
		parse_error(42, data, input_array, colors);
	color.r = ft_atoi(colors[0]);
	if (color.r < 0 || color.r > 255)
		parse_error(11, data, input_array, colors);
	color.g = ft_atoi(colors[1]);
	if (color.g < 0 || color.g > 255)
		parse_error(12, data, input_array, colors);
	color.b = ft_atoi(colors[2]);
	if (color.b < 0 || color.b > 255)
		parse_error(13, data, input_array, colors);
	free_array(colors);
	return (color);
}

void	validate_general_input(t_data *data)
{
	if (data->east.validation == 0 ||
		data->north.validation == 0 ||
		data->south.validation == 0 ||
		data->sprite.validation == 0 ||
		data->west.validation == 0)
		parse_error(27, data, 0, 0);
	if (data->color.floor.validation == 0 ||
		data->color.ceilling.validation == 0)
		parse_error(28, data, 0, 0);
	if (data->res.validation == 0)
		parse_error(29, data, 0, 0);
	else
		return ;
}
