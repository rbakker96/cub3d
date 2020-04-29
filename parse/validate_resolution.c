/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_resolution.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/09 10:40:49 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/29 11:42:57 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_number(const char *str)
{
	int			i;
	int			pos_neg;
	long int	result;

	i = 0;
	pos_neg = 1;
	result = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-' && str[i + 1] != '+')
	{
		pos_neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	check_resolution(t_data *data, char *nb_one, char *nb_two)
{
	int current_x;
	int current_y;

	if ((nb_one[0] == '-' && data->res.x > 0) || (nb_one[0] != '-' &&
															data->res.x < 0))
		data->res.x = data->res.x * -1;
	if ((nb_two[0] == '-' && data->res.y > 0) || (nb_two[0] != '-' &&
															data->res.y < 0))
		data->res.y = data->res.y * -1;
	if (data->res.x <= 0 || data->res.y <= 0)
		parse_error(36, data, 0, 0);
	mlx_get_screen_size(data->mlx, &current_x, &current_y);
	if (data->res.x > current_x && data->bmp_needed != 1)
		data->res.x = current_x;
	if (data->res.y > current_y && data->bmp_needed != 1)
		data->res.y = current_y;
}
