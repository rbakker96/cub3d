/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:17:13 by rbakker           #+#    #+#             */
/*   Updated: 2020/02/27 11:42:33 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		arguments_count(char **input_data)
{
	int i;

	i = 0;
	while (input_data[i] != 0)
		i++;
	return (i);
}

t_color			color_value(char *input_str, char **input_array)
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

char	*table_1(int error_code)
{
	if (error_code == 1)
		return ("Error\nInvalid amount of arguments\n");
	if (error_code == 2)
		return ("Error\nInvalid file name\n");
	if (error_code == 3)
		return ("Error\nUnable to read input file\n");
	if (error_code == 4)
		return ("Error\nWrong amount of arguments for resolution\n");
	if (error_code == 5)
		return ("Error\nMultiple input values for resolution\n");
	if (error_code == 6)
		return ("Error\nWrong amount of arguments for floor color\n");
	if (error_code == 7)
		return ("Error\nMultiple input values for floor color\n");
	if (error_code == 8)
		return ("Error\nWrong amount of arguments ceilling color\n");
	if (error_code == 9)
		return ("Error\nMultiple input values for ceilling color\n");
	if (error_code == 10)
		return ("Error\nWrong amount of arguments for color value\n");
	if (error_code == 11)
		return ("Error\nRed color value out of range\n");
	if (error_code == 12)
		return ("Error\nGreen color value out of range\n");
	return (0);
}

char	*table_2(int error_code)
{
	if (error_code == 13)
		return ("Error\nBlue color value out of range\n");
	if (error_code == 14)
		return ("Error\nWrong amount of arguments North texture\n");
	if (error_code == 15)
		return ("Error\nMultiple input values for North texture\n");
	if (error_code == 16)
		return ("Error\nWrong amount of arguments South texture\n");
	if (error_code == 17)
		return ("Error\nMultiple input values for South texture\n");
	if (error_code == 18)
		return ("Error\nWrong amount of arguments East texture\n");
	if (error_code == 19)
		return ("Error\nMultiple input values for East texture\n");
	if (error_code == 20)
		return ("Error\nWrong amount of arguments West texture\n");
	if (error_code == 21)
		return ("Error\nMultiple input values for West texture\n");
	if (error_code == 22)
		return ("Error\nWrong amount of arguments Sprite texture\n");
	if (error_code == 23)
		return ("Error\nMultiple input values for Sprite texture\n");
	if (error_code == 24)
		return ("Error\nCheck input file, wrong value encounterd\n");
	return (0);
}

void	parse_error(int code, char **array_1, char **array_2)
{
	char	*error_message;

	error_message = (code <= 12) ? table_1(code) : table_2(code);
	ft_putstr_fd(error_message, 2);
	free_array(array_1);
	if (array_2)
		free_array(array_2);
	exit(0);
}
