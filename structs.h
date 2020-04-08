/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:01:38 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/08 21:01:04 by roybakker     ########   odam.nl         */
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
	off_screen = 6,
	checked = 9
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

typedef struct			s_sprite_pos
{
	t_2d_double			pos;
	double				dis;
}						t_sprite_pos;

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
	int					bpp;
	int					line_len;
	int					endian;
	int					usage;
}						t_mlx_image;

typedef struct			s_texture
{
	char				*path;
	t_mlx_image			mlx;
	t_2d_int			tex_res;
	uint32_t			color;
	double				wall_x;
	int					tex_x;
	int					tex_y;
	double				tex_pos;
	double				step;
	int					validation;
}						t_texture;

typedef struct			s_sprite_calc
{
	double				sprite_x;
	double				sprite_y;
	double				transform_x;
	double				transform_y;
	int					spritescreen;
	int					height;
	int					width;
	int					draw_start_x;
	int					draw_end_x;
	int					draw_start_y;
	int					draw_end_y;
	int					tex_x;
	int					tex_y;
	int					stripe;
	double				matrix;
}						t_sprite_calc;

typedef struct			s_sprite
{
	t_mlx_image			mlx;
	t_2d_int			res;
	t_sprite_pos		*pos;
	int					amount;
	char				*path;
	double				*dis;
	uint32_t			color;
	int					validation;
}						t_sprite;

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

typedef struct			s_resolution_data
{
	int					x;
	int					y;
	int					validation;
}						t_resolution_data;

typedef struct			s_color_data
{
	t_color				floor;
	t_color				ceilling;
}						t_color_data;

typedef struct			s_map_data
{
	char				spawning_point;
	int					map_size;
	char				**map;
	char				*map_input;
}						t_map_data;

/*
**--------------------------CALCULATION STRUCTS---------------------------------
*/

typedef struct			s_raycasting_calc
{
	t_movement			move;
	t_2d_double			dir;
	t_2d_double			old_dir;
	t_2d_double			plane;
	t_2d_double			old_plane;
	t_2d_double			pos;
	t_2d_double			side_dis;
	t_2d_double			delta_dis;
	t_2d_double			ray_dir;
	t_2d_int			step;
	t_2d_int			map;
	double				wall_dis;
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
	void				*mlx;
	void				*mlx_win;
	t_mlx_image			image_one;
	t_mlx_image			image_two;
	t_resolution_data	res;
	t_texture			north;
	t_texture			south;
	t_texture			west;
	t_texture			east;
	t_sprite			sprite;
	t_sprite_calc		sprites;
	t_color_data		color;
	t_map_data			map;
	t_raycasting_calc	raycast;
}						t_data;

#endif
