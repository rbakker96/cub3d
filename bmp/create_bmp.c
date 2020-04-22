/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_bmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 12:22:02 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/21 13:52:22 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			get_padding(t_data *data)
{
	int i;
	int modulo;

	i = 0;
	while (i < 3)
	{
		modulo = (data->res.x * 3 + i) % 4;
		if (modulo == 0)
			return (i);
		i++;
	}
	return (i);
}

int			file_header(t_data *data, int fd)
{
	char	file_header[14];
	int		width;
	int		padding;

	padding = get_padding(data);
	width = data->res.x + padding;
	ft_bzero(file_header, 14);
	file_header[0] = 'B';
	file_header[1] = 'M';
	*(int *)(file_header + 2) = 54 + 3 * width * data->res.y;
	*(short *)(file_header + 10) = 54;
	return (write(fd, &file_header, 14));
}

int			image_header(t_data *data, int fd)
{
	char	image_header[40];
	int		width;
	int		padding;

	padding = get_padding(data);
	width = data->res.x + padding;
	ft_bzero(image_header, 40);
	*(unsigned int *)(image_header) = 40;
	*(unsigned int *)(image_header + 4) = data->res.x;
	*(unsigned int *)(image_header + 8) = data->res.y;
	*(short int *)(image_header + 12) = 1;
	*(short int *)(image_header + 14) = 24;
	*(unsigned int *)(image_header + 20) = 3 * width * data->res.y;
	*(unsigned int *)(image_header + 24) = 24;
	*(unsigned int *)(image_header + 28) = 24;
	return (write(fd, &image_header, 40));
}

int			pixel_array(t_data *data, int x, int y, int fd)
{
	char			*pos;
	unsigned int	pixel;
	int				padding;

	padding = get_padding(data);
	y = data->res.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->res.x)
		{
			pos = data->image_one.addr + (y * data->image_one.line_len + x *
													(data->image_one.bpp / 8));
			pixel = *(unsigned int *)pos;
			if (write(fd, &pixel, 3) < 0)
				return (-1);
			x++;
		}
		if (write(fd, "\0\0\0", padding) < 0)
			return (-1);
		y--;
	}
	return (0);
}

void		create_bmp(t_data *data)
{
	int fd;
	int fail;

	fd = open("./screenshot/image.bmp", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
	if (fd == -1)
		parse_error(38, data, 0, 0);
	if (file_header(data, fd) < 0 || image_header(data, fd) < 0 ||
		pixel_array(data, 0, 0, fd) < 0)
	{
		close(fd);
		parse_error(39, data, 0, 0);
	}
	fail = close(fd);
	(fail < 0) ? parse_error(40, data, 0, 0) : fail;
	close_screen(data);
}
