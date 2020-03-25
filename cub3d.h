/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 10:44:33 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/25 20:13:58 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stddef.h>
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
**----------------------------------ERROR---------------------------------------
*/

/*
** error_function.c
*/
char		*table_1(int error_code);
char		*table_2(int error_code);
char		*table_3(int error_code);
char		*table_4(int error_code);
void		parse_error(int code, char **array_1, char **array_2);

/*
** free_functions.c
*/
void		free_array(char **array);
void		free_machine(char *string, char **array);

/*
** reset_functions.c
*/
void		reset_validation(t_data *data);
void		reset_texture(t_data *data);
void		reset_color(t_data *data);
void		reset_input_struct(t_data *data);

/*
**------------------------------MLX FUNCTIONS-----------------------------------
*/

/*
** init_mlx.c
*/
void		init_mlx(t_data *data);
void		open_window(t_data *data);
void		create_new_image(t_data *data);
void		get_data_addres(t_data *data);

/*
** create_texture.c
*/
void		create_texture_images(t_data *data);
void		east_texture_image(t_data *data);
void		north_texture_image(t_data *data);
void		south_texture_image(t_data *data);
void		west_texture_image(t_data *data);

/*
** create_image.c
*/
void		pixel_to_image(t_data *data, int x, int y, int color);

/*
**----------------------------------PARSE---------------------------------------
*/

/*
** parse.c
*/
void		parse_file(int argv, char **argc, t_data *data);

/*
** parse_general_input.c
*/
void		parse_general_input(char *line, t_data *data);
void		parse_resolution(t_data *data, char **input_data);
void		parse_floor(t_data *data, char **input_data);
void		parse_ceilling(t_data *data, char **input_data);
void		general_input(t_data *data, int fd);

/*
** parse_texture_input.c
*/

void		parse_north(t_data *data, char **input_data);
void		parse_south(t_data *data, char **input_data);
void		parse_east(t_data *data, char **input_data);
void		parse_west(t_data *data, char **input_data);
void		parse_sprite(t_data *data, char **input_data);

/*
** parse_map_input.c
*/
void		validate_map(t_data *data, int x, int y);
void		create_map(char *line, t_data *data);
void		update_map(char *line, t_data *data, int x);
void		map_input(t_data *data, int fd);

/*
** save_map.c
*/
int			line_ofset(char *line);
char		*ofset_not_present(char *line, char *new_string, int x, int y);
char		*ofset_present(char *line, char *new_string, int ofset, int y);

/*
** validate_corners.c
*/
void		coner_type_one(t_data *data, int i, int x, int y);
void		coner_type_two(t_data *data, int i, int x, int y);
int			coner_type_three(t_data *data, int i, int x, int y);
int			coner_type_four(t_data *data, int i, int x, int y);

/*
** validate_map.c
*/
void		check_top_line(t_data *data, int x, int y);
void		check_middel_lines(t_data *data, int x, int y);
void		check_bottom_line(t_data *data, int x, int y);
void		check_start_position_and_spawning(t_data *data);

/*
** validate_read_lines.c
*/
int			line_count(char **input_data);
int			empty_line(char *line);
int			general_input_line(char *line);
int			map_line(char *line);

/*
** validate_general_input.c
*/
int			check_file_name(char *file_name);
int			arguments_count(char **input_data);
t_color		color_value(char *input_str, char **input_array);
void		validate_general_input(t_data *data);

/*
**----------------------------------RENDER--------------------------------------
*/

/*
** render.c
*/
void		pre_calculations(t_data *data);
void		calculate_variables(t_data *data, int i);
void		render_screen(t_data *data, int i);

/*
** set_colors.c
*/
void		set_floor_and_ceilling_dcolor(t_data *data);
uint32_t	create_rgb(int r, int g, int b);

/*
** camera_calc.c
*/
void		camera_x(t_data *data, int i);

/*
** direction_calc.c
*/
void		view_direction(t_data *data);
void		ray_direction(t_data *data);
void		step_size(t_data *data);

/*
** distance_calc.c
*/
void		delta_distance(t_data *data);
void		side_distance(t_data *data);

/*
** plane_calc.c
*/
void		initialize_plane(t_data *data);

/*
** position_calc.c
*/
void		start_position(t_data *data);
void		current_position(t_data *data);

/*
** wall_calc.c
*/
void		identify_wall(t_data *data);
void		prep_wall_distance(t_data *data);

/*
** draw.c
*/
void		draw_screen(t_data *data, int x);
void		draw_ceilling(t_data *data, int x);
void		draw_wall(t_data *data, int x);
void		draw_floor(t_data *data, int x);

/*
** reset_variables.c
*/
void		reset_variables(t_data *data);

/*
**---------------------------------MOVEMENT-------------------------------------
*/

/*
** move_calc.c
*/
void		move_forward(t_data *data);
void		move_backward(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);

/*
** turn_calc.c
*/
void		turn_right(t_data *data);
void		turn_left(t_data *data);

/*
** register_movement.c
*/
int			key_press(int keycode, t_data *data);
int			key_release(int keycode, t_data *data);
int			process_movement(t_data *data);

/*
**---------------------------------TEXTURE--------------------------------------
*/

/*
** wall_x.c
*/
double		calculate_wall_x(t_data *data);

/*
** tex_x.c
*/
int			calculate_tex_x(t_data *data, double wall_x, int tex_width);

/*
** texture_calc.c
*/
void		calculate_texture_variables(t_data *data);
void		calculate_north_variables(t_data *data);
void		calculate_south_variables(t_data *data);
void		calculate_west_variables(t_data *data);
void		calculate_east_variables(t_data *data);

/*
** texture_color.c
*/
void		place_texture_color(t_data *data, int x, int y);
void		north_texture(t_data *data, int x, int y);
void		south_texture(t_data *data, int x, int y);
void		east_texture(t_data *data, int x, int y);
void		west_texture(t_data *data, int x, int y);

#endif
