/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/23 14:16:53 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/29 18:02:45 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		place_texture_color(t_data *data, int x, int y)
{
	if (data->raycast.side == 1 && data->raycast.ray_dir.y > 0)
		south_texture(data, x, y);
	else if (data->raycast.side == 1 && data->raycast.ray_dir.y < 0)
		north_texture(data, x, y);
	else if (data->raycast.side == 0 && data->raycast.ray_dir.x > 0)
		east_texture(data, x, y);
	else
		west_texture(data, x, y);
}

void		north_texture(t_data *data, int x, int y)
{
	int pixel;

	data->north.tex_y = (int)data->north.tex_pos & (data->north.tex_res.x - 1);
	data->north.tex_pos += data->north.step;
	pixel = ((data->north.tex_y * data->north.mlx.line_len) + (data->north.tex_x
												* (data->north.mlx.bpp / 8)));
	data->north.color = *(unsigned int *)(data->north.mlx.addr + pixel);
	if (data->raycast.side == 1)
		data->north.color = (data->north.color >> 1) & 8355711;
	pixel_to_image(data, x, y, data->north.color);
}

void		south_texture(t_data *data, int x, int y)
{
	int pixel;

	data->south.tex_y = (int)data->south.tex_pos & (data->south.tex_res.x - 1);
	data->south.tex_pos += data->south.step;
	pixel = ((data->south.tex_y * data->south.mlx.line_len) + (data->south.tex_x
												* (data->south.mlx.bpp / 8)));
	data->south.color = *(unsigned int *)(data->south.mlx.addr + pixel);
	if (data->raycast.side == 1)
		data->south.color = (data->south.color >> 1) & 8355711;
	pixel_to_image(data, x, y, data->south.color);
}

void		east_texture(t_data *data, int x, int y)
{
	int pixel;

	data->east.tex_y = (int)data->east.tex_pos & (data->east.tex_res.x - 1);
	data->east.tex_pos += data->east.step;
	pixel = ((data->east.tex_y * data->east.mlx.line_len) + (data->east.tex_x *
													(data->east.mlx.bpp / 8)));
	data->east.color = *(unsigned int *)(data->east.mlx.addr + pixel);
	if (data->raycast.side == 1)
		data->east.color = (data->east.color >> 1) & 8355711;
	pixel_to_image(data, x, y, data->east.color);
}

void		west_texture(t_data *data, int x, int y)
{
	int pixel;

	data->west.tex_y = (int)data->west.tex_pos & (data->west.tex_res.x - 1);
	data->west.tex_pos += data->west.step;
	pixel = ((data->west.tex_y * data->west.mlx.line_len) + (data->west.tex_x *
													(data->west.mlx.bpp / 8)));
	data->west.color = *(unsigned int *)(data->west.mlx.addr + pixel);
	if (data->raycast.side == 1)
		data->west.color = (data->west.color >> 1) & 8355711;
	pixel_to_image(data, x, y, data->west.color);
}
