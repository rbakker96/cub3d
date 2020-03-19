/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defenitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:02:51 by rbakker        #+#    #+#                */
/*   Updated: 2020/03/19 10:13:20 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFENITIONS_H
# define DEFENITIONS_H
# include "cub3d.h"

/*
**------------------------------X11 EVENTS--------------------------------------
*/

# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROY 17

# define PRESS_MASK 1L<<0
# define RELEASE_MASK 1L<<1

/*
**------------------------------KEY CODES--------------------------------------
*/

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define LEFT_KEY 123
# define RIGHT_KEY 124

/*
**----------------------------------DATA----------------------------------------
*/

# define WIDTH data->resolution.x
# define HEIGHT data->resolution.y

# define MAP data->map

/*
**------------------------------RAY CASTING-------------------------------------
*/

# define CAM_X data->raycasting.camera_x

# define MAP_X data->raycasting.map.x
# define MAP_Y data->raycasting.map.y

# define POS_X data->raycasting.pos.x
# define POS_Y data->raycasting.pos.y

# define DELTA_DIS_X data->raycasting.delta_distance.x
# define DELTA_DIS_Y data->raycasting.delta_distance.y

# define DIR_X data->raycasting.direction.x
# define DIR_Y data->raycasting.direction.y

# define RAY_DIR_X data->raycasting.ray_direction.x
# define RAY_DIR_Y data->raycasting.ray_direction.y

# define SIDE_DIS_X data->raycasting.side_distance.x
# define SIDE_DIS_Y data->raycasting.side_distance.y

# define PLANE_X data->raycasting.plane.x
# define PLANE_Y data->raycasting.plane.y

# define STEP_X data->raycasting.step.x
# define STEP_Y data->raycasting.step.y

# define WALL_DIS data->raycasting.perp_wall_distance

# define SIDE data->raycasting.side

# define LINE_HEIGHT data->raycasting.lineheight
# define DRAW_START data->raycasting.draw_start
# define DRAW_END data->raycasting.draw_end

/*
**--------------------------------MOVEMENT--------------------------------------
*/

# define OLD_DIR_X data->raycasting.old_direction.x
# define OLD_DIR_Y data->raycasting.old_direction.y

# define OLD_PLANE_X data->raycasting.old_plane.x
# define OLD_PLANE_Y data->raycasting.old_plane.y

# define FORWARD data->raycasting.move.forward
# define BACKWARD data->raycasting.move.backward
# define LOOK_LEFT data->raycasting.move.turn_left
# define LOOK_RIGHT data->raycasting.move.turn_right
# define MOVE_LEFT data->raycasting.move.move_left
# define MOVE_RIGHT data->raycasting.move.move_right

/*
**--------------------------------TEXTURE---------------------------------------
*/

# define WALL_X data->texture.wallX

# define TEX_X data->texture.texX
# define TEX_Y data->texture.texY

# define TEX_WIDTH data->texture.tex_resolution.x
# define TEX_HEIGHT data->texture.tex_resolution.y

# define STEP data->texture.step

# define TEX_POS data->texture.texPos

#endif
