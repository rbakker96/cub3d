/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 10:44:33 by rbakker       #+#    #+#                 */
/*   Updated: 2020/04/17 14:01:54 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stddef.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
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
void		parse_error(int code, t_data *data, char **array_1, char **array_2);

/*
** free_functions.c
*/
void		free_array(char **array);
void		free_struct(t_data *data);
void		free_map(t_data *data);
void		free_texture(t_data *data);

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
** create_sprite.c
*/
void		create_sprite_image(t_data *data);

/*
** close_screen.c
*/
int			button_close_screen(t_data *data);
int			key_close_screen(t_data *data);

/*
**--------------------------------BMP IMAGE-------------------------------------
*/

/*
** create_bmp.c
*/
int			get_padding(t_data *data);
int			file_header(t_data *data, int fd);
int			image_header(t_data *data, int fd);
int			pixel_array(t_data *data, int x, int y,int fd);
void		create_bmp(t_data *data);

/*
** get_rgb_color.c
*/
int			get_red(int rgb);
int			get_green(int rgb);
int			get_blue(int rgb);

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
char		*join_map_lines(char *map, char *line, t_data *data, int i);
void		update_map(char *line, t_data *data);
void		map_input(t_data *data, int fd);

/*
** flood_fill_map_check.c
*/
void		floodfill_algorithm(t_data *data);
void		flood_map(char **map, t_data *data, int x, int y);
t_2d_int	position(t_data *data, int x, int y);
void		check_spawning_point(t_data *data);
void		check_top_and_bottom_line(char **map, t_data *data, int x, int y);

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
t_color		color_value(char *input_str, t_data *data, char **input_array);
void		validate_general_input(t_data *data);

/*
** validate_resolution.c
*/
void		check_resolution(t_data *data);

/*
**----------------------------------RENDER--------------------------------------
*/

/*
** render.c
*/
void		pre_calculations(t_data *data);
void		calculate_variables(t_data *data, int x);
void		render_screen(t_data *data, int x);

/*
** set_colors.c
*/
void		set_floor_and_ceilling_color(t_data *data);
uint32_t	create_rgb(int r, int g, int b);

/*
** camera_calc.c
*/
void		camera_x(t_data *data, int x);

/*
** direction_calc.c
*/
void		set_view_direction(t_data *data);
void		ray_direction(t_data *data);
void		step_size(t_data *data);

/*
** distance_calc.c
*/
void		delta_distance(t_data *data);
void		side_distance(t_data *data);
void		set_prep_distance_array(t_data *data);

/*
** plane_calc.c
*/
void		initialize_plane(t_data *data);

/*
** position_calc.c
*/
void		set_start_position(t_data *data);
void		current_position(t_data *data);

/*
** wall_calc.c
*/
void		identify_wall(t_data *data);
void		prep_wall_distance(t_data *data, int x);

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

/*
**---------------------------------SPRITES--------------------------------------
*/

/*
** cast_sprite.c
*/
void		cast_sprites(t_data *data, int i);
void		calcualte_sprite_variables(t_data *data);

/*
** sprite_position.c
*/
void		sprite_position_and_distance(t_data *data);
void		sprite_distance(t_data *data, int i);
void		set_sprites_array(t_data *data);

/*
** sort_sprites.c
*/
void		sort_sprites(t_data *data);

/*
** transform_position.c
*/
void		transform_sprite_position(t_data *data, int i);

/*
** sprite_dimensions.c
*/
void		sprite_dimensions(t_data *data);
void		sprite_height(t_data *data);
void		sprite_width(t_data *data);

/*
** sprite_color.c
*/
void		sprite_color(t_data *data, int y);

#endif
