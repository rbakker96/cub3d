/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 11:17:13 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/14 14:40:59 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

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

char	*table_3(int error_code)
{
	if (error_code == 25)
		return ("Error\nWall isn't completly connected\n");
	if (error_code == 26)
		return ("Error\nCorner isn't completly connected \n");
	if (error_code == 27)
		return ("Error\nTexture value is missing\n");
	if (error_code == 28)
		return ("Error\nColor value is missing\n");
	if (error_code == 29)
		return ("Error\nResolution value is missing\n");
	if (error_code == 30)
		return ("Error\nSpawning point missing\n");
	if (error_code == 31)
		return ("Error\n\n");
	if (error_code == 32)
		return ("Error\n\n");
	if (error_code == 33)
		return ("Error\n\n");
	if (error_code == 34)
		return ("Error\n\n");
	if (error_code == 35)
		return ("Error\n\n");
	if (error_code == 36)
		return ("Error\n\n");
	return (0);
}

char	*table_4(int error_code)
{
	if (error_code == 37)
		return ("Error\n\n");
	if (error_code == 38)
		return ("Error\n\n");
	if (error_code == 39)
		return ("Error\n\n");
	if (error_code == 40)
		return ("Error\n\n");
	if (error_code == 41)
		return ("Error\n\n");
	if (error_code == 42)
		return ("Error\n\n");
	if (error_code == 43)
		return ("Error\n\n");
	if (error_code == 44)
		return ("Error\n\n");
	if (error_code == 45)
		return ("Error\n\n");
	if (error_code == 46)
		return ("Error\n\n");
	if (error_code == 47)
		return ("Error\n\n");
	if (error_code == 48)
		return ("Error\n\n");
	return (0);
}

void	parse_error(int code, char **array_1, char **array_2)
{
	char	*error_message;

	if (code <= 24)
		error_message = (code <= 12) ? table_1(code) : table_2(code);
	else
		error_message = (code <= 36) ? table_3(code) : table_4(code);
	ft_putstr_fd(error_message, 2);
	free_array(array_1);
	if (array_2)
		free_array(array_2);
	exit(0);
}
