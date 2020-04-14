/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_rgb_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 10:36:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/04/14 14:14:14 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/roybakker/Documents/Codam/cub3d/cub3d.h"

int		get_red(int rgb)
{
	return (rgb & 0xFF);
}

int		get_green(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

int		get_blue(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}
