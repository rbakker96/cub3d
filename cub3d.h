/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 10:44:33 by rbakker           #+#    #+#             */
/*   Updated: 2020/03/06 17:55:52 by rbakker          ###   ########.fr       */
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
# include "structs.h"
# include "defenitions.h"

# include <stdio.h>  /*remove*/

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
void			reset_input_struct(t_data *data);

/*
**-----------------------------PARSE FOLDER-------------------------------------
*/

void			parse_file(int argv, char **argc, t_data *data);
void			parse_lines(t_data *data, char *file_name);
void			update_map(char *line, t_data *data, int x);
void			create_map(char *line, t_data *data);
void			validate_map(t_data *data, int x, int y);
void			validate_general_input(t_data *data);

void			parse_general_input(char *line, t_data *data);
void			parse_resolution(t_data *data, char **input_data);
void			parse_floor(t_data *data, char **input_data);
void			parse_ceilling(t_data *data, char **input_data);

void			parse_north(t_data *data, char **input_data);
void			parse_south(t_data *data, char **input_data);
void			parse_east(t_data *data, char **input_data);
void			parse_west(t_data *data, char **input_data);
void			parse_sprite(t_data *data, char **input_data);

/*
**-----------------------------RENDER FOLDER------------------------------------
*/

void			initialize_camera_x(t_data *data, t_raycasting *raycasting,
									int i);

void			view_direction(t_data *data, t_raycasting *raycasting);
void			ray_direction(t_raycasting *raycasting);
void			step_size(t_raycasting *raycasting);

void			delta_distance(t_raycasting *raycasting);
void			side_distance(t_raycasting *raycasting);

void			initialize_plane(t_raycasting *raycasting);

void			start_and_current_position(t_data *data,
											t_raycasting *raycasting);

void			identify_wall(t_data *data, t_raycasting *raycasting);
void			prep_wall_distance(t_raycasting *raycasting);
void			draw_wall(t_data *data, t_raycasting *raycasting,
							t_mlx_data *mlx_data, int i);

void			calculate_variables(t_data *data, t_raycasting *raycasting,
									int i);
void			render(t_data *data, t_raycasting *raycasting,
							t_mlx_data *mlx_data, int i);

void			reset_variables(t_raycasting *raycasting);

void			my_put_pixel(t_mlx_data *mlx_data, int x, int y, int color);
int				create_argb(int t, int r, int g, int b);

#endif
