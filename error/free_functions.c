/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 16:29:33 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/21 13:32:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	free_struct(t_data *data)
{
	free_map(data);
	free_texture(data);
	if (data->sprite.dis)
		free(data->sprite.dis);
	if (data->sprite.pos)
		free(data->sprite.pos);
}

void	free_map(t_data *data)
{
	if (data->map.map_input)
		free(data->map.map_input);
	if (data->map.map)
		free_array(data->map.map);
}

void	free_texture(t_data *data)
{
	if (data->north.path)
		free(data->north.path);
	if (data->east.path)
		free(data->east.path);
	if (data->south.path)
		free(data->south.path);
	if (data->west.path)
		free(data->west.path);
}
