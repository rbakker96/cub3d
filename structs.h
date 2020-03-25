/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:01:38 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/25 13:36:53 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "cub3d.h"

/*
**-------------------------------DEFENITIONS------------------------------------
*/

typedef enum			e_defenitions
{
	error = -1,
	correct = 1,
	present = 2,
	left = 3,
	right = 4,
	top = 3,
	bottom = 4,
	on_screen = 5,
	off_screen = 6
}						t_defenitions;

/*
**---------------------------------GENERAL--------------------------------------
*/

typedef struct			s_2d_double
{
	double				x;
	double				y;
}						t_2d_double;

typedef struct			s_2d_int
{
	int					x;
	int					y;
}						t_2d_int;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
	uint32_t			color;
	int					validation;
}						t_color;

typedef struct			s_mlx_image
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					usage;
}						t_mlx_image;

typedef struct			s_texture
{
	char				*path;
	t_mlx_image			image;
	t_2d_int			tex_resolution;
	uint32_t			color;
	double				wallX;
	int					texX;
	int					texY;
	double				texPos;
	double				step;
	int					validation;
}						t_texture;

typedef struct			s_movement
{
	int					forward;
	int					backward;
	int					turn_left;
	int					turn_right;
	int					move_left;
	int					move_right;
}						t_movement;

/*
**--------------------------INPUT DATA STRUCTS----------------------------------
*/

typedef struct			s_mlx_data
{
	void				*mlx;
	void				*mlx_win;
	t_mlx_image			image_one;
	t_mlx_image			image_two;
}						t_mlx_data;

typedef struct			s_resolution_data
{
	int					x;
	int					y;
	int					validation;
}						t_resolution_data;

typedef struct			s_texture_data
{
	t_texture			north_texture;
	t_texture			south_texture;
	t_texture			west_texture;
	t_texture			east_texture;
	t_texture			sprite_texture;
}						t_texture_data;

typedef struct 			s_color_data
{
	t_color				floor_color;
	t_color				ceilling_color;
}						t_color_data;

typedef struct			s_map_data
{
	char				spawning_point;
	char				**map;
	char				*map_input;
}						t_map_data;

/*
**--------------------------CALCULATION STRUCTS---------------------------------
*/

typedef struct			s_raycasting_calc
{
	t_movement			move;
	t_2d_double			direction;
	t_2d_double			old_direction;
	t_2d_double			plane;
	t_2d_double			old_plane;
	t_2d_double			pos;
	t_2d_double			side_distance;
	t_2d_double			delta_distance;
	t_2d_double			ray_direction;
	t_2d_int			step;
	t_2d_int			map;
	double				perp_wall_distance;
	double				camera_x;
	int					side;
	int					lineheight;
	int					draw_start;
	int					draw_end;
}						t_raycasting_calc;

/*
**------------------------------MAIN STRUCT-------------------------------------
*/

typedef struct			s_data
{
	t_mlx_data			mlx_data;
	t_resolution_data	resolution;
	t_texture_data		texture_data;
	t_color_data		color;
	t_map_data			map;
	t_raycasting_calc	raycasting;
}						t_data;

#endif
