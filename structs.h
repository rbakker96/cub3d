/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:01:38 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/13 14:03:34 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "cub3d.h"

/*
**-------------------------------DEFENITIONS------------------------------------
*/

typedef enum		e_defenitions
{
	error = -1,
	correct = 1,
	present = 2,
	left = 3,
	right = 4,
	top = 3,
	bottom = 4
}					t_defenitions;

/*
**---------------------------------GENERAL--------------------------------------
*/

typedef struct		s_2d_double
{
	double			x;
	double			y;
}					t_2d_double;

typedef struct		s_2d_int
{
	int				x;
	int				y;
}					t_2d_int;

typedef struct		s_movement
{
	int				forward;
	int				backward;
	int				turn_left;
	int				turn_right;
	int				move_left;
	int				move_right;
}					t_movement;

/*
**----------------------------------SCENE---------------------------------------
*/

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				validation;
}					t_color;

typedef struct		s_resolution
{
	int				x;
	int				y;
	int				validation;
}					t_resolution;

typedef struct		s_texture
{
	char			*path;
	int				validation;
}					t_texture;

/*
**----------------------------------DATA----------------------------------------
*/

typedef struct		s_mlx_data
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx_data;

typedef struct		s_raycasting
{
	t_movement		move;
	t_2d_double		direction;
	t_2d_double		old_direction;
	t_2d_double		plane;
	t_2d_double		old_plane;
	t_2d_double		pos;
	t_2d_double		side_distance;
	t_2d_double		delta_distance;
	t_2d_double		ray_direction;
	t_2d_int		step;
	t_2d_int		map;
	double			perp_wall_distance;
	double			camera_x;
	double			move_speed;
	double			rot_speed;
	int				side;
}					t_raycasting;

typedef struct		s_data
{
	t_mlx_data		mlx_data;
	t_raycasting	raycasting;
	t_resolution	resolution;
	t_color			floor_color;
	t_color			ceilling_color;
	t_texture		north_texture;
	t_texture		south_texture;
	t_texture		west_texture;
	t_texture		east_texture;
	t_texture		sprite_texture;
	char			spawning_point;
	char			**map;
	char			*map_input;
}					t_data;

#endif
