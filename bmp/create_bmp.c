/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_bmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 12:22:02 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/14 21:19:07 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

int			file_header(t_data *data, int fd)
{
	char file_header[14];

	ft_bzero(file_header, 14);
	file_header[0] = 'B';
	file_header[1] = 'M';
	*(int *)(file_header + 2) = 54 + 3 * (data->res.x * data->res.y);
	*(short *)(file_header + 10) = 54;
	return (write(fd, &file_header, 14));
}

int			image_header(t_data *data, int fd)
{
	char image_header[40];

	ft_bzero(image_header, 40);
	*(unsigned int *)(image_header) = 40;
	*(unsigned int *)(image_header + 4) = data->res.x;
	*(unsigned int *)(image_header + 8) = data->res.y;
	*(short int *)(image_header + 12) = 1;
	*(short int *)(image_header + 14) = 24;
	*(unsigned int *)(image_header + 20) = 3 * (data->res.x * data->res.y);
	*(unsigned int *)(image_header + 24) = 24;
	*(unsigned int *)(image_header + 28) = 24;
	return (write(fd, &image_header, 40));
}

int			pixel_array(t_data *data, int x, int y, int fd)
{
	char			*pos;
	unsigned int	pixel;

	y = data->res.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->res.x)
		{
			pos = data->image_one.addr + (y *
					data->image_one.line_len + x * (data->image_one.bpp / 8));
			pixel = *(unsigned int *)pos;
			if (write(fd, &pixel, 3) < 0)
				return (-1);
			x++;
		}
		y--;
	}
	return (0);
}

void		create_bmp(t_data *data)
{
	int		fd;

	fd = open("./screenshot/image.bmp", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
	if (fd == -1)
		parse_error(38, 0, 0);
	if (file_header(data, fd) < 0 || image_header(data, fd) < 0 ||
		pixel_array(data, 0, 0, fd) < 0)
		parse_error(39, 0, 0);
	data->bmp_needed = 0;
	close(fd);
}
