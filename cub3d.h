/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 10:44:33 by rbakker        #+#    #+#                */
/*   Updated: 2020/02/28 17:34:33 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stddef.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "list/list.h"
# include "gnl/get_next_line.h"

# include <stdio.h>  /*remove*/

/*
**-------------------------------DEFENITIONS------------------------------------
*/

typedef enum		e_defenitions
{
	error = -1,
	correct = 1,
	present = 2,
	left = 3,
	right = 4
}					t_defenitions;

/*
**---------------------------------GENERAL--------------------------------------
*/

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				validation;
}					t_color;

typedef struct		s_3d_value
{
	double			x;
	double			y;
	double			z;
}					t_3d_value;

typedef struct		s_ray
{
	t_3d_value		origin;
	t_3d_value		direction;
}					t_ray;

/*
**----------------------------------SCENE---------------------------------------
*/

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

typedef struct		s_data
{
	t_resolution	resolution;
	t_color			floor_color;
	t_color			ceilling_color;
	t_texture		north_texture;
	t_texture		south_texture;
	t_texture		west_texture;
	t_texture		east_texture;
	t_texture		sprite_texture;
	char			**map;
	char			*map_input;
}					t_data;

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

/*
**----------------------------------UTILS---------------------------------------
*/

int				arguments_count(char **input_data);
t_color			color_value(char *input_str, char **input_array);
void			parse_error(int code, char **array_1, char **array_2);

int				check_file_name(char *file_name);
int				line_length(char *line);
int				empty_line(char *line);
int				general_input_line(char *line);
int				map_line(char *line);

int				line_count(char **input_data);
int				whitespace_check(char *line);
int				line_ofset(char *line);
char			*ofset_not_present(char *line, char *new_string, int x, int y);
char			*ofset_present(char *line, char *new_string, int ofset, int x);

void			coner_type_one(t_data *data, int i, int x, int y);
void			coner_type_two(t_data *data, int i, int x, int y);
void			check_middel_lines(t_data *data, int x, int y);
void			check_top_line(t_data *data, int x, int y);
void			check_bottom_line(t_data *data, int x, int y);

void			check_start_position_and_spawning(t_data *data);
void			free_array(char **array);
void			free_machine(char *string, char **array);
void			validation_reset(t_data *data);

/*
**----------------------------------PARSE---------------------------------------
*/

void			parse_file(int argv, char **argc, t_data *data);
void			parse_lines(t_data *data, char *file_name);
void			update_map(char *line, t_data *data, int x);
void			create_map(char *line, t_data *data);
void			validate_map(t_data *data, int x, int y);

void			parse_general_input(char *line, t_data *data);
void			parse_resolution(t_data *data, char **input_data);
void			parse_floor(t_data *data, char **input_data);
void			parse_ceilling(t_data *data, char **input_data);

void			parse_north(t_data *data, char **input_data);
void			parse_south(t_data *data, char **input_data);
void			parse_east(t_data *data, char **input_data);
void			parse_west(t_data *data, char **input_data);
void			parse_sprite(t_data *data, char **input_data);

#endif
